%{
/****************************************************************************
****************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "trad.h"
#include "comp.c"

//Variables globales
NODO *com;//Principio de la lista de śimbolos para el AST
NODO *fin;//Final de la lista de śimbolos para el AST
int   auxb;  //variable auxiliar para la lectura de booleanos 
int   auxint;  //variable auxiliar para la lectura de enteros
float auxn;  //variable auxiliar para la lectura de numeros
char  auxc[255];//variable auxiliar para la lectura de strings
char  auxt[255];//variable auxiliar para las traducciones
int auxtip=1;//variable auxiliar para los tipos de varias sentencias
NODO auxnodo1;//Variables para trabajar con la lista
NODO auxnodo2;
NODO *auxvar;
NODO *auxvar2;
%}


//definimos los tipos de datos que vamos a utilizar
%union 	{
	struct NODO *indice; //puntero a la tabla de simbolos 
	struct elemento {
		char nombre[255]; //amacenar el nombre
		int escons; //nos dice si es o no constante 1->si 0->no 
		int espun; //nos dice si es o no puntero 1->si 0->no 
		int tipo; //tipo de variable
		int valbool; //tipo booleano
		double valnum;	//valor numerico	     
		int valint; //valor entero  
		char valstr[255]; //valor de tipo string
		char cad[255];//valor para las cadenas
		char trad[555];//almaceno la cadena de composicion de exp
		int vis; //variable para visualizar las constantes cadena correctamente	
		char res[255];//cadena para mostrar por pantalla
		} ELEMENTO;
}

////////////////////////////////////////////////////////////////////////////////////////////

//Definicion de los tokens, terminales y no terminales
%token    TK_PROGRAM
%token    TK_CONST
%token    TK_VAR
%token	  TK_SI
%token    TK_INICIO
%token    TK_ENTERO
%token    TK_REAL
%token    TK_BOOL
%token		TK_MIENTRAS
%token		TK_IGU
%token		TK_HAZ
%token		TK_DIR
%token		TK_VAL
%token		TK_RETORNO
%token    TK_ESCRIBIR
%token		TK_STRING
%token		TK_ARG
%token    TK_LIB
%token    TK_SWITCH
%token    TK_LEER
%token    TK_LLAMAR
%token	  TK_FIN
%token	  TK_MOD
%token	  TK_HACER
%token	  TK_INC
%token	  TK_DEC
%token	  TK_FUNCION
%token	  TK_CONT
%token		TK_DEFAULT
%token		TK_HASTA
%token		TK_ELSE
%token		TK_PARA
%token    TK_CASO
%token	<ELEMENTO>	TK_COM
%token  <ELEMENTO> TK_CADENA
%token 	<ELEMENTO> TK_NBOOL
%token 	<ELEMENTO>	TK_NUM
%token 	<ELEMENTO>	TK_ENT
%token 	<indice>	TK_VARIABLE
%type   <ELEMENTO>  	cabecera dec_constantes constante exp dec_vbles tipo variable sentencia lista_sentencias  salto_lin salto_lin_dec  asignacion visual elemento_mostrar  visual2 lectura control cont final librerias case cases default break puntero punteros_asignar funciones funcion dec_arg_fun cuerpo argumento llamar_fun llamar_arg control2 decre else control3 control4 control5 fun_dec devolver asig_fun
%start programa
////////////////////////////////////////////////////////////////////////////////////////////////

%right '=' TK_MEI TK_MAI TK_DIS '<' '>' TK_ASIG
%left '+' '-' TK_OR
%left '*' '/' TK_AND TK_NOT
%nonassoc MENOSUNARIO
%right TK_POW
////////////////////////////////////////////////////////////////////////////////////////////////

%%
//Aquí comienza el programa
programa:			
	cabecera librerias dec_constantes dec_vbles cuerpo funciones
	{
		fprintf(salida,$2.trad);
		fprintf(salida,$3.trad);
		fprintf(salida,$6.trad);
		fprintf(salida,intr_cabecera());//Introducir el main después de las constantes
		fprintf(salida,$4.trad);
		fprintf(salida,$5.trad);
		
		/*		
		copiardatos(&auxnodo1,5,0,0,"",0,0,0,"final",0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
		*/
	};

////////////////////////////////////////////////////////////////////////////////////////////////

//salto_lin y salto_lin_dec reconocen todos los saltos de línea que hay entre declaraciones
salto_lin:                          
	salto_lin_dec {}
	|{};

/************************************************************************************************/
salto_lin_dec:                        
	'\n' {} 
	|'\n' salto_lin_dec{};

