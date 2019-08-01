MODULES = src/cocogen src/framework
MKDIR = mkdir -p

CC           ?= gcc
CFLAGS       ?= -Wall -std=gnu11 -pedantic -MMD \
				-Werror=implicit-function-declaration 
LDFLAGS      += -lmhash -lcoconut
LFLAGS       += -L./CoCoNut-lib/bin
INCLUDE_DIRS = -Iinclude/ -I./CoCoNut-lib/include/
SOURCE_DIR := src
BUILD_DIR := build
BIN_DIR := bin
SILENCED := # Set silenced to '@' if you do not want printing to happen.
LEX = flex
YACC = bison 
COCONUT_LIB_DIR = CoCoNut-lib
COCONUT_LIB = $(COCONUT_LIB_DIR)/bin/libcoconut.a


ifdef sanitize
	CFLAGS += -fsanitize=address -fno-omit-frame-pointer
	LDFLAGS += -fsanitize=address
endif

ifdef profiling
	CLAGS += -pg
	LDFLAGS += -pg
endif

VPATH := $(MODULES)

SRC := $(foreach module, $(MODULES), $(notdir $(wildcard $(module)/*.c)))
SRC := $(sort $(SRC)) # Create reproducible builds.
OBJ := $(SRC:.c=.o)
OBJ := $(addprefix $(BUILD_DIR)/, $(OBJ))


# START RULES
release: CFLAGS += -O2 -DNDEBUG
release: cocogen

debug: CFLAGS += -g -Og
debug: cocogen

cocogen: $(BIN_DIR)/cocogen

$(BIN_DIR)/cocogen: $(OBJ)
	$(SILENCED)$(CC) -o $@ $^ $(LFLAGS) $(LDFLAGS)

.PHONY += flexbison
flexbison:
	$(MAKE) -C src/cocogen -f module.mk YACC="$(YACC)" LEX="$(LEX)"

$(OBJ): flexbison coconut_lib | $(BUILD_DIR) $(BIN_DIR)

coconut_lib: 
	$(MAKE) -C CoCoNut-lib/ CFLAGS="$(CFLAGS)"

$(BUILD_DIR):
	$(SILENCED)$(MKDIR) $(BUILD_DIR)

$(BIN_DIR):
	$(SILENCED)$(MKDIR) $(BIN_DIR)

$(BUILD_DIR)/%.o: %.c
	$(SILENCED)$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ -c $<



.PHONY += clean
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
	make -C $(COCONUT_LIB_DIR) clean
