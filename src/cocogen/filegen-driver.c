#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>

#include "cocogen/ast.h"
#include "cocogen/filegen-util.h"

#include "lib/array.h"
#include "lib/errors.h"
#include "lib/memory.h"
#include "lib/print.h"
#include "lib/smap.h"

#define HASH_HEADER "// Hash: %s\n"

static Config *ast_definition = NULL;
static char *output_directory = NULL;
static smap_t *generated_files = NULL;

static bool only_list_files = false;

FILE *get_fp(char *full_path, char *mode) {
    FILE *fp = fopen(full_path, mode);
    if (!fp) {
        perror("Opening file failed");
        exit(CANNOT_OPEN_FILE);
    }
    return fp;
}

bool is_only_list_files() {
    return only_list_files;
}

Config *_get_ast_definition() {
    return ast_definition;
}

char *get_full_path_with_dir(const char *dir, char *filename, char *formatter) {
    size_t dir_len = strlen(dir);
    char *full_path = mem_alloc(dir_len + strlen(filename) + 1);
    strcpy(full_path, dir);
    strcat(full_path, filename);

    if (formatter) {
        char *old_full_path = full_path;
        full_path =
            mem_alloc(dir_len + strlen(formatter) + strlen(filename) + 1);
        sprintf(full_path, old_full_path, formatter);
        mem_free(old_full_path);
    }

    return full_path;

}

static char *get_full_path(char *filename, char *formatter) {
    return get_full_path_with_dir(output_directory, filename, formatter);
}

void print_file_gen(char *full_path) {
    if (only_list_files)
        printf("%s\n", full_path);
    else
        printf(COLOR_GREEN " GEN       " COLOR_RESET "%s\n", full_path);
}

void add_filename_to_set(char *filename) {
    char *filename_dup = strdup(filename);
    char *fn = strrchr(filename_dup, '/');
    if (fn) {
        // Skip the slash
        fn = fn + 1;
    } else {
        fn = filename;
    }

    size_t length = strlen(fn);
    if ((fn[length - 2] == '.' &&
         (fn[length - 1] == 'c' || fn[length - 1] == 'h'))) {
        fn[length - 2] = '\0';
        smap_insert(generated_files, fn, fn);
        free(filename_dup);
    }
}

static bool hash_match(NodeCommonInfo *info, char *full_path) {

    char *current_hash = mem_alloc(43 * sizeof(char));
    bool rv = false;

    FILE *fp = fopen(full_path, "r");
    if (fp != NULL) {
        // TODO: More robustness of the detection of the hash, maybe use regex.
        // Hash: %32s\n -> read 3+4+2+32+1 = 42 characters.
        if (fgets(current_hash, 42, fp) != NULL) {
            if (strncmp(current_hash + 9, info->hash, 32) == 0) {
                rv = true;
                /* printf(COLOR_GREEN " SAME      " COLOR_RESET "%s\n", */
                /*        full_path); */
            }
        }
        fclose(fp);
    }

    if (!rv) {
        print_file_gen(full_path);
    }

    add_filename_to_set(full_path);
    mem_free(current_hash);
    return rv;
}

void filegen_init(Config *config, bool list_gen_files_flag) {
    ast_definition = config;
    only_list_files = list_gen_files_flag;
}

void filegen_cleanup(void) {
    if (output_directory != NULL) {
        mem_free(output_directory);
    }

    if (generated_files != NULL) {
        smap_free(generated_files);
    }
}

bool ensure_dir_exists(char *dirname, __mode_t mode) {
    if (mkdir(dirname, mode) == 0) {
        return true;
    } else {
        if (errno == EEXIST) {
            DIR *d = opendir(dirname);

            // out_dir exists but is a file
            if (!d) {
                perror("Creation failed");
                exit(CANNOT_CREATE_DIR);
            } else {
                // Directory already exists
                closedir(d);
            }
            return true;
        } else {
            perror("Creation failed");
            exit(CANNOT_CREATE_DIR);
        }
    }
    return false;
}

void filegen_dir(char *out_dir) {
    filegen_cleanup();

    generated_files = smap_init(32);

    size_t out_dir_len = strlen(out_dir);

    if (out_dir[out_dir_len - 1] != '/') {
        output_directory = mem_alloc(out_dir_len + 2);
        sprintf(output_directory, "%s/", out_dir);
    } else {
        output_directory = strdup(out_dir);
    }

    ensure_dir_exists(output_directory, 0755);
}

void filegen_generate(char *filename, void (*func)(Config *, FILE *)) {

    char *full_path = get_full_path(filename, NULL);

    add_filename_to_set(full_path);

    print_file_gen(full_path);

    if (!only_list_files) {
        FILE *fp = get_fp(full_path, "w");
        func(ast_definition, fp);
        fclose(fp);
    }

    mem_free(full_path);
}

void filegen_all_nodes(char *fileformatter,
                       void (*func)(Config *, FILE *, Node *)) {
    char *full_path;
    FILE *fp;

    for (int i = 0; i < array_size(ast_definition->nodes); ++i) {
        Node *node = array_get(ast_definition->nodes, i);
        full_path = get_full_path(fileformatter, node->id);

        if (hash_match(node->common_info, full_path)) {
            mem_free(full_path);
            continue;
        }

        if (!only_list_files) {
            fp = get_fp(full_path, "w");
            out(HASH_HEADER, node->common_info->hash);
            func(ast_definition, fp, node);
            fclose(fp);
        }

        mem_free(full_path);
    }
}

