trans: lex.yy.o lexico.tab.o codigo.h codigo.c trans.tab.h trans.tab.c
	gcc -o transpilador lex.yy.o anal.tab.o -lm
bison: trans.y
	bison -d trans.y
lex : lexico.f
	flex lexico.f
clean: 
	rm -f trans.tab.c
	rm -f trans.tab.h
	rm -f compilador
	rm -f lex.yy.c
