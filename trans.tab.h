/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_TRANS_TAB_H_INCLUDED
# define YY_YY_TRANS_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_PROGRAM = 258,
    TK_CONST = 259,
    TK_VAR = 260,
    TK_SI = 261,
    TK_INICIO = 262,
    TK_ENTERO = 263,
    TK_REAL = 264,
    TK_BOOL = 265,
    TK_MIENTRAS = 266,
    TK_IGU = 267,
    TK_HAZ = 268,
    TK_RETORNO = 269,
    TK_ESCRIBIR = 270,
    TK_STRING = 271,
    TK_ARG = 272,
    TK_LIB = 273,
    TK_SWITCH = 274,
    TK_LEER = 275,
    TK_LLAMAR = 276,
    TK_FIN = 277,
    TK_MOD = 278,
    TK_HACER = 279,
    TK_INC = 280,
    TK_DEC = 281,
    TK_FUNCION = 282,
    TK_CONT = 283,
    TK_ARRAY = 284,
    TK_MUL = 285,
    TK_DIV = 286,
    TK_DEFAULT = 287,
    TK_HASTA = 288,
    TK_ELSE = 289,
    TK_PARA = 290,
    TK_CASO = 291,
    TK_COM = 292,
    TK_CADENA = 293,
    TK_NBOOL = 294,
    TK_NUM = 295,
    TK_ENT = 296,
    TK_VARIABLE = 297,
    TK_MEI = 298,
    TK_MAI = 299,
    TK_DIS = 300,
    TK_ASIG = 301,
    TK_OR = 302,
    TK_AND = 303,
    TK_NOT = 304,
    MENOSUNARIO = 305,
    TK_POW = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 25 "trans.y" /* yacc.c:1909  */

	struct NODO *indice; //puntero a la tabla de simbolos 
	struct elemento {
		char nombre[255]; //amacenar el nombre
		int escons; //nos dice si es o no constante 1->si 0->no 
		int esarray; //nos dice si es o no puntero 1->si 0->no 
		int tipo; //tipo de variable
		int valbool; //tipo booleano
		double valnum;	//valor numerico	     
		int valint; //valor entero  
		char valstr[255]; //valor de tipo string
		char cad[255];//valor para las cadenas
		char trad[555];//almaceno la cadena de composicion de exp
		int vis; //variable para visualizar las constantes cadena correctamente	
		char res[255];//cadena para mostrar por pantalla
		int aux;//Variable para el índice del array
		} ELEMENTO;

#line 125 "trans.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TRANS_TAB_H_INCLUDED  */