void filegen_all_nodesets(char *fileformatter,
                          void (*func)(Config *, FILE *, Nodeset *)) {
    char *full_path;
    FILE *fp;

    for (int i = 0; i < array_size(ast_definition->nodesets); ++i) {
        Nodeset *nodeset = array_get(ast_definition->nodesets, i);
        full_path = get_full_path(fileformatter, nodeset->id);

        if (hash_match(nodeset->common_info, full_path)) {
            mem_free(full_path);
            continue;
        }

        if (!only_list_files) {
            fp = get_fp(full_path, "w");
            out(HASH_HEADER, nodeset->common_info->hash);
            func(ast_definition, fp, nodeset);
            fclose(fp);
        }

        mem_free(full_path);
    }
}

void filegen_all_traversals(char *fileformatter,
                            void (*func)(Config *, FILE *, Traversal *)) {
    char *full_path;
    FILE *fp;

    for (int i = 0; i < array_size(ast_definition->traversals); ++i) {
        Traversal *traversal = array_get(ast_definition->traversals, i);
        full_path = get_full_path(fileformatter, traversal->id);

        if (hash_match(traversal->common_info, full_path)) {
            mem_free(full_path);
            continue;
        }

        if (!only_list_files) {
            fp = get_fp(full_path, "w");
            out(HASH_HEADER, traversal->common_info->hash);
            func(ast_definition, fp, traversal);
            fclose(fp);
        }

        mem_free(full_path);
    }
}

void filegen_all_passes(char *fileformatter,
                        void (*func)(Config *, FILE *, Pass *)) {
    char *full_path;
    FILE *fp;

    for (int i = 0; i < array_size(ast_definition->passes); ++i) {
        Pass *pass = array_get(ast_definition->passes, i);
        full_path = get_full_path(fileformatter, pass->id);

        if (hash_match(pass->common_info, full_path)) {
            mem_free(full_path);
            continue;
        }

        if (!only_list_files) {
            fp = get_fp(full_path, "w");
            out(HASH_HEADER, pass->common_info->hash);
            func(ast_definition, fp, pass);
            fclose(fp);
        }

        mem_free(full_path);
    }
}

void filegen_all_phases(char *fileFormatter,
                        void (*func)(Config *, FILE *, Phase *)) {

    char *full_path;
    FILE *fp;
    for (int i = 0; i < array_size(ast_definition->phases); ++i) {
        Phase *phase = array_get(ast_definition->phases, i);
        full_path = get_full_path(fileFormatter, phase->id);

        if (hash_match(phase->common_info, full_path)) {
            phase->common_info->hash_matches = true;
            mem_free(full_path);
            continue;
        }

        if (!only_list_files) {
            fp = get_fp(full_path, "w");
            out(HASH_HEADER, phase->common_info->hash);
            func(ast_definition, fp, phase);
            fclose(fp);
        }

        mem_free(full_path);
    }
}

void filegen_phase_subtree(void (*func)(array *)) {
    func(ast_definition->phases);
}

void filegen_delete_non_generated_filed(ccn_set_t*generated_files, array *directories, ccn_set_t *blacklist) {
    DIR *dir;
    struct dirent *ent;

    for (int i = 0; i < array_size(directories); ++i) {
        char *dir_name = array_get(directories, i);
        size_t dir_len = strlen(dir_name);

        if ((dir = opendir(dir_name)) != NULL) {
            while ((ent = readdir(dir)) != NULL) {
                if (ent->d_type != DT_REG)
                    continue;

                char *name = ent->d_name;
                size_t name_len = strlen(name);
                if (blacklist != NULL && ccn_set_contains(blacklist, name))
                    continue;

                // Delete the file if it is not generated
                if (! ccn_set_contains(generated_files, name)) {
                    char *full_path = malloc(dir_len + name_len + 2);
                    sprintf(full_path, "%s%s", dir_name, name);
                    printf(COLOR_GREEN " RM        " COLOR_RESET "%s\n",
                        full_path);
                    if (remove(full_path) != 0)
                        perror("remove");

                    mem_free(full_path);
                }
            }
            closedir(dir);
        } else {
            perror("Could not open directory for file cleanup.\n");
        }
    }
}

void filegen_cleanup_old_files(void) {
    size_t output_dir_length = strlen(output_directory);
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(output_directory)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type != DT_REG)
                continue;

            char *name = ent->d_name;
            size_t length = strlen(ent->d_name);
            if (!(length >= 2 && name[length - 2] == '.' &&
                  (name[length - 1] == 'h' || name[length - 1] == 'c' ||
                   name[length - 1] == 'd' || name[length - 1] == 'o')))
                continue;

            char *name_no_ext = strdup(name);
            name_no_ext[length - 2] = '\0';

            // Delete the file if it is not generated
            if (smap_retrieve(generated_files, name_no_ext) == NULL) {
                char *full_path = malloc(output_dir_length + length + 2);
                sprintf(full_path, "%s%s", output_directory, name);
                printf(COLOR_GREEN " RM        " COLOR_RESET "%s\n",
                       full_path);
                if (remove(full_path) != 0)
                    perror("remove");

                mem_free(full_path);
            }
            mem_free(name_no_ext);
        }
        closedir(dir);
    } else {
        /* could not open directory */
        perror("Error opening directory for file cleanup");
    }
}