//////////////////////////////////////////////////////////////////////////////////////////////////
//Estructura del programa
cabecera: 			
	TK_PROGRAM TK_VARIABLE salto_lin
	{
		copiardatos(&auxnodo1,5,0,0,"",0,0,0,"main",0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	};
//////////////////////////////////////////////////////////////////////////////////////////////////
librerias:
	{
		strcpy($$.trad,"#include <stdio.h>\n#include <math.h>\n#include <stdlib.h>\n#include <string.h>\n");
	}
	;

//////////////////////////////////////////////////////////////////////////////////////////////////

//Constantes
dec_constantes:                 
	TK_CONST salto_lin constante 
	{
		strcpy($$.trad,$3.trad);
	}
	| {		
	strcpy($$.trad,"");
	};//Puede o no haber constantes
//////////////////////////////////////////////////////////////////////////////////////////////////
//Se le asigna valor y tipo a las constantes
constante:
	TK_VARIABLE TK_NUM salto_lin 
	{ //Un número
		$1->tipo=$2.tipo;
		strcpy($$.trad,intr_const_num($2.valnum,$1->nombre)); //La traducción
		
		copiardatos(&auxnodo1,$2.tipo,1,0,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
	
/*************************************************************************************************/
 	
	| TK_VARIABLE TK_ENT salto_lin 
	{ //Un número
		$1->tipo=$2.tipo;
		strcpy($$.trad,intr_const_int($2.valint,$1->nombre)); //La traducción
		
		copiardatos(&auxnodo1,$2.tipo,1,0,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	} 
/*************************************************************************************************/
 	
	| TK_VARIABLE TK_NBOOL salto_lin 
	{ //Un número
		$1->tipo=$2.tipo;
		strcpy($$.trad,intr_const_int($2.valbool,$1->nombre)); //La traducción
		
		
		copiardatos(&auxnodo1,$2.tipo,1,0,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	} 
/*************************************************************************************************/
	| TK_VARIABLE TK_CADENA salto_lin 
	{//Constante cadena
		$1->tipo=$2.tipo;
		strcpy($$.trad,intr_const_cad($2.cad,$1->nombre)); //Traducción

		copiardatos(&auxnodo1,$2.tipo,1,0,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}

/*************************************************************************************************/

	| TK_VARIABLE TK_NUM salto_lin constante //Varias
	{ 
		$1->tipo=$2.tipo;
		strcpy($$.trad,intr_const_num($2.valnum,$1->nombre)); //Traducción
		
		copiardatos(&auxnodo1,$2.tipo,1,0,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}

/*************************************************************************************************/
	
	| TK_VARIABLE TK_ENT salto_lin constante
	{ //Un número
		$1->tipo=$2.tipo;
		strcpy($$.trad,intr_const_int($2.valint,$1->nombre)); //La traducción
		
		copiardatos(&auxnodo1,$2.tipo,1,0,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	} 
/*************************************************************************************************/
	
	| TK_VARIABLE TK_NBOOL salto_lin constante
	{ //Un número
		$1->tipo=$2.tipo;
		strcpy($$.trad,intr_const_int($2.valbool,$1->nombre)); //La traducción
		
		copiardatos(&auxnodo1,$2.tipo,1,0,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	} 

/************************************************************************************************/
	| TK_VARIABLE TK_CADENA salto_lin constante //Varios números
	{
		$1->tipo=$2.tipo;
		strcpy($$.trad,intr_const_cad($2.cad,$1->nombre));  //Traducción

		copiardatos(&auxnodo1,$2.tipo,1,0,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	};


//////////////////////////////////////////////////////////////////////////////////////////////////

//Diferentes tipos y números correspondientes
tipo:
	TK_ENTERO 
	{
	$$.tipo=6; 
	}

	|  TK_REAL 
	{
	$$.tipo=1;} 

	|  TK_STRING	
	{
	$$.tipo=4;
	}
	| TK_CADENA
	{
	$$.tipo=4;
	}
	|  TK_BOOL 
	{
	$$.tipo=3;
	};

///////////////////////////////////////////////////////////////////////////////////////////////////
//Se declaran variables
dec_vbles:
	TK_VAR salto_lin variable 
	{
		strcpy($$.trad,$3.trad);
	}
	| {
		strcpy($$.trad,"");
	}
	;			 
/*************************************************************************************************/
variable:			
	TK_VARIABLE tipo puntero salto_lin  
	{
		$1->tipo=$2.tipo;
		strcpy($$.trad,intr_variable($2.tipo, $1->nombre,$3.espun)); //Traducción
	
		copiardatos(&auxnodo1,$2.tipo,0,$3.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}

/*************************************************************************************************/
	| TK_VARIABLE tipo puntero salto_lin variable	
	{
		$1->tipo=$2.tipo;

		strcpy($$.trad,intr_variable($2.tipo, $1->nombre,$3.espun)); //Traducción
			
		strcat($$.trad,$5.trad);
			
		copiardatos(&auxnodo1,$2.tipo,0,$3.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	};

//////////////////////////////////////////////////////////////////////////////////////////////////
puntero:
	TK_VAL
	{
		$$.espun=1;
	}
	| 
	{
		$$.espun=0;
	}
	;
//////////////////////////////////////////////////////////////////////////////////////////////////
//Main del programa
cuerpo:
	TK_INICIO salto_lin lista_sentencias TK_FIN
	{
		strcpy($$.trad,$3.trad);
		strcat($$.trad,"}\n");
	}
	;
//////////////////////////////////////////////////////////////////////////////////////////////////
//Funciones
funciones:
	funcion
	{
		strcpy($$.trad,$1.trad);
	}
	| funciones funcion
	{
		strcpy($$.trad,$2.trad);
		strcat($$.trad,$1.trad);
	}
	;
//////////////////////////////////////////////////////////////////////////////////////////////////
fun_dec:
	TK_FUNCION TK_VARIABLE
	{
		strcpy($$.trad,$2->nombre);
		
		auxvar=$2;
		insertar_fun(auxvar,OP_FUN);
		
		copiardatos(&auxnodo1,5,0,0,"",0,0,0,$2->nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL,auxvar);
	}
;
//////////////////////////////////////////////////////////////////////////////////////////////////
funcion:
	fun_dec dec_vbles dec_arg_fun devolver salto_lin lista_sentencias final
	{
		//printf("%s \n",$6.nombre);
		
		if($4.tipo==1)
			strcpy($$.trad,"float ");
		if($4.tipo==6||$4.tipo==3)
			strcpy($$.trad,"int ");
		if($4.tipo==2)
			strcpy($$.trad,"char *");
			
		strcat($$.trad,$1.trad);
		strcat($$.trad,$3.trad);
		strcat($$.trad,"{\n");
		strcat($$.trad,$6.trad);
		strcat($$.trad,$7.trad);
	}
	|
	{//Puede no haber funciones
		strcpy($$.trad,"");
	}
	;
//////////////////////////////////////////////////////////////////////////////////////////////////
devolver:	
	TK_RETORNO tipo
	{
		$$.tipo=$2.tipo;
		
		copiardatos(&auxnodo1,$2.tipo,0,0,"",0,0,0,"devolver",0);
		insertar(auxnodo1,auxnodo2,OP_RETURN,auxvar);
	}
	;
//////////////////////////////////////////////////////////////////////////////////////////////////
//Argumentos a pasarle a la función
dec_arg_fun:
		TK_ARG salto_lin argumento
	{	
		strcpy($$.trad,"(");
		strcat($$.trad,$3.trad);
		strcat($$.trad,")");
	}
	| 
	{
		strcpy($$.trad,"(");
		strcat($$.trad,")");
	}
	;
//////////////////////////////////////////////////////////////////////////////////////////////////
argumento:
	TK_VARIABLE tipo puntero salto_lin  
	{
		$1->tipo=$2.tipo;
		
		strcpy($$.trad,intr_argumento($2.tipo, $1->nombre,$3.espun)); //Traducción

		copiardatos(&auxnodo1,$2.tipo,0,$3.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$1->nombre,1);
		insertar(auxnodo1,auxnodo2,OP_ARG,auxvar);
	}
/*************************************************************************************************/
	| TK_VARIABLE tipo puntero salto_lin argumento
	{
		$1->tipo=$2.tipo;
		
		strcpy($$.trad,intr_argumento($2.tipo, $1->nombre,$3.espun)); //Traducción
		strcat($$.trad,", ");
		strcat($$.trad,$5.trad);
			
		copiardatos(&auxnodo1,$2.tipo,0,$3.espun,$1->valstr,$1->valbool,$1->valnum,$1->valint,$1->nombre,1);
		insertar(auxnodo1,auxnodo2,OP_ARG,auxvar);
	};
//////////////////////////////////////////////////////////////////////////////////////////////////
//Sentencias de aplicación
// El tipo de la asignacion depende del tipo de la variable
lista_sentencias:		
	sentencia salto_lin 
	{
		strcpy($$.trad,$1.trad);	
	}

/*************************************************************************************************/

	| sentencia salto_lin lista_sentencias 
	{		
		 strcat($$.trad,$3.trad); 
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////

//Asignaciones
sentencia:			
	asignacion 
	{		
		strcpy($$.trad,$1.trad);//Se limpia .trad
	}
/*************************************************************************************************/
//if, while, para y dowhile
	| control final
	{
		strcpy($$.trad,$1.trad);
		strcat($$.trad,$2.trad);
	}
/*************************************************************************************************/
	| visual{
	strcpy($$.trad,$1.trad);
	}
/*************************************************************************************************/	
	| lectura{
	strcpy($$.trad,$1.trad);
	}
/*************************************************************************************************/
//Comentarios
	| TK_COM
	{
		//printf("%s",$1.cad);
		strcpy($$.trad,"");
	}
/************************************************************************************************/	
	| llamar_fun ')'
	{
		strcpy($$.trad,$1.trad);
		strcat($$.trad,"(");;
		strcat($$.trad,");\n");
	}
/*************************************************************************************************/
//Llamadas a funciones
	| asig_fun  '(' TK_VARIABLE ',' llamar_arg ')'
	{
		strcpy($$.trad,$1.trad);
		strcat($$.trad,$3->nombre);
		strcat($$.trad,"(");
		strcat($$.trad,$5.trad);
		strcat($$.trad,");\n");
	
		strcpy(auxnodo1.nombre,$3->nombre);
		strcpy(auxnodo2.nombre,$1.nombre);

		insertar(auxnodo1,auxnodo2,OP_ASIG_LLAMAR,auxvar);
	}
/************************************************************************************************/
	| TK_LLAMAR '(' TK_VARIABLE ',' llamar_arg ')'
	{
		strcpy($$.trad,$3->nombre);
		strcat($$.trad,"(");
		strcat($$.trad,$5.trad);
		strcat($$.trad,");\n");
	
		strcpy(auxnodo1.nombre,$3->nombre);
		insertar(auxnodo1,auxnodo2,OP_LLAMAR,auxvar);
	}
/************************************************************************************************/
	| decre
	{
		strcpy($$.trad,$1.trad);
	}
/************************************************************************************************/
	| TK_RETORNO exp
	{	
		if($2.escons)	{
			strcpy($$.trad,"return ");
			strcat($$.trad,$2.trad);
			strcat($$.trad,";\n");
		}else{
			strcpy($$.trad,"return ");
			strcat($$.trad,$2.nombre);
			strcat($$.trad,";\n");		
		}
		copiardatos(&auxnodo1,$2.tipo,$2.escons,$2.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$2.nombre,0);
	
		insertar(auxnodo1,auxnodo2,OP_DEVOLVER,auxvar);
	}
/************************************************************************************************/	
	;
//////////////////////////////////////////////////////////////////////////////////////////////////
asig_fun:
	TK_LLAMAR
	{
	strcpy($$.trad,"");
	}
	| punteros_asignar TK_VARIABLE TK_ASIG TK_LLAMAR
	{
		char signo1[3];
		char retorno[255];
		
		if ($1.vis==0)
			strcpy(signo1,"");
		if ($1.vis==2)
			strcpy(signo1,"*");
		if ($1.vis==3)
			strcpy(signo1,"&");
			
		strcpy(retorno,signo1);
		strcat(retorno,$2->nombre);
		strcat(retorno,"=");
		
		//printf("%s\n",retorno);
		strcpy($$.trad,retorno);	
		strcpy($$.nombre,$2->nombre);
	}
	;
//////////////////////////////////////////////////////////////////////////////////////////////////
llamar_fun:
	TK_LLAMAR  '(' TK_VARIABLE
	{
		strcpy($$.trad,$3->nombre);
		strcpy(auxnodo1.nombre,$3->nombre);
		insertar(auxnodo1,auxnodo2,OP_LLAMAR,auxvar);
	}
	;
//////////////////////////////////////////////////////////////////////////////////////////////////
decre:
//Postincremento 
	TK_INC exp
	{
		strcpy($$.trad,$2.nombre);
		strcat($$.trad,"++;\n");
			
		strcpy(auxnodo1.nombre,$2.nombre);
	
		insertar(auxnodo1,auxnodo2,OP_INC,auxvar);
	}
/*************************************************************************************************/
//Postdecremento 
	|	TK_DEC exp
	{
		strcpy($$.trad,$2.nombre);
		strcat($$.trad,"--;\n");
	
		strcpy(auxnodo1.nombre,$2.nombre);
	
		insertar(auxnodo1,auxnodo2,OP_DEC,auxvar);
	}
;
/////////////////////////////////////////////////////////////////////////////////////////////////	
llamar_arg:
	exp
	{
		strcpy($$.trad,$1.trad);
		
		copiardatos(&auxnodo1,$1.tipo,0,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL_ARG,auxvar);
	}
	| llamar_arg ',' exp
	{
		strcat($$.trad,", ");
		strcat($$.trad,$3.trad);
		
		copiardatos(&auxnodo1,$3.tipo,0,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
		insertar(auxnodo1,auxnodo2,OP_DECL_ARG,auxvar);
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////	
else:
	TK_ELSE
	{
		insertar(auxnodo1,auxnodo2,OP_ELSE,auxvar);
	};
/////////////////////////////////////////////////////////////////////////////////////////////////	
control3:
	TK_SI exp
	{
		strcpy($$.trad,$2.trad);
			
		copiardatos(&auxnodo1,$2.tipo,$2.escons,$2.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$2.nombre,0);
	
		insertar(auxnodo1,auxnodo2,OP_SI,auxvar);
	}
	;
////////////////////////////////////////////////////////////////////////////////////////////////
control2:	
 TK_MIENTRAS exp
	{
	
		strcpy($$.trad,$2.trad);
		
		copiardatos(&auxnodo1,$2.tipo,$2.escons,$2.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$2.nombre,0);
	
		insertar(auxnodo1,auxnodo2,OP_WHILE,auxvar);
	}
	;
////////////////////////////////////////////////////////////////////////////////////////////////
control4:
TK_PARA TK_VARIABLE TK_ASIG TK_ENT TK_HASTA TK_ENT 
	{
		char signo[3]=">";
		char op[3];
		
		//Se comprueba si el valor objetivo es mayor o menor que el inicial para 
		//Hacer el for bien
		if(atoi($4.trad)>atoi($6.trad)) {
			strcpy(signo,">");
			strcpy(op,"--");
			}
		else if(atoi($4.trad)<atoi( $6.trad)) {
			strcpy(signo,"<");
			strcpy(op,"++");
			}
		else{
			strcpy(signo,"!=");
			strcpy(op," ");//Por poner algo
			}
		
		
		//No funciona esta forma así que se hace de la formas más larga.
		//snprintf($$.trad,"for (",$2->nombre,"=",$4.trad,";",$2->nombre,signo,$6.trad,";",$2->nombre,op,")");
		

		//Se escribe el for y se devuelve
		strcpy($$.trad,"for (");
		strcat($$.trad,$2->nombre);
		strcat($$.trad,"=");
		strcat($$.trad,$4.trad);
		strcat($$.trad,";");		
		strcat($$.trad,$2->nombre);
		strcat($$.trad,signo);
		strcat($$.trad,$6.trad);
		strcat($$.trad,";");
		strcat($$.trad,$2->nombre);
		strcat($$.trad,op);
		strcat($$.trad,")");
		
		auxvar=$2;
		copiardatos(&auxnodo1,$4.tipo,$4.escons,$4.espun,$4.valstr,$4.valbool,$4.valnum,$4.valint,$4.nombre,0);
		copiardatos(&auxnodo2,$6.tipo,$6.escons,$6.espun,$6.valstr,$6.valbool,$6.valnum,$6.valint,$6.nombre,0);
	
		insertar_para(auxnodo1,auxnodo2,OP_PARA,auxvar);
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////	
control5:
	TK_SWITCH TK_VARIABLE {
		strcpy($$.nombre,$2->nombre);
		$$.tipo=$2->tipo;
		
		copiardatos(&auxnodo1,$2->tipo,$2->escons,$2->espun,$2->valstr,$2->valbool,$2->valnum,$2->valint,$2->nombre,0);
		
		insertar(auxnodo1,auxnodo2,OP_SWITCH,auxvar);
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////	
control:
//if sin else
	control3 cont lista_sentencias 
	{
		strcpy($$.trad,"if (");
		strcat($$.trad,$1.trad);
		strcat($$.trad,")\n");
		strcat($$.trad,$2.trad);
		strcat($$.trad,$3.trad);
	}
/*************************************************************************************************/
//if con else
	| control3 cont lista_sentencias else lista_sentencias
	{
		strcpy($$.trad,"if (");
		strcat($$.trad,$1.trad);
		strcat($$.trad,") {\n");
		strcat($$.trad,$3.trad);
		strcat($$.trad,"} else {\n");
		strcat($$.trad,$5.trad);
	}
/*************************************************************************************************/
//while
	| control2 cont lista_sentencias 
	{
		strcpy($$.trad,"while (");
		strcat($$.trad,$1.trad);
		strcat($$.trad,") {\n");
		strcat($$.trad,$3.trad);
	}
/*************************************************************************************************/
//PARA
	| control4 cont lista_sentencias
	{		
		strcpy($$.trad,$1.trad);
		strcat($$.trad,$2.trad);
		strcat($$.trad,$3.trad);
	}
/*************************************************************************************************/
//SWITCH
	| control5 cases
	{	
		
		//Si todo está bien se traduce y saca por pantalla
		
		strcpy($$.trad,"switch (");
		strcat($$.trad,$1.nombre);
		strcat($$.trad,"){\n");
		strcat($$.trad,$2.trad);
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////
case:
	TK_CASO exp lista_sentencias break
	{
		$$.tipo=$2.tipo;
		
		strcpy($$.trad,"case ");
		strcat($$.trad,$2.trad);
		strcat($$.trad,":\n");		
		strcat($$.trad,$3.trad);
		strcat($$.trad,$4.trad);		
		
		copiardatos(&auxnodo1,$2.tipo,$2.escons,$2.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$2.nombre,0);
	
		insertar(auxnodo1,auxnodo2,OP_CASE,auxvar);
	}
	|	default lista_sentencias break
	{
		strcpy($$.trad,$1.trad);
		strcat($$.trad,$2.trad);
		strcat($$.trad,$3.trad);		
		
		insertar(auxnodo1,auxnodo2,OP_DEFAULT,auxvar);
	}
	;	
/////////////////////////////////////////////////////////////////////////////////////////////////
cases:
	case 
	{
	}
	| case cases
	{
		strcpy($$.trad,$2.trad);
		strcat($$.trad,$1.trad);
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////
default:
	TK_DEFAULT
	{
		strcpy($$.trad,"default:\n");
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////
break:
	{
		//fprintf(salida,"break;\n");
		strcpy($$.trad,"break;\n");
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////
cont:
	TK_HACER
	{
		strcpy($$.trad,"{\n");
	}
	//No hace falta poner hacer en el pseudo
	| 
	{
		strcpy($$.trad,"{\n");
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////
final:
	TK_FIN
	{
		//fprintf(salida,"}\n");
		strcpy($$.trad,"}\n");
		
		insertar(auxnodo1,auxnodo2,OP_FIN,auxvar);
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////
//Asigna a una variable un número o cadena
asignacion: 			
punteros_asignar TK_VARIABLE TK_ASIG punteros_asignar exp 
{
	char signo1[3],signo2[3];
	char retorno[255];
	
	if ($1.vis==0)
		strcpy(signo1,"");
	if ($1.vis==2)
		strcpy(signo1,"*");
	if ($1.vis==3)
		strcpy(signo1,"&");
	
	if ($4.vis==0)
		strcpy(signo2,"");
	if ($4.vis==2)
		strcpy(signo2,"*");
	if ($4.vis==3)
		strcpy(signo2,"&");
		
	strcpy(retorno,signo1);
	strcat(retorno,$2->nombre);
	strcat(retorno,"=");
	strcat(retorno,signo2);
	strcat(retorno,$5.trad);
	strcat(retorno,";");
	strcat(retorno,"\n");
	
	//printf("%s\n",retorno);
	strcpy($$.trad,retorno);	
	
	auxvar=$2;
	
	copiardatos(&auxnodo1,$5.tipo,$5.escons,$5.espun,$5.valstr,$5.valbool,$5.valnum,$5.valint,$5.nombre,0);
	
	insertar(auxnodo1,auxnodo2,OP_ASIGNAR,auxvar);
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////
punteros_asignar:	
	TK_VAL{ 
		$$.vis=2;//*
	}
	| TK_DIR{ 
		$$.vis=3;//&
	}
	| {
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////

//Ver expresiones
elemento_mostrar:               
exp 
{
	$$.vis=$1.vis;	
	$$.tipo=$1.tipo;
	
	switch ($1.tipo){
	case 1: 
		strcpy($$.trad,"printf(\" %%f \\n\",");
		strcat($$.trad,$1.trad);
		strcat($$.trad,");\n");
		break;
	case 2:					
		strcpy($$.trad,"printf(\" %%s \\n\",");
		strcat($$.trad,$1.trad);
		strcat($$.trad,");\n");
		break;
	case 3: 
		strcpy($$.trad,"printf(\" %%d \\n\",");
		strcat($$.trad,$1.trad);
		strcat($$.trad,");\n");
		break;
	case 4: 
		strcpy($$.trad,"printf(\" %%s \\n\",");
		strcat($$.trad,$1.trad);
		strcat($$.trad,");\n");
		break;
	case 6: 
		strcpy($$.trad,"printf(\" %%d \\n\",");
		strcat($$.trad,$1.trad);
		strcat($$.trad,");\n");
		break;
	}//switch
	

	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.cad,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
	
	insertar(auxnodo1,auxnodo2,OP_ESCRIBIR,auxvar);
};

///////////////////////////////////////////////////////////////////////////////////////////////////						
//Mostrar por pantalla
visual:
	TK_ESCRIBIR '('elemento_mostrar')'
	{
		strcpy($$.trad,$3.trad);
	} 

/*************************************************************************************************/
	| TK_ESCRIBIR '(' visual2 ',' elemento_mostrar ')'
	{
		strcpy($$.trad,$3.trad);
		strcat($$.trad,$5.trad);
	} 

/*************************************************************************************************/

	|TK_ESCRIBIR'('')'
	{
		strcpy($$.trad,"printf(\"\\n\");");
		strcat($$.trad,"\n");
	};//salto de línea
                                
////////////////////////////////////////////////////////////////////////////////////////////////
//Mosntrar varios elementos separándolos por comas
visual2:			 
	elemento_mostrar
	{	
		strcpy($$.trad,$1.trad);
	}

/*************************************************************************************************/

	| visual2 ',' elemento_mostrar  
	{	
		strcpy($$.trad,$1.trad);
		strcat($$.trad,$3.trad);
	}
	|{
		strcpy($$.trad,"");
	}
	;	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Se lee una variable o una lista

lectura:			
	TK_LEER '('TK_VARIABLE')' //aqui leemos una variable
	{
		strcpy($$.trad,vis_entrada($3->tipo,$3->nombre,$3->espun));//Traducción
		
		auxvar=$3;
	
		insertar(auxnodo1,auxnodo2,OP_LEER,auxvar);
	}
	;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Operaciones que se pueden hacer
exp:				
	exp '+' exp
	//Operaciones de suma para numeros o concatenacion para cadenas
	{
	strcat($$.trad," + ");//Traducción
	strcat($$.trad,$3.trad);
	
	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);

	insertarexp(auxnodo1,auxnodo2,OP_SUMA);
	}

/*************************************************************************************************/
//Resta, sólo números
	|	exp '-' exp
	{
		strcat($$.trad," - ");//introducimos la cadena creada para la traduccion
		strcat($$.trad,$3.trad);
		
		copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
		copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
		insertarexp(auxnodo1,auxnodo2,OP_RESTA);
		
	}
/*************************************************************************************************/
//Multiplicación, sólo números
	|	exp '*' exp
	{
		strcat($$.trad," * ");//Traducción
		strcat($$.trad,$3.trad);
		
		copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
		copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
		insertarexp(auxnodo1,auxnodo2,OP_MULT);
	}
/*************************************************************************************************/
//Divisiones
	|	exp '/' exp
	{
		strcat($$.trad," / ");//Traducción
		strcat($$.trad,$3.trad);

		copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
		copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
		insertarexp(auxnodo1,auxnodo2,OP_DIV);
	}
/*************************************************************************************************/
//Operación de cambio de signo
	|	'-' exp %prec MENOSUNARIO
	{
		strcpy($$.trad," -");//introducimos la cadena creada para la traduccion
		strcat($$.trad,$2.trad);

		copiardatos(&auxnodo1,$2.tipo,$2.escons,$2.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$2.nombre,0);
		insertarexp(auxnodo1,auxnodo2,OP_CAM);
	}

/*************************************************************************************************/
//Exponenciales
	|	exp TK_POW exp
	{
		strcpy($$.trad," pow");//Traducción
		strcpy(auxt,"(");
		strcat(auxt,$1.trad);
		strcat(auxt,",");
		strcat(auxt,$3.trad);
		strcat(auxt,")");
		strcat($$.trad,auxt);

	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
	insertarexp(auxnodo1,auxnodo2,OP_POW);
	}
/*************************************************************************************************/
//Modulo
	|	exp TK_MOD exp
	{
		strcat(auxt,$1.trad);
		strcat(auxt,"%");
		strcat(auxt,$3.trad);
		strcpy($$.trad,auxt);


		copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
		copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
		insertarexp(auxnodo1,auxnodo2,OP_MOD);
	}
/*************************************************************************************************/
//Operaciones entre parentesis
	|	'(' exp ')'
	{
	strcpy($$.trad,"(");//Traducción
	strcat($$.trad,$2.trad);
	strcat($$.trad,")");

	$$.tipo=$2.tipo;
	$$.valnum = $2.valnum;
	strcpy($$.valstr,$2.valstr);
	strcpy($$.cad,$2.cad);
	$$.valbool = $2.valbool;
	$$.valint= $2.valint;
	$$.espun= $2.espun;
	$$.escons= $2.escons;
	}

/*************************************************************************************************/
//Operaciones lógicas
	|	exp'<'exp
	{
	strcat($$.trad," < ");//Traducción
	strcat($$.trad,$3.trad);
	$$.tipo=3;

	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
	insertarexp(auxnodo1,auxnodo2,OP_MENOR);
	}
/*************************************************************************************************/
//Esta es la coparacion mayor que que devuelve true o false
	|	exp'>'exp
	{
	strcat($$.trad," > ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);

	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
	insertarexp(auxnodo1,auxnodo2,OP_MAYOR);
	}
/*************************************************************************************************/
//Esta es la coparacion mayor o igual que que devuelve true o false
	|	exp TK_MAI exp
	{
	strcat($$.trad," >= ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);
	$$.tipo=3;

	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
	
	insertarexp(auxnodo1,auxnodo2,OP_MAI);
	}
/*********************************************************************************/		
//Esta es la coparacion meyor o igual que que devuelve true o false
	|	exp TK_MEI exp
	{
	strcat($$.trad," <= ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);

	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
	insertarexp(auxnodo1,auxnodo2,OP_MEI);                                
}
/*************************************************************************************************/						
//Esta es la coparacion de no igualdad, es decir de distinto que que devuelve true o false
	|	exp TK_DIS exp
	{
	strcat($$.trad," != ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);
	$$.tipo=3;
	
	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
	insertarexp(auxnodo1,auxnodo2,OP_DESIGUALDAD);                                 
	}
/*************************************************************************************************/						
//Esta es la coparacion de  igualdad, que devuelve true o false
	|	exp TK_IGU exp
	{
		strcat($$.trad," == ");//introducimos la cadena creada para la traduccion
		strcat($$.trad,$3.trad);
		$$.tipo=3;
		
		copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
		copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
		insertarexp(auxnodo1,auxnodo2,OP_IGUALDAD);
	}
/*************************************************************************************************/
	| exp TK_AND exp
	//operacion a nivel de booleanos, and true and true devuelve true otro false
	{
	strcat($$.trad," && ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);
	$$.tipo=3;
	
	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
	insertarexp(auxnodo1,auxnodo2,OP_AND);
	}   

/*************************************************************************************************/
	| exp TK_OR exp
	//operacion a nivel de booleanos, or false or false devuelve false otro true
	{
	strcat($$.trad," || ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);
	$$.tipo=3;
	
	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre,0);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre,0);
	insertarexp(auxnodo1,auxnodo2,OP_OR);
	
	}   

/*************************************************************************************************/
	| TK_NOT exp
	//operacion a nivel de booleanos, not notfalse=true  not true devuelve false otro true

	{
	strcpy($$.trad," !");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$2.trad);
	$$.tipo=3;

	
	copiardatos(&auxnodo1,$2.tipo,$2.escons,$2.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$2.nombre,0);
	insertarexp(auxnodo1,auxnodo2,OP_NOT);	
	}   
/*************************************************************************************************/
//esto es un número real
	|	TK_NUM
	{
		$$.tipo=1;
		$$.escons=1;
		$$.valnum =$1.valnum;	  
	}
/*************************************************************************************************/
//esto es un número entero
	|	TK_ENT
	{
		$$.tipo=6;
		$$.escons=1;
		$$.valint =$1.valint;	
	}
/*************************************************************************************************/
//esto es de tipo booleano aunque internamente la tratamos como un entero
	|	TK_NBOOL
	{
		$$.tipo=3;
		$$.escons=1;
		$$.valbool= $1.valbool;
	}
/*************************************************************************************************/
//estas son las variables que hay de tantas clases como tipos
	| TK_VARIABLE //copiamos toda la informacion del nodo
	{	
		strcpy($$.trad,$1->nombre);//copio el nombre de la variable para la traduccion
		strcpy($$.nombre,$1->nombre);//copio el nombre de la variable para la traduccion
		$$.tipo=$1->tipo;
		$$.escons=0;
	}
/*************************************************************************************************/
//Esto es una cosntante de tipo cadena
	| TK_CADENA
	{
		$$.tipo=$1.tipo;
		strcpy($$.valstr,$1.cad);
		strcpy($$.cad,$1.cad);
		$$.escons=$1.escons;
	}  		
/*************************************************************************************************/
//Operaciones con punteros y arrays
	| TK_VAL exp
	{
		strcpy($$.trad,"*");
		strcat($$.trad,$2.trad);
	}
/*************************************************************************************************/
//Dir de memoria 
	| TK_DIR exp 
	{
		strcpy($$.trad,"&");
		strcat($$.trad,$2.trad);
	}
	;		
%%
//////////////////////////////////////////////////////////////////////////////////////////////////
//Main, dónde se genera el fichero
int main(int argc, char **argv)
{     	
	if(argc==1) {
		printf("Se debe introducir: el fichero a analizar\n\n");
		exit(0);
	}//no se han introducido los parametros correctos	
	extern yyin;//se importa la variable yyin de lex        
	yyin = fopen (argv[1],"r");
	
	salida=fopen("salida.c","w");//creamos el fichero de salida de la traduccion
	salida=fopen("salida.c","a+"); //abrimos en modo para añadir
	yyparse();

	fclose(salida);//se cierra el fichero de salida
	
	com=NULL;
	fin=NULL;
	
	if(INICIO==NULL)
		printf("\nError, programa vacio.\n");
	else
		ejecutar(INICIO,0,"main");
		
	/*
	printf("//////////////////\n");
	listar(&com);
	printf("//////////////////\n");
	listar(&argini);
	*/
}

