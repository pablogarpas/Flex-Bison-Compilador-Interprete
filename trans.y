%{
/****************************************************************************
****************************************************************************/
#include "trad.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Prototipos
int ejecutar();
NODO procesarexp(ARBOL *aux);
//Variables globales
int eje[10]={1,0,0,0,0,0,0,0,0,0};//variable para ver que añadir al AST
int poscontrol;//variable guardando posición
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
%token    TK_STRING
%token		TK_MIENTRAS
%token		TK_IGU
%token		TK_HAZ
%token		TK_DIR
%token		TK_VAL
%token		TK_RETORNO
%token    TK_ESCRIBIR
%token		TK_ARG
%token    TK_LIB
%token    TK_SWITCH
%token    TK_LEER
%token    TK_LLAMAR
%token	  TK_FIN
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
%type   <ELEMENTO>  	cabecera dec_constantes constante exp dec_vbles tipo variable sentencia lista_sentencias  salto_lin salto_lin_dec  asignacion visual elemento_mostrar  visual2 lectura control cont final librerias case cases default break puntero punteros_asignar funciones funcion dec_arg_fun cuerpo argumento llamar control2
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
		$2->tipo=0;  	
	};
//////////////////////////////////////////////////////////////////////////////////////////////////
librerias:
	{
		strcpy($$.trad,"#include <stdio.h>\n#include <math.h>\n");
	}
	;

//////////////////////////////////////////////////////////////////////////////////////////////////

//Constantes
dec_constantes:                 
	TK_CONST salto_lin constante 
	{
		strcpy($$.trad,$3.trad);
		
		$$.tipo=$3.tipo;
		switch ($3.tipo){
			case 1:$$.valnum=$3.valnum;break;
			case 2:strcpy($$.cad,$3.cad);break;
			case 3:$$.valbool=$3.valbool;break;
			case 6:$$.valint=$3.valint;break;
		}		
	}
	| {		
	strcpy($$.trad,"");
	};//Puede o no haber constantes


//////////////////////////////////////////////////////////////////////////////////////////////////

//Se le asigna valor y tipo a las constantes
constante:
	TK_VARIABLE TK_NUM salto_lin 
	{ //Un número
		strcpy($$.trad,intr_const_num($2.valnum,$1->nombre)); //La traducción
		$$.valnum=$1->valnum=$2.valnum;
		$$.tipo=$1->tipo=$2.tipo;
		$$.escons=1;	
		$1->escons=1;
		$1->aux=3;//Cualquier número
	}
	
/*************************************************************************************************/
 	
	| TK_VARIABLE TK_ENT salto_lin 
	{ //Un número
		strcpy($$.trad,intr_const_int($2.valint,$1->nombre)); //La traducción
		$$.valint=$1->valint=$2.valint;
		$$.tipo=$1->tipo=$2.tipo;
		$$.escons=1;	
		$1->escons=1;
		$1->aux=3;//Cualquier número
	} 
/*************************************************************************************************/
 	
	| TK_VARIABLE TK_NBOOL salto_lin 
	{ //Un número
		strcpy($$.trad,intr_const_int($2.valbool,$1->nombre)); //La traducción
		$$.valbool=$1->valbool=$2.valbool;
		$$.tipo=$1->tipo=$2.tipo;
		$$.escons=1;	
		$1->escons=1;
		$1->aux=3;//Cualquier número
	} 
/*************************************************************************************************/
	| TK_VARIABLE TK_CADENA salto_lin 
	{//Constante cadena
		strcpy($$.trad,intr_const_cad($2.cad,$1->nombre)); //Traducción
		strcpy($$.cad,strcpy($1->cad,$2.cad));    
		$$.tipo=$1->tipo=$2.tipo;
		$$.escons=1;
		$1->escons=1;
		$1->aux=3;//Cualquier número
	}

/*************************************************************************************************/

	| TK_VARIABLE TK_NUM salto_lin constante //Varias
	{ 
		strcpy($$.trad,intr_const_num($2.valnum,$1->nombre)); //Traducción
		$$.valnum=$1->valnum=$2.valnum;
		$$.tipo=$1->tipo=$2.tipo;
		$$.escons=1;
		$1->escons=1;
		$1->aux=3;//Cualquier número
	}

/*************************************************************************************************/
	
	| TK_VARIABLE TK_ENT salto_lin constante
	{ //Un número
		strcpy($$.trad,intr_const_int($2.valint,$1->nombre)); //La traducción
		$$.valint=$1->valint=$2.valint;
		$$.tipo=$1->tipo=$2.tipo;
		$$.escons=1;	
		$1->escons=1;
		$1->aux=3;//Cualquier número
	} 
/*************************************************************************************************/
	
	| TK_VARIABLE TK_NBOOL salto_lin constante
	{ //Un número
		strcpy($$.trad,intr_const_int($2.valbool,$1->nombre)); //La traducción
		$$.valbool=$1->valbool=$2.valbool;
		$$.tipo=$1->tipo=$2.tipo;
		$$.escons=1;	
		$1->escons=1;
		$1->aux=3;//Cualquier número
	} 

/************************************************************************************************/
	| TK_VARIABLE TK_CADENA salto_lin constante //Varios números
	{
		strcpy($$.trad,intr_const_cad($2.cad,$1->nombre));  //Traducción
		strcpy($$.cad,strcpy($1->cad,$2.cad));
		$$.escons=1;
		$$.tipo=$1->tipo=$2.tipo;
		$1->escons=1;
		$1->aux=3;//Cualquier número
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
	$$.tipo=2;
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
		
		$$.tipo=$3.tipo;
	}
	| {
		strcpy($$.trad,"");
	}
	;			 
