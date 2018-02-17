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

struct NODO  *com; //Puntero al comienzo de la TS (tabla de símbolos)
struct NODO  *fin; //Puntero al final de la TS
char *cadaux;//variable auxiliar para eliminar las comillas de yytext
char i;//variable auxiliar para eliminar las comillas de yytext
int n_lineas;//contar el numero de lineas
int num_errores;// variable para contar el número de errores
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
{entero}       {yylval.ELEMENTO.valint = atoi(yytext);
		 yylval.ELEMENTO.tipo=1;
		 strcpy(yylval.ELEMENTO.trad,yytext);
	 	 return TK_ENT;
		}//devuelve un entero

{real}       {yylval.ELEMENTO.valnum = atof(yytext);
	 	yylval.ELEMENTO.tipo=1;	 
		strcpy(yylval.ELEMENTO.trad,yytext);
		return TK_NUM;
		}//devuelve un real

{booleano}     {if (strcmp(yytext,"true")==0){
		  yylval.ELEMENTO.valbool = 1;
		strcpy(yylval.ELEMENTO.trad,yytext);
	 	  yylval.ELEMENTO.tipo=3;	
		  return TK_NBOOL;
    		}	
                else
		  yylval.ELEMENTO.valbool = 0;
	 	  yylval.ELEMENTO.tipo=3;	
		strcpy(yylval.ELEMENTO.trad,yytext);
		  return TK_NBOOL;
                 }//devuelve un booleano

{blancos}  ;//no hace nada
{salto}		{n_lineas++;} // Incrementa una variable con el numero de linea

"="			return TK_ASIG;
"=="		return TK_IGU;
"<>"		return TK_DIS;
"**"		return TK_POW;
"<="		return TK_MEI;
">="		return TK_MAI;
"++"		return TK_INC;
"--"		return TK_DEC;
"&"		return TK_DIR;
"*"		return TK_VAL;
"default" return TK_DEFAULT;
"caso" return TK_CASO;
"switch" return TK_SWITCH;
"programa"	return TK_PROGRAM;
"inicio"         return TK_INICIO;
"funcion"         return TK_FUNCION;
"fin"	        return TK_FIN;
"si"		return TK_SI;
"const"		return TK_CONST;
"var"		return TK_VAR;
"haz"		return TK_HAZ;
"escribir"	return TK_ESCRIBIR;
"para" return TK_PARA;
"hasta" return TK_HASTA;
"leer"	return TK_LEER;
"mientras" return TK_MIENTRAS;
"hacer"		return TK_HACER;
"entero"	return TK_ENTERO;
"bool"		return TK_BOOL;
"real"		return TK_REAL;
"string"	return TK_STRING;
"librerias" return TK_LIB;
"and"		return TK_AND;
"or"		return TK_OR;
"not"		return TK_NOT;

{variable}       {yylval.indice = buscar_simbolo(yytext,&com,&fin);
                 //buscamos es la TS la variable y si no esta la añadimos
                 //introducimos en trad lo que el lex encuentra y aunque variable sea un puntero
                 //la expresion del yacc (el NT) almacena el valor de traduccion
									strcpy(yylval.ELEMENTO.trad,yytext);
									return TK_VARIABLE;
									}//devuelve una variable

{cadena}  {cadaux=(char *)malloc(sizeof (char [yyleng]));
           // Quitamos las comillas de las cadenas y añadimos el valor para la trduccion
           //damos valor a los campos correspondientes
           strcpy(yylval.ELEMENTO.trad,yytext);
	   for (i=1;i<yyleng-1;i++)  cadaux[i-1]=yytext[i];
	   strcpy(yylval.ELEMENTO.cad,cadaux);
	   yylval.ELEMENTO.tipo=4; 
	   yylval.ELEMENTO.escons=1;	   	
           return TK_CADENA;
		}//devuelve una constante de tipo cadena

\n|.	   return yytext[0];



%%
int yywrap(){
return 1;
}

//Función para los errores con la línea en la que se encuentran
yyerror(char *s, int salir)
{
  printf("%s. En la línea %d.\n",s,n_lineas+1);
  num_errores++;
  
  if (num_errores>5||salir) {
  exit(0);
  }
}
