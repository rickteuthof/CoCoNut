#ifndef _STR_H_
#define _STR_H_


extern char *create_ast_string(const char *source);
//extern const char *read_string(char *source);
extern void free_ast_string(char *source);
extern char *copy_ast_string(char *source);

extern char *copy_string(char *source);
// extern char *STRcpy(char *source);
// extern str *STRncpy(str *source, int maxlen);
// extern int  STRlen(str *source);
// extern str *STRsubStr( const char *string, int start, int len);
// extern str *STRnull();

#define F_PTR "%p"

#endif /* _STR_H_ */