/*************************************************************************************************/
variable:			
	TK_VARIABLE tipo puntero salto_lin  
	{
	
		strcpy($$.trad,intr_variable($2.tipo, $1->nombre,$3.espun)); //Traducción
	
	if ($1->escons==0) {
		$$.tipo=$2.tipo;
		$1->tipo=$2.tipo;
		strcpy($$.nombre,$1->nombre);
		$1->espun=$3.espun;
		}
	else yyerror("Error: %s ---Variable ya declarada como constante\n",$1->nombre);
	}

/*************************************************************************************************/
	| TK_VARIABLE tipo puntero salto_lin variable	
	{
	
		strcpy($$.trad,intr_variable($2.tipo, $1->nombre,$3.espun)); //Traducción
			
		strcat($$.trad,$5.trad);
			
		if ($1->escons==0)	{
			$$.tipo=$2.tipo;
			$1->tipo=$2.tipo;
			strcpy($$.nombre,$1->nombre);
			$1->espun=$3.espun;
			}
		else yyerror("Error: %s ---Variable ya declarada como constante\n",$1->nombre);             
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
		//printf($3.res);
	
		strcpy($$.trad,$3.trad);
		strcat($$.trad,"}\n");
		
		//printf("\n%s\n",$$.trad);
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
funcion:
	TK_FUNCION TK_VARIABLE dec_arg_fun dec_vbles TK_RETORNO tipo salto_lin lista_sentencias final
	{
		//printf("%s \n",$6.nombre);
		if($6.tipo==1)
			strcpy($$.trad,"float ");
		if($6.tipo==6||$6.tipo==3)
			strcpy($$.trad,"int ");
		if($6.tipo==2)
			strcpy($$.trad,"char *");
			
		strcat($$.trad,$2->nombre);
		strcat($$.trad,$3.trad);
		strcat($$.trad,"{\n");
		strcat($$.trad,$8.trad);
		strcat($$.trad,$9.trad);
		
		//printf("\n%s\n",$$.trad);
	}
	|
	{//Puede no haber funciones
		strcpy($$.trad,"");
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

		strcpy($$.trad,intr_argumento($2.tipo, $1->nombre,$3.espun)); //Traducción
	if ($1->escons==0) {
		$$.tipo=$2.tipo;
		$1->tipo=$2.tipo;
		strcpy($$.nombre,$1->nombre);
		$1->espun=$3.espun;
		}
	else yyerror("Error: %s ---Variable ya declarada como constante\n",$1->nombre);
	}
/*************************************************************************************************/
	| TK_VARIABLE tipo puntero salto_lin argumento
	{
		strcpy($$.trad,intr_argumento($2.tipo, $1->nombre,$3.espun)); //Traducción
		strcat($$.trad,", ");
		strcat($$.trad,$5.trad);
			
		if ($1->escons==0)	{
			$$.tipo=$2.tipo;
			$1->tipo=$2.tipo;
			strcpy($$.nombre,$1->nombre);
			$1->espun=$3.espun;
			}
		else yyerror("Error: %s ---Variable ya declarada como constante\n",$1->nombre);
	};
//////////////////////////////////////////////////////////////////////////////////////////////////
//Sentencias de aplicación
// El tipo de la asignacion depende del tipo de la variable
lista_sentencias:		
	sentencia salto_lin 
	{
		$$.tipo=$1.tipo;
		switch ($1.tipo){
		case 1: $$.valnum = $1.valnum;break;
		case 2:	strcpy($$.valstr,$1.valstr);break;
		case 3: $$.valbool = $1.valbool;break;
		case 4: strcat($$.valstr,$1.cad);
			//fprintf(salida,"%s",$1.trad);
			break;
		case 6: $$.valint = $1.valint;break;
		}
		
		strcpy($$.trad,$1.trad);	
		
		strcpy($$.res,$1.res);	
	}

/*************************************************************************************************/

	| sentencia salto_lin lista_sentencias 
	{
		$$.tipo=$1.tipo;
		
		switch ($1.tipo){
			case 1: $$.valnum = $1.valnum;break;
			case 2:	strcpy($$.valstr,$1.valstr);break;
			case 3: $$.valbool = $1.valbool;break;
			case 4: strcat($$.valstr,$1.cad);
				//fprintf(salida,"%s",$1.trad);
				break;
			case 6: $$.valint = $1.valint;break;
		}	
				
		 strcat($$.trad,$3.trad);
		 
		 strcat($$.res,$3.res);
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////

//Asignaciones
sentencia:			
	asignacion 
	{		
		$$.tipo=$1.tipo;
		switch ($1.tipo){
			case 1: $$.valnum = $1.valnum;break;
			case 2:	strcpy($$.valstr,$1.valstr);break;
			case 3: $$.valbool = $1.valbool;break;
			case 4: strcpy($$.valstr,$1.cad);break; 
			case 6: $$.valint = $1.valint;break;
		}
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
/*************************************************************************************************/
//Llamadas a funciones
	| TK_LLAMAR '(' TK_VARIABLE ',' llamar ')'
	{
		strcpy($$.trad,$3->nombre);
		strcat($$.trad,"(");
		strcat($$.trad,$5.trad);
		strcat($$.trad,");\n");
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////	
llamar:
	exp
	{
		strcpy($$.trad,$1.trad);
	}
	| llamar ',' exp
	{
		strcat($$.trad,", ");
		strcat($$.trad,$3.trad);
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////	
control2:	
	TK_SI exp
	{
		strcpy($$.trad,$2.trad);
			
		copiardatos(&auxnodo1,$2.tipo,$2.escons,$2.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$2.nombre);
	
		insertar(auxnodo1,auxnodo2,OP_SI,auxvar);
	};
/////////////////////////////////////////////////////////////////////////////////////////////////	
control:
//if sin else
	control2 cont lista_sentencias 
	{
		strcpy($$.trad,"if (");
		strcat($$.trad,$1.trad);
		strcat($$.trad,")\n");
		strcat($$.trad,$2.trad);
	}
/*************************************************************************************************/
//if con else
	| TK_SI exp cont lista_sentencias TK_ELSE lista_sentencias
	{
		strcpy($$.trad,"if (");
		strcat($$.trad,$2.trad);
		strcat($$.trad,")\n");
		strcat($$.trad,$4.trad);
		strcat($$.trad,"} else {\n");
		strcat($$.trad,$6.trad);
	}
/*************************************************************************************************/
	| TK_MIENTRAS exp cont lista_sentencias 
	{
		strcpy($$.trad,"while (");
		strcat($$.trad,$2.trad);
		strcat($$.trad,") {\n");
		strcat($$.trad,$4.trad);
		
		//while($2.valbool)
			//strcpy($$.res,$4.res);
	}
/*************************************************************************************************/
	| TK_HAZ sentencia TK_MIENTRAS exp
	{
		strcpy($$.trad,"do {\n");
		strcat($$.trad,$2.trad);
		strcat($$.trad,"} while(");		
		strcat($$.trad,$4.trad);
		strcat($$.trad,");\n");		
	}
/*************************************************************************************************/
	| TK_PARA TK_VARIABLE TK_ASIG exp TK_HASTA exp cont lista_sentencias
	{
		//printf("%s",intr_para($2->nombre,$4.trad,$6.trad));
		
		char signo[3]=">";
		char op[3];
		int ini;
		int obj;
		int i;
		
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
		strcat($$.trad,$7.trad);
		strcat($$.trad,$8.trad);
		
		ini=atoi($4.trad);
		obj=atoi($6.trad);
		
		for(i=ini;i<obj;i++)
			printf("%s",$8.res);
	}
/*************************************************************************************************/
	| TK_SWITCH TK_VARIABLE cases
	{				
		int aux=$3.tipo;
		int compro;
		
		while(aux>0) {
			compro= aux%10;
			if($2->tipo==compro) {//no se hace nada, tipos compatibles
			}else if (compro==9) {//no se hace nada, default
			}else if ( ($2->tipo==1 && compro== 6) || ($2->tipo==6 && compro== 1) ) {
			//Se puede comparar float con entero sin error
			}
		 	else {
			yyerror("Error: al menos uno de los casos del switch no concuerda en tipo con la variable");
			}
			aux=aux/10;
		}
		
		//Si todo está bien se traduce y saca por pantalla
		
		strcpy($$.trad,"switch (");
		strcat($$.trad,$2->nombre);
		strcat($$.trad,"){\n");
		strcat($$.trad,$3.trad);
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
	}
	|	default lista_sentencias break
	{
		strcpy($$.trad,$1.trad);
		strcat($$.trad,$2.trad);
		strcat($$.trad,$3.trad);		
		$$.tipo=9;
	}
	;
	;	
/////////////////////////////////////////////////////////////////////////////////////////////////
cases:
	case 
	{
		auxtip*=10;	//Se va aumentando esta variable para guardar los tipos en el mismo número
		//De esta manera tenemos un número cuyas unidades, decenas ... representan un tipo
	}
	| case cases
	{
	
		$$.tipo+=$2.tipo*auxtip;
	
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
	
	copiardatos(&auxnodo1,$5.tipo,$5.escons,$5.espun,$5.valstr,$5.valbool,$5.valnum,$5.valint,$5.nombre);
	
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
		auxnodo1.valnum=$1.valnum;
		strcpy(auxnodo1.cad,$1.trad);
		break;
	case 2:					
		strcpy($$.trad,"printf(\" %%s \\n\",");
		strcat($$.trad,$1.trad);
		strcat($$.trad,");\n");
		strcpy(auxnodo1.valstr,$1.valstr);
		strcpy(auxnodo1.cad,$1.trad);
		break;
	case 3: 
		auxnodo1.valbool=$1.valbool;
		strcpy(auxnodo1.valstr,$1.trad);
		strcpy($$.trad,"printf(\" %%d \\n\",");
		strcat($$.trad,$1.trad);
		strcat($$.trad,");\n");
		break;
	case 4: 
		strcpy($$.trad,"printf(\"");
		strcat($$.trad,$1.cad);
		strcat($$.trad,"\\n\");\n");
		strcpy(auxnodo1.valstr,$1.valstr);
		strcpy(auxnodo1.cad,$1.trad);
		break;
	case 6: 
		strcpy($$.trad,"printf(\" %%s \\n\",");
		strcat($$.trad,$1.trad);
		strcat($$.trad,");\n");
		auxnodo1.valint=$1.valint;
		strcpy(auxnodo1.cad,$1.trad);
		break;
	default: 
		yyerror("Error:Imposible visualizar la variable o expresion\n");
		break;
	}//switch
	

	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre);
	
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
	//strcpy($$.res,"\n");
	
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
	|{}
	;	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Se lee una variable o una lista

lectura:			
	TK_LEER '('TK_VARIABLE')' //aqui leemos una variable
	{
		strcpy($$.trad,vis_entrada($3->tipo,$3->nombre,$3->espun));//Traducción
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
	if (($1.tipo==1) && ($3.tipo==1)){
		$$.tipo=1;
		$$.valnum = $1.valnum + $3.valnum;
	}
	else if(($1.tipo==2) && ($3.tipo==2)){
		$$.tipo=2;
		strcpy($$.valstr,strcat($1.valstr,$3.valstr));
	}
	else if(($1.tipo==2) && ($3.tipo==4)){
		$$.tipo=2;
		strcpy($$.valstr,strcat($1.valstr,$3.cad));
	}
	else if(($1.tipo==4) && ($3.tipo==2)){
		$$.tipo=2;
		strcpy($$.valstr,strcat($1.cad,$3.valstr));
	}
	else if(($1.tipo==4) && ($3.tipo==4)){
		$$.tipo=4;
		strcpy($$.cad,strcat($1.cad,$3.cad));
	}
	else if(($1.tipo==6) && ($3.tipo==6)){
		$$.tipo=6;
		$$.valint = $1.valint + $3.valint;
	}
	else if(($1.tipo==1) && ($3.tipo==6)){
		$$.tipo=1;
		$$.valnum = $1.valnum + $3.valint;
	}
	else if(($1.tipo==6) && ($3.tipo==1)){
		$$.tipo=1;
		$$.valnum = $1.valint + $3.valnum;
	}
	else
	yyerror("Error: Operaciones sobre tipos diferentes\n");
	}

/*************************************************************************************************/
//Resta, sólo números
	|	exp '-' exp
	{
		strcat($$.trad," - ");//introducimos la cadena creada para la traduccion
		strcat($$.trad,$3.trad);
		if (($1.tipo==1) && ($3.tipo==1)) {
			$$.tipo=1;
			$$.valnum = $1.valnum - $3.valnum;
			}
		else if(($1.tipo==6) && ($3.tipo==6)){
			$$.tipo=6;
			$$.valint = $1.valint - $3.valint;
		}
		else if(($1.tipo==1) && ($3.tipo==6)){
			$$.tipo=1;
			$$.valnum = $1.valnum - $3.valint;
		}
		else if(($1.tipo==6) && ($3.tipo==1)){
			$$.tipo=1;
			$$.valnum = $1.valint - $3.valnum;
		}
		else {                   
		yyerror("Error: Operaciones sobre tipos diferentes\n");
		}
	}
/*************************************************************************************************/
//Multiplicación, sólo números
	|	exp '*' exp
	{
		strcat($$.trad," * ");//Traducción
		strcat($$.trad,$3.trad);
		
		if (($1.tipo==1) && ($3.tipo==1))	{
			$$.tipo=1;
			$$.valnum = $1.valnum * $3.valnum;
		}
		else if(($1.tipo==6) && ($3.tipo==6)){
			$$.tipo=6;
			$$.valint = $1.valint * $3.valint;
		}
		else if(($1.tipo==1) && ($3.tipo==6)){
			$$.tipo=1;
			$$.valnum = $1.valnum * $3.valint;
		}
		else if(($1.tipo==6) && ($3.tipo==1)){
			$$.tipo=1;
			$$.valnum = $1.valint * $3.valnum;
		}		
		else {		                   
		yyerror("Error: Operaciones sobre tipos diferentes\n");
		}
	}
/*************************************************************************************************/
//Divisiones
	|	exp '/' exp
	{
		strcat($$.trad," / ");//Traducción
		strcat($$.trad,$3.trad);

		if ($3.valnum == 0)
			yyerror("División por cero.\n");
		else if (($1.tipo==1) && ($3.tipo==1))		{
			$$.tipo=1;
			$$.valnum = $1.valnum / $3.valnum;
		}
		else if(($1.tipo==6) && ($3.tipo==6)){
			$$.tipo=6;
			$$.valint = $1.valint / $3.valint;
		}
		else if(($1.tipo==1) && ($3.tipo==6)){
			$$.tipo=1;
			$$.valnum = $1.valnum / $3.valint;
		}
		else if(($1.tipo==6) && ($3.tipo==1)){
			$$.tipo=1;
			$$.valnum = $1.valint / $3.valnum;
		}
		else	{		                  
			yyerror("Error: Operaciones sobre tipos diferentes\n");
		}
	}
/*************************************************************************************************/
//Operación de cambio de signo
	|	'-' exp %prec MENOSUNARIO
	{
		strcpy($$.trad," -");//introducimos la cadena creada para la traduccion
		strcat($$.trad,$2.trad);

		if ($2.tipo==1)	{
			$$.tipo=1;
			$$.valnum = -$2.valnum;
		}
		else if ($2.tipo==6) {
			$$.tipo=6;
			$$.valint = -$2.valint;
		}
		else	{                               
		yyerror("Error: Operaciones sobre tipos diferentes\n");
		}
	}

/*************************************************************************************************/
//Exponenciales
	|	exp TK_POW exp
	{
		strcpy($$.trad," TK_POW");//Traducción
		strcpy(auxt,"(");
		strcat(auxt,$1.trad);
		strcat(auxt,",");
		strcat(auxt,$3.trad);
		strcat(auxt,")");
		strcat($$.trad,auxt);

		if (($1.tipo==1)&& ($3.tipo==1))
		{
		$$.tipo=1;
		$$.valnum = pow($1.valnum,$3.valnum);
		}
		else if(($1.tipo==6) && ($3.tipo==6)){
			$$.tipo=6;
			$$.valint = pow($1.valint,$3.valint);
		}
		else if(($1.tipo==1) && ($3.tipo==6)){
			$$.tipo=1;
			$$.valnum = pow($1.valnum,$3.valint);
		}
		else if(($1.tipo==6) && ($3.tipo==1)){
			$$.tipo=1;
			$$.valnum = pow($1.valint,$3.valnum);
		}
		else {
			yyerror("Error: Operaciones sobre tipos diferentes\n");
		}
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
	}

/*************************************************************************************************/
//Operaciones lógicas
	|	exp'<'exp
	{
	strcat($$.trad," < ");//Traducción
	strcat($$.trad,$3.trad);

	$$.tipo=3;//Se asigna el tipo bool
	if (($1.tipo)==($3.tipo))
	{ 	
		if ($1.tipo==1)//si es real
		{
			if ($1.valnum<$3.valnum) $$.valbool=1 ;
			else $$.valbool=0;
		} 
		else if($1.tipo==2)//si es string
		{
			if (strcmp($1.valstr,$3.valstr)<0) $$.valbool =1; 
			else $$.valbool=0;
		} 	
		else if($1.tipo==4)//si es cte cadena
		{
			if (strcmp($1.cad,$3.cad)<0) $$.valbool =1; 
			else $$.valbool=0;
		}
		else if($1.tipo==6)//si es entero
		{
			if ($1.valint<$3.valint) $$.valbool=1 ;
			else $$.valbool=0;
		}
	}	

	else if (($1.tipo==2)&&($3.tipo==4))//cadena y constante
	{
		if (strcmp($1.valstr,$3.cad)<0) $$.valbool =1; 
		else $$.valbool=0;
	}
	else if (($1.tipo==4)&&($3.tipo==2))//constante y cadena
	{
		if (strcmp($1.cad,$3.valstr)<0) $$.valbool =1; 
		else $$.valbool=0;
	}
	else if (($1.tipo==6)&&($3.tipo==1))//constante y cadena
	{
		if ($1.valint<$3.valnum) $$.valbool =1; 
		else $$.valbool=0;
	}
	else if (($1.tipo==1)&&($3.tipo==6))//constante y cadena
	{
		if ($1.valnum<$3.valint) $$.valbool =1; 
		else $$.valbool=0;
	}
	else yyerror("Error: Operaciones sobre tipos diferentes\n"); 
	}
/*************************************************************************************************/
//Esta es la coparacion mayor que que devuelve true o false
	|	exp'>'exp
	{
		strcat($$.trad," > ");//introducimos la cadena creada para la traduccion
		strcat($$.trad,$3.trad);

		$$.tipo=3;//asigno tipo bool
		if (($1.tipo)==($3.tipo))
		{ 	
			if ($1.tipo==1)//si es numero
			{
			if ($1.valnum>$3.valnum) $$.valbool =1 ;
			else $$.valbool=0;
			} 
			else if($1.tipo==2)//si es string
			{
			if (strcmp($1.valstr,$3.valstr)>0) $$.valbool =1; 
			else $$.valbool=0;
			} 	
			else if($1.tipo==4)//si es cte cadena
			{
				if (strcmp($1.cad,$3.cad)>0) $$.valbool =1; 
				else $$.valbool=0;
			}
			else if($1.tipo==6)//si es cte cadena
			{
				if ($1.valint>$3.valint) $$.valbool =1 ;
				else $$.valbool=0;
			} 	 	
		}	

		else if (($1.tipo==2)&&($3.tipo==4))//cadena y constante
		{
		if (strcmp($1.valstr,$3.cad)>0) $$.valbool =1; 
		else $$.valbool=0;
		}
		else if (($1.tipo==4)&&($3.tipo==2))//constante y cadena
		{
			if (strcmp($1.cad,$3.valstr)>0) $$.valbool =1; 
			else $$.valbool=0;
		}
		else if (($1.tipo==6)&&($3.tipo==1))//constante y cadena
		{
			if ($1.valint>$3.valnum) $$.valbool =1; 
			else $$.valbool=0;
		}
			else if (($1.tipo==1)&&($3.tipo==6))//constante y cadena
		{
			if ($1.valnum>$3.valint) $$.valbool =1; 
			else $$.valbool=0;
		}

		else yyerror("Error: Operaciones sobre tipos diferentes\n"); 
	}
/*************************************************************************************************/
//Esta es la coparacion mayor o igual que que devuelve true o false
	|	exp TK_MAI exp
	{
	strcat($$.trad," >= ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);

	$$.tipo=3;//asigno tipo bool
	if (($1.tipo)==($3.tipo))
	{ 	
		if ($1.tipo==1)//si es numero
		{
			if ($1.valnum>=$3.valnum) $$.valbool =1 ;
			else $$.valbool=0;
		} 
		else if($1.tipo==2)//si es string
		{
			if (strcmp($1.valstr,$3.valstr)>=0) $$.valbool =1; 
			else $$.valbool=0;
		} 	
		else if($1.tipo==4)//si es cte cadena
		{
			if (strcmp($1.cad,$3.cad)>=0) $$.valbool =1; 
			else $$.valbool=0;
		} 	
		else if ($1.tipo==6)//si es numero
		{
			if ($1.valint>=$3.valint) $$.valbool =1 ;
			else $$.valbool=0;
		} 
	}	

	else if (($1.tipo==2)&&($3.tipo==4))//cadena y constante
	{
		if (strcmp($1.valstr,$3.cad)>=0) $$.valbool =1; 
		else $$.valbool=0;
	}
	else if (($1.tipo==4)&&($3.tipo==2))//constante y cadena
	{
		if (strcmp($1.cad,$3.valstr)>=0) $$.valbool =1; 
		else $$.valbool=0;
	}
		else if (($1.tipo==6)&&($3.tipo==1))//constante y cadena
	{
		if ($1.valint>=$3.valnum) $$.valbool =1; 
		else $$.valbool=0;
	}
		else if (($1.tipo==1)&&($3.tipo==6))//constante y cadena
	{
		if ($1.valnum>=$3.valint) $$.valbool =1; 
		else $$.valbool=0;
	}

	else yyerror("Error: Operaciones sobre tipos diferentes\n"); 
	}
/*********************************************************************************/		
//Esta es la coparacion meyor o igual que que devuelve true o false
	|	exp TK_MEI exp
	{
	strcat($$.trad," <= ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);

	$$.tipo=3;//asigno tipo bool
	if (($1.tipo)==($3.tipo))
	{ 	
		if ($1.tipo==1)//si es numero
		{
		if ($1.valnum<=$3.valnum) $$.valbool =1 ;
			else $$.valbool=0;
		} 
		else if($1.tipo==2)//si es string
		{
			if (strcmp($1.valstr,$3.valstr)<=0) $$.valbool =1; 
			else $$.valbool=0;
		} 	
		else if($1.tipo==4)//si es cte cadena
		{
			if (strcmp($1.cad,$3.cad)<=0) $$.valbool =1; 
			else $$.valbool=0;
		} 	
		if ($1.tipo==6)//si es numero
		{
			if ($1.valint<=$3.valint) $$.valbool =1 ;
			else $$.valbool=0;
		} 
	}	

	else if (($1.tipo==2)&&($3.tipo==4))//cadena y constante
	{
		if (strcmp($1.valstr,$3.cad)<=0) $$.valbool =1; 
		else $$.valbool=0;
	}
	else if (($1.tipo==4)&&($3.tipo==2))//constante y cadena
	{
		if (strcmp($1.cad,$3.valstr)<=0) $$.valbool =1; 
		else $$.valbool=0;
	}
	else if (($1.tipo==6)&&($3.tipo==1))//constante y cadena
	{
		if ($1.valint>=$3.valnum) $$.valbool =1; 
		else $$.valbool=0;
	}
		else if (($1.tipo==1)&&($3.tipo==6))//constante y cadena
	{
		if ($1.valnum>=$3.valint) $$.valbool =1; 
		else $$.valbool=0;
	}

	else yyerror("Error: Operaciones sobre tipos diferentes\n");                                  
}
/*************************************************************************************************/						
//Esta es la coparacion de no igualdad, es decir de distinto que que devuelve true o false
	|	exp TK_DIS exp
	{
	strcat($$.trad," != ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);

	$$.tipo=3;//asigno tipo bool
	if (($1.tipo)==($3.tipo))
	{ 	
		if ($1.tipo==1)//si es numero
		{
			if ($1.valnum!=$3.valnum) $$.valbool =1 ;
			else $$.valbool=0;
		} 
		else if($1.tipo==2)//si es string
		{
			if (strcmp($1.valstr,$3.valstr)!=0) $$.valbool =1; 
			else $$.valbool=0;
		} 	
		else if($1.tipo==4)//si es cte cadena
		{
			if (strcmp($1.cad,$3.cad)!=0) $$.valbool =1; 
			else $$.valbool=0;
		}
		if ($1.tipo==6)//si es numero
		{
			if ($1.valint!=$3.valint) $$.valbool =1 ;
			else $$.valbool=0;
		} 
	}	

	else if (($1.tipo==2)&&($3.tipo==4))//cadena y constante
	{
	if (strcmp($1.valstr,$3.cad)!=0) $$.valbool =1; 
	else $$.valbool=0;
	}
	else if (($1.tipo==4)&&($3.tipo==2))//constante y cadena
	{
	if (strcmp($1.cad,$3.valstr)!=0) $$.valbool =1; 
	else $$.valbool=0;
	}
	else if (($1.tipo==6)&&($3.tipo==1))//constante y cadena
	{
		if ($1.valint!=$3.valnum) $$.valbool =1; 
		else $$.valbool=0;
	}
	else if (($1.tipo==1)&&($3.tipo==6))//constante y cadena
	{
		if ($1.valnum!=$3.valint) $$.valbool =1; 
		else $$.valbool=0;
	}

	else yyerror("Error: Operaciones sobre tipos diferentes\n");                                  
	}
/*************************************************************************************************/						
//Esta es la coparacion de  igualdad, que devuelve true o false
	|	exp TK_IGU exp
	{
		strcat($$.trad," == ");//introducimos la cadena creada para la traduccion
		strcat($$.trad,$3.trad);
		$$.tipo=3;
		

		copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre);
		copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$1.nombre);
		insertarexp(auxnodo1,auxnodo2,OP_IGUALDAD);
	}



/*************************************************************************************************/
	| exp TK_AND exp
	//operacion a nivel de booleanos, and true and true devuelve true otro false

	{
	strcat($$.trad," && ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);
	
	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre);
	insertarexp(auxnodo1,auxnodo2,OP_AND);
	}   

/*************************************************************************************************/
	| exp TK_OR exp
	//operacion a nivel de booleanos, or false or false devuelve false otro true
	{
	strcat($$.trad," || ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);
	
	copiardatos(&auxnodo1,$1.tipo,$1.escons,$1.espun,$1.valstr,$1.valbool,$1.valnum,$1.valint,$1.nombre);
	copiardatos(&auxnodo2,$3.tipo,$3.escons,$3.espun,$3.valstr,$3.valbool,$3.valnum,$3.valint,$3.nombre);
	insertarexp(auxnodo1,auxnodo2,OP_OR);
	
	}   

/*************************************************************************************************/
	| TK_NOT exp
	//operacion a nivel de booleanos, not notfalse=true  not true devuelve false otro true

	{
	strcpy($$.trad," !");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$2.trad);

	
	copiardatos(&auxnodo1,$2.tipo,$2.escons,$2.espun,$2.valstr,$2.valbool,$2.valnum,$2.valint,$2.nombre);
	insertarexp(auxnodo1,auxnodo2,OP_NOT);	
	}   
/*************************************************************************************************/
//esto es un número real
	|	TK_NUM
	{
		$$.tipo=1;
		$$.valnum =$1.valnum;	  
	}
/*************************************************************************************************/
//esto es un número entero
	|	TK_ENT
	{
		$$.tipo=6;
		
		$$.valint =$1.valint;	
	}
/*************************************************************************************************/
//esto es de tipo booleano aunque internamente la tratamos como un entero
	|	TK_NBOOL
	{
		$$.tipo=3;
		$$.valbool= $1.valbool;
	}
/*************************************************************************************************/
//estas son las variables que hay de tantas clases como tipos
	| TK_VARIABLE //copiamos toda la informacion del nodo
	{
		strcpy($$.trad,$1->nombre);//copio el nombre de la variable para la traduccion
		strcpy($$.nombre,$1->nombre);//copio el nombre de la variable para la traduccion
		strcpy($$.valstr,$1->valstr);//strign
		strcpy($$.cad,$1->cad);//cadena, esto es por los identificadores de las constantes
		$$.valnum=$1->valnum;	//variable numerica
		$$.valbool=$1->valbool;//variable de tipo booleano
		$$.valint=$1->valint;//variable de tipo entero
		$$.tipo=$1->tipo;//tipo de la variable
		$$.escons=$1->escons; //Nos dice si es una cosntante o no                    
		$$.vis=$1->aux;//para traducir la visualizacion
		$$.espun= $1->espun;
	}
/*************************************************************************************************/
//Esto es una cosntante de tipo cadena
	| TK_CADENA
	{
		$$.tipo=$1.tipo;
		strcpy($$.valstr,$1.cad);
		$$.escons=$1.escons;
	}  		
/*************************************************************************************************/

//Preincremento 
	|	TK_INC variable
	{
		if($2.tipo==6) {
			intr_inc($2.nombre,0);
			$$.valint=$2.valint;		
			$$.tipo=$2.tipo;
			}
		else
			yyerror("Error: No se puede incrementar una variable no númerica");
	}
/*************************************************************************************************/
//Postincremento 
	|	variable TK_INC
	{
		if($1.tipo==6) {
			intr_inc($1.nombre,1);
			$$.valint=$1.valint;
			$$.tipo=$1.tipo;
			}
		else
			yyerror("Error: No se puede incrementar una variable no númerica");
	}
/*************************************************************************************************/
//Predecremento
	|	TK_DEC variable
	{
		if($2.tipo==6) {
			intr_dec($2.nombre,0);
			$$.valint=$2.valint;		
			$$.tipo=$2.tipo;
			}
		else
			yyerror("Error: No se puede decrementar una variable no númerica");
	}
/*************************************************************************************************/
//Postdecremento 
	|	variable TK_DEC
	{
		if($1.tipo==6) {
			intr_dec($1.nombre,1);
			$$.valint=$1.valint;
			$$.tipo=$1.tipo;
			}
		else
			yyerror("Error: No se puede decrementar una variable no númerica");
	}
/*************************************************************************************************/
	| TK_VAL exp
	{
		strcpy($$.trad,"*");
		strcat($$.trad,$2.trad);
	}
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
	
	if(INICIO==NULL)
		printf("\nError, programa vacio.\n");
	else
		ejecutar();
}

int ejecutar() {
	ARBOL *aux;
	extern com;
	extern fin;
	NODO *variable;
	aux=INICIO;
	
	do {
		switch(aux->op){
		case OP_ESCRIBIR:
			if(aux->izq!=NULL) 
				aux->exp1=procesarexp(aux->izq);
			
			switch (aux->exp1.tipo){
				case 1:
					if(aux->exp1.escons) {
						printf("%f\n",aux->exp1.valnum);
					}
					else {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						printf("%f\n",variable->valnum);
					}
					break;
				case 2:	
					if(aux->exp1.escons) {
						printf("%s\n",aux->exp1.valstr);
					}
					else {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						printf("%s\n",variable->valstr);
					}
					break;
				case 3:
					if(aux->exp1.escons) {
						printf("%d\n",aux->exp1.valbool);
					}
					else {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						printf("%d\n",variable->valbool);
					}
					break;
				case 4:	
					if(aux->exp1.escons) {
						printf("%s\n",aux->exp1.valstr);
					}
					else {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						printf("%s\n",variable->valstr);
					}
					break;
				case 6: 
					if(aux->exp1.escons) {
						printf("%d\n",aux->exp1.valint);
					}
					else {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						printf("%d\n",variable->valint);
					}
					break;
			}//switch
			break;
		case OP_ASIGNAR:		
			if ((aux->var->tipo==aux->exp1.tipo)&&(aux->var->escons==0)&&(aux->var->espun==0)) {
				aux->var->tipo=aux->exp1.tipo;
				strcpy(aux->var->valstr,aux->exp1.valstr);
				aux->var->valbool= aux->exp1.valbool;
				aux->var->valnum = aux->exp1.valnum;
				aux->var->valint = aux->exp1.valint;
			}
			else if((aux->var->tipo=2)&&(aux->exp1.tipo==4)&&(aux->var->escons==0)&&(aux->var->espun==0)) {	
				strcpy(aux->var->valstr,aux->exp1.valstr);
			}
			else yyerror("Error en la asignación, no concuerdan los tipos o la variable es constante\n");	
			break;
		case OP_SI:		
			if (aux->exp1.tipo != 3){
				yyerror("Error en el si\n");
				break;
				}
				
			if(aux->izq!=NULL) 
				aux->exp1=procesarexp(aux->izq);	
			
			if(aux->exp1.valbool==0) {
				while(aux->der->op!=OP_FIN) {
					aux=aux->der;
				}
			}
				
			break;
		}//switch
		aux=aux->der;
	}while(aux!=NULL);
}//función

NODO procesarexp(ARBOL *aux){
	NODO retorno;
	NODO *variable;
	extern com;
	extern fin;
	int i,k;
	do {
		switch(aux->op){
			case OP_IGUALDAD:
				retorno.tipo=3;//asigno tipo bool
				if ((aux->exp1.tipo)==(aux->exp2.tipo))
				{ 	
					if (aux->exp1.tipo==1)//si es numero
					{
						if (aux->exp1.valnum!=aux->exp2.valnum) retorno.valbool =0 ;
						else retorno.valbool=1;
					} 
					else if(aux->exp1.tipo==2)//si es string
					{
						if (strcmp(aux->exp1.valstr,aux->exp2.valstr)!=0) retorno.valbool =0; 
						else retorno.valbool=1;
					} 	
					else if(aux->exp1.tipo==4)//si es cte cadena
					{
						if (strcmp(aux->exp1.cad,aux->exp2.cad)!=0) retorno.valbool =0; 
						else retorno.valbool=1;
					}
					if (aux->exp1.tipo==6)//si es numero
					{
						if (aux->exp1.valint!=aux->exp2.valint) retorno.valbool =0 ;
						else retorno.valbool=1;
					} 
				}	

				else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
				{
				if (strcmp(aux->exp1.valstr,aux->exp2.cad)!=0) retorno.valbool =0; 
				else retorno.valbool=1;
				}
				else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
				{
				if (strcmp(aux->exp1.cad,aux->exp2.valstr)!=0) retorno.valbool =0; 
				else retorno.valbool=1;
				}
				else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
				{
					if (aux->exp1.valint!=aux->exp2.valnum) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
				{
					if (aux->exp1.valnum!=aux->exp2.valint) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				else yyerror("Error: Operaciones sobre tipos diferentes \n");                                                            
				
				retorno.escons=1;
				retorno.espun=0;
				return retorno;
				break;
			case OP_NOT:
				if (aux->exp1.tipo==3) 
				{
					retorno.tipo=3;
					retorno.valbool = aux->exp1.valbool;
				}
				else yyerror("Error en la negación: Operaciones sobre tipos incorrectos\n");
				return retorno;
				break;
			case OP_OR:
				if ((aux->exp2.tipo==3) && (aux->exp2.tipo==3)) {
					retorno.tipo=3;
					if(!aux->exp1.escons) {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						i=variable->valbool;
					} else
						i=aux->exp1.valbool;
						
					if(!aux->exp2.escons) {
						variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
						k=variable->valbool;
					} else
						k=aux->exp2.valbool;
					
					retorno.valbool = (k || i);
				}
				else yyerror("Error en el OR: Operación sobre tipos diferentes\n");
				
				retorno.escons=1;
				retorno.espun=0;
				return retorno;
				break;
			case OP_AND:
				if ((aux->exp2.tipo==3) && (aux->exp2.tipo==3)) {
					retorno.tipo=3;
					if(!aux->exp1.escons) {
						variable=buscar_simbolo(aux->exp1.nombre,&com,&fin);
						i=variable->valbool;
					} else
						i=aux->exp1.valbool;
						
					if(!aux->exp2.escons) {
						variable=buscar_simbolo(aux->exp2.nombre,&com,&fin);
						k=variable->valbool;
					} else
						k=aux->exp2.valbool;
					
					retorno.valbool = (k && i);
				}
				else yyerror("Error en el AND: Operación sobre tipos diferentes\n");
				
				retorno.escons=1;
				retorno.espun=0;
				return retorno;
				break;
		}//switch
		aux=aux->izq;
	}while(aux!=NULL);
}//función
