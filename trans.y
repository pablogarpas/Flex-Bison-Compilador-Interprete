%{
/****************************************************************************
****************************************************************************/
#include "codigo.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Variables globales
int   auxb;  //variable auxiliar para la lectura de booleanos 
int   auxint;  //variable auxiliar para la lectura de enteros
float auxn;  //variable auxiliar para la lectura de numeros
char  auxc[30];//variable auxiliar para la lectura de strings
char  auxt[30];//variable auxiliar para las traducciones
%}


//definimos los tipos de datos que vamos a utilizar
%union 	{
	struct NODO *indice; //puntero a la tabla de simbolos 
	struct elemento {
		int escons; //nos dice si es o no constante 1->si 0->no 
		int tipo; //tipo entero
		int valbool; //tipo booleano
		double valnum;	//valor numerico	     
		int valint; //valor entero  
		char valstr[255]; //valor de tipo string
		char cad[255];//valor para las cadenas
		char trad[255];//almaceno la cadena de composicion de exp
		int vis; //variable para visualizar las constantes cadena correctamente	
		} nterminal;
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
%token    TK_ESCRIBIR
%token    TK_LIB
%token    TK_LEER
%token	  TK_FIN
%token	  TK_HACER
%token	  TK_CONT
%token		TK_HASTA
%token		TK_PARA
%token  <nterminal> TK_CADENA
%token 	<nterminal> TK_NBOOL
%token 	<nterminal>	TK_NUM
%token 	<nterminal>	TK_ENT
%token 	<indice>	TK_VARIABLE
%type   <nterminal>  	cabecera dec_constantes constante exp dec_vbles tipo variable sentencia lista_sentencias  salto_lin salto_lin_dec  asignacion visual elemento_mostrar  visual2 lectura lectura2 control cont final librerias libreria
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
	cabecera librerias dec_constantes dec_vbles cuerpo{};

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
	TK_LIB salto_lin libreria
	{

	}
	|{}
	;
//////////////////////////////////////////////////////////////////////////////////////////////////
libreria:
	TK_CADENA salto_lin
	{
		intr_lib($1.cad); //Traducción
	}
	;

//////////////////////////////////////////////////////////////////////////////////////////////////

//Constantes
dec_constantes:                 
	TK_CONST salto_lin constante 
	{
		intr_cabecera();//Introducir el main después de las constantes
	
		$$.tipo=$3.tipo;
		switch ($3.tipo){
			case 1:$$.valnum=$3.valnum;break;
			case 2:strcpy($$.cad,$3.cad);break;
			case 3:$$.valbool=$3.valbool;break;
			case 6:$$.valint=$3.valint;break;
		}		
	}
	| {		intr_cabecera();//Introducir el main después de las constantes
	};//Puede o no haber constantes


//////////////////////////////////////////////////////////////////////////////////////////////////

//Se le asigna valor y tipo a las constantes
constante:
	TK_VARIABLE '=' TK_NUM salto_lin 
	{ //Un número
		intr_const_num($3.valnum,$1->nombre); //La traducción
		$$.valnum=$1->valnum=$3.valnum;
		$$.tipo=$1->tipo=$3.tipo;
		$$.escons=1;	
		$1->escons=1;
		$1->aux=3;//Cualquier número
	}
	
/*************************************************************************************************/
 	
	| TK_VARIABLE '=' TK_ENT salto_lin 
	{ //Un número
		intr_const_int($3.valint,$1->nombre); //La traducción
		$$.valint=$1->valint=$3.valint;
		$$.tipo=$1->tipo=$3.tipo;
		$$.escons=1;	
		$1->escons=1;
		$1->aux=3;//Cualquier número
	} 
/*************************************************************************************************/
 	
	| TK_VARIABLE '=' TK_NBOOL salto_lin 
	{ //Un número
		intr_const_int($3.valbool,$1->nombre); //La traducción
		$$.valbool=$1->valbool=$3.valbool;
		$$.tipo=$1->tipo=$3.tipo;
		$$.escons=1;	
		$1->escons=1;
		$1->aux=3;//Cualquier número
	} 
/*************************************************************************************************/
	| TK_VARIABLE '=' TK_CADENA salto_lin 
	{//Constante cadena
		intr_const_cad($3.cad,$1->nombre); //Traducción
		strcpy($$.cad,strcpy($1->cad,$3.cad));    
		$$.tipo=$1->tipo=$3.tipo;
		$$.escons=1;
		$1->escons=1;
		$1->aux=3;//Cualquier número
	}

/*************************************************************************************************/

	| TK_VARIABLE '=' TK_NUM salto_lin constante //Varias
	{ 
		intr_const_num($3.valnum,$1->nombre); //Traducción
		$$.valnum=$1->valnum=$3.valnum;
		$$.tipo=$1->tipo=$3.tipo;
		$$.escons=1;
		$1->escons=1;
		$1->aux=3;//Cualquier número
	}

/*************************************************************************************************/
	
	| TK_VARIABLE '=' TK_ENT salto_lin constante
	{ //Un número
		intr_const_int($3.valint,$1->nombre); //La traducción
		$$.valint=$1->valint=$3.valint;
		$$.tipo=$1->tipo=$3.tipo;
		$$.escons=1;	
		$1->escons=1;
		$1->aux=3;//Cualquier número
	} 
/*************************************************************************************************/
	
	| TK_VARIABLE '=' TK_NBOOL salto_lin constante
	{ //Un número
		intr_const_int($3.valbool,$1->nombre); //La traducción
		$$.valbool=$1->valbool=$3.valbool;
		$$.tipo=$1->tipo=$3.tipo;
		$$.escons=1;	
		$1->escons=1;
		$1->aux=3;//Cualquier número
	} 

/************************************************************************************************/
	| TK_VARIABLE '=' TK_CADENA salto_lin constante //Varios números
	{
		intr_const_cad($3.cad,$1->nombre);  //Traducción
		strcpy($$.cad,strcpy($1->cad,$3.cad));
		$$.escons=1;
		$$.tipo=$1->tipo=$3.tipo;
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
		
		$$.tipo=$3.tipo;
	}
	| {}
	;
				 
/*************************************************************************************************/

variable:			
	TK_VARIABLE tipo salto_lin  
	{
	intr_variable($2.tipo, $1->nombre); //Traducción
	if ($1->escons==0)		
		$$.tipo=$1->tipo=$2.tipo;
	else printf("Error: %s ---Variable ya declarada como constante\n",$1->nombre);
	}

/*************************************************************************************************/
	| TK_VARIABLE tipo salto_lin variable	
	{
		intr_variable($2.tipo, $1->nombre);  //Traducción
		if ($1->escons==0)	
		$$.tipo=$1->tipo=$2.tipo;
		else printf("Error: %s ---Variable ya declarada como constante\n",$1->nombre);             
	};

//////////////////////////////////////////////////////////////////////////////////////////////////

//Cuerpo del programa
cuerpo:
	TK_INICIO salto_lin lista_sentencias final
	{}
	;

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
		case 4: strcpy($$.valstr,$1.cad);break;
		case 6: $$.valint = $1.valint;break;
		}
	}

