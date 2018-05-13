trans: lex.yy.o trans.tab.o
	gcc -o compilador lex.yy.o trans.tab.o -lm
bison: trans.y
	bison -d trans.y
lex : lexico.f
	flex lexico.f
clean: 
	rm -f trans.tab.c
	rm -f trans.tab.h
	rm -f trans.tab.o
	rm -f compilador
	rm -f lex.yy.c
	rm -f lex.yy.o
