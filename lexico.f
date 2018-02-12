%{

/****************************************************************************
*****************************************************************************
Analizador léxico para el pseudocódigo que aceptará el transpilador.
****************************************************************************
****************************************************************************/
//---------------------- COMENTARIOS AL CODIGO ------------------------------
//delim-> reconoce un espacio en blanco o una tabulacion                   --
//blancos-> reconoce uno o mÃƒÂ¡s espacios en blanco                       --
//entero-> reconoce los numeros enteros                                    --
//entero-> reconoce los numeros reales                                     --  
//letra->  reconoce las letras del abecedario mayusculas y minusculas      --
//id->  reconoce identificadores compuestos por letras y/o numeros         --
//booleano->  reconoce valores booleanos, true o false                     --
//cadena-> reconoce una constante de tipo cadena                           --
//---------------------------------------------------------------------------

#include "trans.tab.h"
#include "codigo.h"
#include "codigo.c"
#include <string.h>
struct simbolo  *com; //Puntero al comienzo de la TS
struct simbolo  *fin; //Puntero al final de la TS
char *cadaux;//variable auxiliar para eliminar las comillas de yytext
char i;//variable auxiliar para eliminar las comillas de yytext
int n_lineas;//contar el numero de lineas

%}
delim [\' '\t] 
blancos {delim}+ 
entero [0-9]+ 
real	{entero}+[.]{entero}([eE][-+]?{entero})? 
letra [a-zA-Z] 
booleano (true|false) 
variable {letra}({letra}|[0-9]|_)* 
cadena   \"[^\"\n]*[\"] 
salto \n
%%
{entero}       {yylval.nterminal.valint = atoi(yytext);
		 yylval.nterminal.tipo=1;
		 strcpy(yylval.nterminal.trad,yytext);
	 	 return ENT;
		}//devuelve un entero

{real}       {yylval.nterminal.valnum = atof(yytext);
	 	yylval.nterminal.tipo=1;	 
		strcpy(yylval.nterminal.trad,yytext);
		return NUM;
		}//devuelve un real

{booleano}     {if (strcmp(yytext,"true")==0){
		  yylval.nterminal.valbool = 1;
		strcpy(yylval.nterminal.trad,yytext);
	 	  yylval.nterminal.tipo=3;	
		  return NBOOL;
    		}	
                else
		  yylval.nterminal.valbool = 0;
	 	  yylval.nterminal.tipo=3;	
		strcpy(yylval.nterminal.trad,yytext);
		  return NBOOL;
                 }//devuelve un booleano

{blancos}  ;//no hace nada
{salto}		{n_lineas++;} // Incrementa una variable con el numero de linea

":="		return ASIG;
"<>"		return DIS;
"**"		return POW;
"<="		return MEI;
">="		return MAI;
"programa"	return PROGRAM;
"inicio"         return INICIO;
"fin"	        return FIN;
"si"		return SI;
"const"		return CONST;
"var"		return VAR;
"escribir"	return ESCRIBIR;
"leer"	return LEER;
"mientras" return MIENTRAS;
"hacer"		return HACER;
"entero"	return ENTERO;
"bool"		return BOOL;
"real"		return REAL;
"string"	return STRING;
"librerias" return LIB;
"and"		return AND;
"or"		return OR;
"not"		return NOT;

{variable}       {yylval.indice = buscar_simbolo(yytext,&com,&fin);
                 //buscamos es la TS la variable y si no esta la añadimos
                 //introducimos en trad lo que el lex encuentra y aunque variable sea un puntero
                 //la expresion del yacc (el NT) almacena el valor de traduccion
		strcpy(yylval.nterminal.trad,yytext);
	        return VARIABLE;
		}//devuelve una variable

{cadena}  {cadaux=(char *)malloc(sizeof (char [yyleng]));
           // Quitamos las comillas de las cadenas y añadimos el valor para la trduccion
           //damos valor a los campos correspondientes
           strcpy(yylval.nterminal.trad,yytext);
	   for (i=1;i<yyleng-1;i++)  cadaux[i-1]=yytext[i];
	   strcpy(yylval.nterminal.cad,cadaux);
	   yylval.nterminal.tipo=4; 
	   yylval.nterminal.escons=1;	   	
           return CADENA;
		}//devuelve una constante de tipo cadena

\n|.	   return yytext[0];



%%
int yywrap(){
return 1;
}

//solo la usamos una vez, pero es para que se vea que se puede utilizar
yyerror(s)
char *s;
{
  printf("%s. En la línea %d.\n",s,n_lineas+1);
}
