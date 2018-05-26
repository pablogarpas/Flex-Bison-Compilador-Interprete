comp: lex.yy.o parser.tab.o
	gcc -o compilador lex.yy.o parser.tab.o -lm
bison: parser.y
	bison -d parser.y
flex : lexer.flex
	flex lexer.flex
clean: 
	rm -f parser.tab.c
	rm -f parser.tab.h
	rm -f parser.tab.o
	rm -f compilador
	rm -f lex.yy.c
	rm -f lex.yy.o