/*************************************************************************************************/

	| sentencia salto_lin lista_sentencias 
	{
		$$.tipo=$1.tipo;
		switch ($1.tipo){
			case 1: $$.valnum = $1.valnum;break;
			case 2:	strcpy($$.valstr,$1.valstr);break;
			case 3: $$.valbool = $1.valbool;break;
			case 4: strcpy($$.cad,$1.cad);break;  	
			case 6: $$.valint = $1.valint;break;
		}		
	};


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
	}

/*************************************************************************************************/
	| control cont lista_sentencias final
	{	if($1.valbool==1)
			$$=$3;
	}
/*************************************************************************************************/

	| visual{}
	| lectura{};
	
/////////////////////////////////////////////////////////////////////////////////////////////////	
control:
	TK_SI exp 
	{
		fprintf(salida,"if ");
			vis_exp($2.tipo,$2.trad);
	}
	| TK_MIENTRAS exp
	{
		fprintf(salida,"while ");
			vis_exp($2.tipo,$2.trad);
	}
	| TK_PARA TK_VARIABLE TK_ASIG exp TK_HASTA exp
	{
		//fprintf(salida,"for (%s=%s;%s<%s;%s )",$2->nombre,$4.trad,$2->nombre,$6.trad,$2->nombre);
			//fprintf(salida,"\n%s\n",$4.trad);
		intr_para($2->nombre,$4.trad,$6.trad);
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////
cont:
	TK_HACER
	{
		fprintf(salida,"{\n");
	}
	;
/////////////////////////////////////////////////////////////////////////////////////////////////
final:
	TK_FIN
	{
		fprintf(salida,"}\n");
	};
/////////////////////////////////////////////////////////////////////////////////////////////////
//Asigna a una variable un número o cadena
asignacion: 			
TK_VARIABLE TK_ASIG exp 
{
	intr_sentencia($1->nombre,$3.trad);   //Traducción
	if (($1->tipo==$3.tipo)&&($1->escons==0)) {
		$$.tipo=$1->tipo=$3.tipo;
		strcpy($1->valstr,$3.valstr);
		strcpy($$.valstr,$1->valstr);
		$$.valbool = $1->valbool=$3.valbool;
		$$.valnum = $1->valnum = $3.valnum;
		$$.valint = $1->valint = $3.valint;
		}
	//Aquí se asigna a una variable de tipo string una constante cadena;
	else if(($1->tipo==2)&&($3.tipo==4)&&($1->escons==0)) {
		$$.tipo=$1->tipo=2;
		strcpy($1->valstr,$3.cad);
		strcpy($$.valstr,$1->valstr);	
		}	  
	else if(($1->tipo==6)&&($1->escons==0)) {
		$$.valint = $1->valint = $3.valint;
		}
	else if(($1->tipo==3)&&($1->escons==0)) {
		$$.valbool = $1->valbool = $3.valbool;
		}
	else yyerror("Error en la asignacion: no concuerdan los tipos o %s es constante\n",$1->nombre);				   
	};

/////////////////////////////////////////////////////////////////////////////////////////////////

//Ver expresiones
elemento_mostrar:               
exp 
{
	$$.vis=$1.vis;	
	$$.tipo=$1.tipo;
	switch ($1.tipo){
		case 1: $$.valnum = $1.valnum;break;
		case 2:	strcpy($$.valstr,$1.valstr);break;
		case 3: $$.valbool = $1.valbool;break;
		case 4: strcpy($$.cad,$1.cad);break;	
		case 6: $$.valint = $1.valint;break;
		}
	};

///////////////////////////////////////////////////////////////////////////////////////////////////						
//Mostrar por pantalla
visual:
	TK_ESCRIBIR '('elemento_mostrar')'
	{
	vis_salida_rc($3.tipo,$3.trad,$3.vis);  //Traducción
	switch ($3.tipo){
		case 1: printf(" %f \n",$3.valnum);break;
		case 2:	printf(" %s \n",$3.valstr);break;
		case 3: if($3.valbool==1) printf(" TRUE \n");
		else if($3.valbool==0) printf(" FALSE \n");
		break;
		case 4: printf(" %s \n",$3.cad);break;
		case 6: printf(" %d \n",$3.valint);break;
		default: printf("Error:Imposible visualizar la variable o expresion\n");
		}	
	} 

/*************************************************************************************************/
	| TK_ESCRIBIR '(' visual2 ',' elemento_mostrar ')'
	{
	vis_salida_rc($5.tipo,$5.trad,$5.vis);  //hacemos la traduccion  para la salida por pantalla
	switch ($5.tipo){
		case 1: printf(" %f \n",$5.valnum);break;
		case 2:	printf(" %s \n",$5.valstr);break;
		case 3: if($5.valbool==1) printf(" TRUE \n");
		else if($5.valbool==0) printf(" FALSE \n");	break;
		case 4: printf(" %s \n",$5.cad);break;
		case 6: printf(" %d \n",$5.valint);break;
		default: printf("Error:Imposible visualizar la variable o expresion\n");
		}
	} 

/*************************************************************************************************/

	|TK_ESCRIBIR'('')'
	{
	fprintf(salida,"printf(\"\\n\");");  //traducción
	printf("\n");};//salto de línea
                                
////////////////////////////////////////////////////////////////////////////////////////////////
//Mosntrar varios elementos separándolos por comas
visual2:			 
	elemento_mostrar
	{	
	vis_salida($1.tipo,$1.trad,$1.vis); //Traducción
	switch ($1.tipo){
		case 1: printf(" %f ",$1.valnum);;break;
		case 2:	printf(" %s ",$1.valstr);break;
		case 3: if($1.valbool==1) printf("TRUE");
		else if($1.valbool==0) printf("FALSE");
		break;
		case 4: printf(" %s ",$1.cad);break;
		case 6: printf(" %d ",$1.valint);break;
		default: printf("Error:Imposible visualizar la variable o expresion\n");
		}
	}

/*************************************************************************************************/

	| visual2 ',' elemento_mostrar  
	{	
	vis_salida($3.tipo,$3.trad,$3.vis); //Traducción
		switch ($3.tipo){
		case 1: printf(" %f ",$3.valnum);;break;
		case 2:	printf(" %s ",$3.valstr);break;
		case 3: if($3.valbool==1) printf("TRUE");
		else if($3.valbool==0) printf("FALSE");
		break;
		case 4: printf(" %s ",$3.cad);break;
		case 6: printf(" %d ",$3.valint);break;
		default: printf("Error:Imposible visualizar la variable o expresion\n");
		}
	}
	|{}
	;	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Se lee una variable o una lista

lectura:			
	TK_LEER '('TK_VARIABLE')' //aqui leemos una variable
	{
	vis_entrada($3->tipo,$3->nombre);  //hacemos la traduccion  para la entrada por teclado

	if ($3->escons==0) //no es una constante y la podemos leer   
		{
		if($3->tipo==1){	
			scanf("%f",&auxn);
			$3->valnum=auxn;
			}
		else if($3->tipo==3)
			{
			scanf("%d",&auxb);
			$3->valbool=auxb;
			}
		else if($3->tipo==2)
			{						
			scanf("%s",auxc);
			strcpy($3->valstr,auxc);
			}
		else if($3->tipo==6)
			{						
			scanf("%d",&auxint);
			$3->valint=auxint;
			}
		else 
			printf("Error: No se puede leer, variable no declarada\n");
	}
	else 
		printf("Error: No podemos leer una constante\n");
	}

/**************************************************************************************************************************************/
|TK_LEER '('lectura2 ',' TK_VARIABLE')' //aqui llemos varias variables
	{
		vis_entrada($5->tipo,$5->nombre);    //hacemos la traduccion  para la entrada por teclado
		if ($5->escons==0) //no es una constante y la podemos leer   
		{
			if($5->tipo==1){	
				scanf("%f",&auxn);
				$5->valnum=auxn;
			}
			else if($5->tipo==3)
			{
				scanf("%d",&auxb);
				$5->valbool=auxb;
			}
			else if($5->tipo==2)
			{						
				scanf("%s",auxc);
				strcpy($5->valstr,auxc);
			}
			else if($5->tipo==6)
			{						
				scanf("%d",&auxint);
				$5->valbool=auxint;
			}
			else 
				printf("Error: No se puede leer, variable no declarada\n");
		}
		else 
		printf("Error: No podemos leer una constante\n");
	}
	;


//////////////////////////////////////////////////////////////////////////////////////////////////
lectura2:                       
	TK_VARIABLE //aqui lemos una variable
	{
		vis_entrada($1->tipo,$1->nombre); //hacemos la traduccion  para la entrada por teclado
		if ($1->escons==0) //no es una constante y la podemos leer   
		{
			if($1->tipo==1){	
			scanf("%f",&auxn);
			$1->valnum=auxn;
			}
			else if($1->tipo==3)
			{
			scanf("%d",&auxb);
			$1->valbool=auxb;
			}
			else if($1->tipo==6)
			{
			scanf("%d",&auxint);
			$1->valint=auxint;
			}
			else if($1->tipo==2)
			{						
			scanf("%s",auxc);
			strcpy($1->valstr,auxc);
			}
			else 
			printf("Error: No se puede leer, variable no declarada\n");
		}
		else 
			printf("Error: No podemos leer una constante\n");
	}
/*******************************************************************************************************/
	|lectura2 ',' TK_VARIABLE //aqui lemos una variable
	{
		vis_entrada($3->tipo,$3->nombre); //hacemos la traduccion  para la entrada por teclado
		if ($3->escons==0) //no es una constante y la podemos leer   
		{
		if($3->tipo==1){	
		scanf("%f",&auxn);
		$3->valnum=auxn;
		}
		else if($3->tipo==3)
		{
		scanf("%d",&auxb);
		$3->valbool=auxb;
		}
		else if($3->tipo==6)
		{
		scanf("%d",&auxint);
		$3->valint=auxint;
		}
		else if($3->tipo==2)
		{						
		scanf("%s",auxc);
		strcpy($3->valstr,auxc);
		}
		else 
		printf("Error: No se puede leer, variable no declarada\n");
	}
	else 
	printf("Error: No podemos leer una constante\n");
	}
	;
//////////////////////////////////////////////////////////////////////////////////////////////////

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
	printf("Error: Operaciones sobre tipos diferentes\n");
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
		printf("Error: Operaciones sobre tipos diferentes\n");
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
		printf("Error: Operaciones sobre tipos diferentes\n");
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
			printf("Error: Operaciones sobre tipos diferentes\n");
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
		printf("Error: Operaciones sobre tipos diferentes\n");
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
			printf("Error: Operaciones sobre tipos diferentes\n");
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
	else printf("Error: Operaciones sobre tipos diferentes\n"); 
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

		else printf("Error: Operaciones sobre tipos diferentes\n"); 
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

	else printf("Error: Operaciones sobre tipos diferentes\n"); 
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

	else printf("Error: Operaciones sobre tipos diferentes\n");                                  
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

	else printf("Error: Operaciones sobre tipos diferentes\n");                                  
	}


