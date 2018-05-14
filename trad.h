#include <stdio.h>
//Estructura para la lista de símbolos

//0->id
//1->real;
//2->string;
//3->bool;
//4->cadena;
//5->delimitador;
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
#define OP_ELSE 22
#define OP_WHILE 23
#define OP_PARA 24
#define OP_SWITCH 25
#define OP_CASE 26
#define OP_DEFAULT 27
#define OP_LEER 28
#define OP_FIN 30
#define OP_INICIO 31
#define OP_FUN 32
#define OP_LLAMAR 33
#define OP_DECL 34
#define OP_EXIT 35
#define OP_DECL_ARG 36
#define OP_ARG 37
#define OP_RETURN 38
#define OP_DEVOLVER 39

//tipo de los simbolos
typedef struct NODO {
  int tipo; //tipo asociado
	int escons; //nos dice si es o no constante 1->si 0->no
	int espun; //nos dice si es o no puntero 1->si 0->no
	int esarg; //nos dice si es un argumento o no 1->si 0->no
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

NODO *com;
NODO *fin;


//////////////////////////////////////////////////////////////////////////
/*Funciones para la busqueda en la tabla de símbolos*/
//////////////////////////////////////////////////////////////////////////
//Buscar y devolver un nodo a esa variable
NODO *buscar(char nombre[20],NODO **com,NODO **fin,char funcion[25]);
//Buscar y devolver un nodo a esa funcion
NODO *buscar_fun(char nombre[20],NODO **com,NODO **fin);
//Ver la tabla de símbolos
void listar(NODO **com);
//Revisar la tabla de símbolos para buscar fallos
void revisar(NODO **com);
//Recorrer la tabla de símbolos buscando variables repetidas
int recorrer(NODO **com,char *nombre,char *funcion);
//Función para eliminar las variables que sobran de la lista
void limpiar(NODO **com);
//Introducir en la tabla de símbolos
NODO *introducir(NODO *var,NODO **com,NODO **fin);
//Busca y devuelve el número de argumentos de una función
int contar_arg(NODO **com,NODO **fin,char funcion[25]);
//Busca y devuelve el número de elementos de una función
int contar(NODO **com,NODO **fin);
//Función para introducir en orden los argumentos
NODO *introducir_arg(NODO *var,NODO **com,NODO **fin);
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
/*Funciones para el AST*/
//////////////////////////////////////////////////////////////////////////
//Pasar de elemento a nodo
void copiardatos(NODO *a, int tipo,int escons,int espun,char *valstr,int valbool,float valnum,int valint,char *nombre, int esarg);

//Crear el árbol o añadir nodo
int insertar(NODO expre1,NODO expre2, int ope, NODO *var);

//Insertar expresión en el hijo izquierdo del arbol
int insertarexp(NODO expre1,NODO expre2, int ope);

//Inserta un nodo para
int insertar_para(NODO expre1,NODO expre2, int ope, NODO *var);

//Inserta una funcion en el árbol
int insertar_fun(NODO *var, int ope);
