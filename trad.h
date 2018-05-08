#include <stdio.h>
//Estructura para la lista de símbolos

//0->id
//1->real;
//2->string;
//3->bool;
//4->cadena;
//5->tipo generico;
//6->entero;

#define PLACEHOLDER 0
#define OP_ESCRIBIR 1
#define OP_ASIGNAR 2
#define OP_IGUALDAD 3
#define OP_NOT 4
#define OP_OR 5
#define OP_AND 6
#define OP_DESIGUALDAD 7
#define OP_MAYOR 8
#define OP_MENOR 9
#define OP_MEI 10
#define OP_MAI 11
#define OP_SUMA 12
#define OP_RESTA 13
#define OP_MULT 14
#define OP_DIV 15
#define OP_CAM 16
#define OP_POW 17
#define OP_MOD 18
#define OP_INC 19
#define OP_DEC 20
#define OP_SI 21
#define OP_FIN 22


//tipo de los simbolos
typedef struct NODO {
  int tipo; //tipo asociado
	int escons; //nos dice si es o no constante 1->si 0->no
	int espun; //nos dice si es o no puntero 1->si 0->no
	char nombre[255]; //nombre de la variable o constante
	int valbool; //valor que se toma si el tipo es booleano
  double valnum; //valor que se toma si el tipo es numérico
  int    valint; //valor que se toma si el tipo es entero
  char   cad[255]; //valor para las cadenas constantes
  char   valstr[255]; //valor que se toma si el tipo es una cadena de tipo string
	int aux; //variable para visualizar las constantes cadena correctamente	
  struct NODO *sig; //puntero que a punta al siguiente nodo
}NODO;

//Manejador para el fichero de salida
FILE *salida;

//Buscar y añadir
NODO *buscar_simbolo(char *nombre,NODO **com,NODO **fin);
//Buscar y devolver un nodo a esa variable
NODO **buscar(char *nombre,NODO **com,NODO **fin);

typedef struct ARBOL{
	struct ARBOL *der;
	struct ARBOL *cen;
	struct ARBOL *izq;
	struct ARBOL *raiz;
	
	NODO exp1;
	NODO exp2;
	int op;
	
	NODO *var;
	NODO *var2;
}ARBOL;

ARBOL *INICIO;
ARBOL *FINAL;



//////////////////////////////////////////////////////////////////////////
/*Funciones para pasar del pseudo a C*/
//////////////////////////////////////////////////////////////////////////

//Main del programa
char *intr_cabecera();

//Librerias
char* intr_lib(char *nombre);

//Constantes
char *intr_const_num(double num,char *nombre);

//Constantes
char *intr_const_int(int num,char *nombre);

//Candenas
char *intr_const_cad(char *cad,char *nombre);

//Variables
char *intr_variable(int tipo, char *nombre, int espun); 

//Variables
char *intr_argumento(int tipo, char *nombre, int espun); 

//Salida por pantalla
void vis_salida(int tipo,char *cad, int vis);

//Salida por pantalla
void vis_salida_sl(int tipo,char *cad, int vis);

//Entrada por pantalla
char *vis_entrada(int tipo,char *cad,int espun);

//Salidas expresiones
void vis_exp(int tipo,char *cad);

//Función para traducir incrementos con comprobación de post o pre incremento
void intr_inc(char *nombre,int post);

//////////////////////////////////////////////////////////////////////////
/*Funciones para la compilación*/
//////////////////////////////////////////////////////////////////////////
//Pasar de elemento a nodo
void copiardatos(NODO *a, int tipo,int escons,int espun,char *valstr,int valbool,float valnum,int valint,char *nombre);
//Crear el árbol o añadir nodo
int insertar(NODO expre1,NODO expre2, int ope, NODO *var);

//Insertar expresión en el hijo izquierdo del arbol
int insertarexp(NODO expre1,NODO expre2, int ope);