/*************************************************************************************************/
	|    exp TK_AND exp
	//operacion a nivel de booleanos, and true and true devuelve true otro false

	{
	strcat($$.trad," && ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);

	if (($1.tipo==3) && ($3.tipo==3))
	{
	$$.tipo=3;
	$$.valbool = $1.valbool && $3.valbool;
	}
	else printf("Error: Operaciones sobre tipos diferentes\n");
	}   

/*************************************************************************************************/
	|    exp TK_OR exp
	//operacion a nivel de booleanos, or false or false devuelve false otro true
	{
	strcat($$.trad," || ");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$3.trad);

	if (($1.tipo==3) && ($3.tipo==3))
	{
		$$.tipo=3;
		$$.valbool = $1.valbool || $3.valbool;
	}
	else printf("Error: Operaciones sobre tipos diferentes\n");
	}   

/*************************************************************************************************/
	|    TK_NOT exp
	//operacion a nivel de booleanos, not notfalse=true  not true devuelve false otro true

	{
	strcpy($$.trad," !");//introducimos la cadena creada para la traduccion
	strcat($$.trad,$2.trad);

	if ($2.tipo==3) 
	{
		$$.tipo=3;
		$$.valbool = !$2.valbool;
	}
	else printf("Error: Operaciones sobre tipos diferentes\n");	
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
		strcpy($$.valstr,$1->valstr);//strign
		strcpy($$.cad,$1->cad);//cadena, esto es por los identificadores de las constantes
		$$.valnum=$1->valnum;	//variable numerica
		$$.valbool=$1->valbool;//variable de tipo booleano
		$$.tipo=$1->tipo;//tipo de la variable
		$$.escons=$1->escons; //Nos dice si es una cosntante o no                    
		$$.vis=$1->aux;//para traducir la visualizacion
	}
/*************************************************************************************************/
//Esto es una cosntante de tipo cadena
	| TK_CADENA
	{
		$$.tipo=$1.tipo;
		strcpy($$.cad,$1.cad);
		$$.escons=$1.escons;
	}
	;	      				
%%
//////////////////////////////////////////////////////////////////////////////////////////////////
//Main, dónde se genera el fichero


int main(int argc, char **argv)
{     	
	if(argc==1) {
		printf("Se debe introducir: anal [fichero a analizar]\n\n");
		exit(0);
	}//no se han introducido los parametros correctos	
	extern yyin;//se importa la variable yyin de lex        
	yyin = fopen (argv[1],"r");
	
	salida=fopen("salida.c","w");//creamos el fichero de salida de la traduccion
	salida=fopen("salida.c","a+"); //abrimos en modo para añadir
	yyparse();
	return 0;
	fclose(salida);//se cierra el fichero de salida
}
