.PHONY = flexbison

flexbison: ast.lexer.c ast.parser.c

ast.lexer.c: ast.l
	$(LEX) -o $@ --header-file=ast.lexer.h $<

ast.parser.c: ast.y
	$(YACC) -dv -o $@ $<
