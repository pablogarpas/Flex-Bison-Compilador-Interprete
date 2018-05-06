#include <stdio.h>
//Estructura para la lista de símbolos

//0->id
//1->real;
//2->string;
//3->bool;
//4->cadena;
//5->tipo generico;
//6->entero;

//tipo de los simbolos
typedef struct NODO {
  int tipo; //tipo asociado
	int escons; //nos dice si es o no constante 1->si 0->no
	int espun; //nos dice si es o no puntero 1->si 0->no
	char nombre[255]; //nombre de la variable o constante
	int valbool; //valor que se toma si el tipo es booleano
	union {
    double valnum; //valor que se toma si el tipo es numérico
    int    valint; //valor que se toma si el tipo es entero
    char   cad[255]; //valor para las cadenas constantes
    char   valstr[255]; //valor que se toma si el tipo es una cadena de tipo string
  };//union
	int aux; //variable para visualizar las constantes cadena correctamente	
  struct NODO *sig; //puntero que a punta al siguiente nodo
}NODO;

//Manejador para el fichero de salida
FILE *salida;

//Buscar y añadir
NODO *buscar_simbolo(char *nombre,NODO **com,NODO **fin);

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

//Función para traducir decrementos con comprobación de post o pre decremento
void intr_dec(char *nombre,int post);

//Comprobación para las estructuras de control
int ejecutar(int pos,int array[]);
