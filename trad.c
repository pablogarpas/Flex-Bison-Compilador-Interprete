//Buscar e introducir en la lista de simbolos
NODO *buscar_simbolo(char nombre[20],NODO **com,NODO **fin)
{
	//variables
	NODO *nuevo,*aux, *retorno;
	aux=*com;//comienzo
	int encontrado=0;
	
	while ((aux!=NULL)&&(encontrado==0)&&(aux->tipo!=5))
	{
			
		if (strcmp(aux->nombre,nombre)==0)//El símbolo existe
		{
      (encontrado=1);
			retorno=aux;
			return retorno;//Devolver nodo
		}
	 aux=aux->sig;
	}
	if (!(nuevo=(NODO *)malloc(sizeof (NODO)))&&(encontrado!=1))
	{
		printf("No se ha podido reservar memoria \n");
		exit(0);
	}
    
	strcpy(nuevo->nombre,nombre);//Nombre
	nuevo->tipo=0;//Tipo génerico
	if ((*com==NULL))
	{
		(nuevo->sig)=NULL;
		*com=nuevo;
		*fin=nuevo;
		retorno=*com;
		return (retorno);
	}
	else
	{
		if (encontrado==0)
		{
			(nuevo->sig)=NULL;			
			(*fin)->sig=nuevo;
			*fin=nuevo;
			retorno=*fin;
			return(retorno);
		}
	}
}
//Introducir sin buscar si existe
NODO *introducir(NODO *var,NODO **com,NODO **fin) {
	//variables
	NODO *nuevo,*aux, *retorno,*nuevo1;
	aux=*com;//comienzo

	nuevo1=(NODO *)malloc(sizeof (NODO));

	if (!(nuevo=(NODO *)malloc(sizeof (NODO))))
	{
		printf("No se ha podido reservar memoria \n");
		exit(0);
	}
  
	nuevo=var;
	
	if(nuevo->esarray) {
		nuevo1->tipo=nuevo->tipo;
		nuevo->tipo=2;
		nuevo->array=nuevo1;
	}
	
	
	if (*com==NULL)
	{
		nuevo->sig=NULL;
		*com=nuevo;
		*fin=nuevo;
	}
	else
	{
		(nuevo->sig)=NULL;			
		(*fin)->sig=nuevo;
		*fin=nuevo;
	}
}

//Introducir los argumentos
NODO *introducir_arg(NODO *var,NODO **com,NODO **fin) {
	//variables
	NODO *nuevo,*aux, *retorno;
	aux=*com;//comienzo


	if (!(nuevo=(NODO *)malloc(sizeof (NODO))))
	{
		printf("No se ha podido reservar memoria \n");
		exit(0);
	}
  
	nuevo=var;
	
	if (*com==NULL)
	{
		nuevo->sig=NULL;
		*com=nuevo;
		*fin=nuevo;
	}
	else
	{
		(nuevo->sig)=*com;
		*com=nuevo;
		
	}
}

//Busca y devuelve el número de argumentos de una función
int contar_arg(NODO **com,NODO **fin,char funcion[25]) {
	//variables
	NODO *aux;
	aux=*com;//comienzo
	int encontrado=0;
	
	while(aux!=NULL){
		if(strcmp(aux->nombre,funcion)==0){
			aux=aux->sig;
			break;
		}
		aux=aux->sig;
	}
	
	while ((aux!=NULL)&&(aux->tipo!=5)) {
		if(aux->esarg)
			encontrado++;

		aux=aux->sig;
	}
	
	return encontrado;
}

//Contar el numero de variables locales de una funcion
int contar(NODO **com,NODO **fin,char funcion[25]) {
	//variables
	NODO *aux;
	aux=*com;//comienzo
	int encontrado=0;
		
	while(aux!=NULL){
		if(strcmp(aux->nombre,funcion)==0){
			aux=aux->sig;
			break;
		}
		aux=aux->sig;
	}
	
	while (aux!=NULL&&aux->tipo!=5) {
			encontrado++;

		aux=aux->sig;
	}
	
	return encontrado;
}

//Buscar si la variable existe
NODO *buscar(char nombre[20],NODO **com,NODO **fin,char funcion[25]) {
	//variables
	NODO *nuevo,*aux, *retorno;
	aux=*com;//comienzo
	int encontrado=0;
	char msj[255];
	
	while(aux!=NULL){
		if(strcmp(aux->nombre,funcion)==0){
			aux=aux->sig;
			break;
		}
		aux=aux->sig;
	}
	
	while ((aux!=NULL)&&(encontrado==0)&&(aux->tipo!=5)) {
		encontrado=(strcmp(aux->nombre,nombre))==0;
		if(encontrado) {
			retorno=aux;
			return retorno;//Devolver nodo
		}
		aux=aux->sig;
	}
	

	
	if(encontrado==0){
		strcpy(msj,"Error en las variables, la variable ");
		strcat(msj,nombre);
		strcat(msj," no existe");

		yyerror(msj);	
	}
}

//Buscar la funcion en la tabla de simbolos para delimitar variables locales
NODO *buscar_fun(char nombre[20],NODO **com,NODO **fin) {
	//variables
	NODO *aux, *retorno;
	aux=*com;//comienzo
	int encontrado=0;
	

	
	while ((aux!=NULL)&&(encontrado==0)) {
	
		encontrado=(strcmp(aux->nombre,nombre))==0;
		if(encontrado && (aux->tipo==5)) {
			retorno=aux;
			return retorno;//Devolver nodo
		}
		aux=aux->sig;
	}
}

//Muestra una lista de variables
void listar(NODO **com) {
	NODO *aux,*aux2;
	aux=*com;//comienzo
	
	printf("/////////////////////////////////////////////////////////////////////\n");
	while(aux!=NULL) {
		printf("%s\t%d",aux->nombre,aux->tipo);
		if(aux->esarray) {
			aux2=aux->array;
			while(aux2!=NULL) {
				printf("\t%d %d",aux2->tipo);
				aux2=aux2->array;
			}
		}
		printf("\n");
		aux=aux->sig;
	}
	printf("/////////////////////////////////////////////////////////////////////\n");
}

//recorre la lista
int recorrer(NODO **com,char *nombre,char *funcion) {
	//variables
	NODO *nuevo,*aux;
	aux=*com;//comienzo
	int encontrado=0;
	
	while(aux!=NULL){
		if(strcmp(aux->nombre,funcion)==0){
			aux=aux->sig;
			break;
		}
		aux=aux->sig;
	}
	
	while ((aux!=NULL)&&(encontrado==0)&&(aux->tipo!=5)) {
		encontrado=(strcmp(aux->nombre,nombre))==0;
		if(encontrado) {
			return 1;
		}
		aux=aux->sig;
	}
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////
/*Funciones para pasar del pseudo a C*/
//////////////////////////////////////////////////////////////////////////

//Main del programa
char *intr_cabecera()
{
	char *aux = malloc(255);
   
  strcpy(aux,"int main() \n{\n");
  
  return aux;
}

//Librerias
char *intr_lib(char *nombre)
{
	char *aux = malloc(255);
	
	strcpy(aux,"#include <");
	strcat(aux,nombre);
	strcat(aux,"> \n");
	
	return aux;
}

//Constantes
char *intr_const_num(double num,char *nombre)
{
	char *aux = malloc(256);
	
	strcpy(aux,"#define ");
	strcat(aux,nombre);
	strcat(aux," ");
	fprintf(aux,"%f",num);
	strcat(aux,"\n");
	
	return aux;
}

//Constantes
char *intr_const_int(int num,char *nombre)
{
	char *aux = malloc(256);
	
	strcpy(aux,"#define ");
	strcat(aux,nombre);
	strcat(aux," ");
	fprintf(aux,"%f",num);
	strcat(aux,"\n");
	
	return aux;
}

//Cadenas
char *intr_const_cad(char *cad,char *nombre)
{
	char *aux = malloc(256);
	
	strcpy(aux,"#define ");
	strcat(aux,nombre);
	strcat(aux," \"");
	strcat(aux,cad);
	strcat(aux,"\"\n");
	
	return aux;
}

//Variables
char *intr_variable(int tipo, char *nombre,int esarray,char *indice)
{
	char *aux = malloc(256);

	switch(tipo) {
		case 1:
			strcpy(aux,"float ");
			strcat(aux,nombre);
			if(esarray) {
				strcat(aux,"[");
				strcat(aux,indice);
				strcat(aux,"]");
			}
			strcat(aux,";\n");
			break;
		case 3:
			strcpy(aux,"int ");
			strcat(aux,nombre);
			if(esarray) {
				strcat(aux,"[");
				strcat(aux,indice);
				strcat(aux,"]");
			}
			strcat(aux,";\n");
			break;
		case 4:
			strcpy(aux,"char *");
			strcat(aux,nombre);
			if(esarray) {
				strcat(aux,"[");
				strcat(aux,indice);
				strcat(aux,"]");
			}
			strcat(aux,";\n");
			break;
		case 6:
			strcpy(aux,"int ");
			strcat(aux,nombre);
			if(esarray) {
				strcat(aux,"[");
				strcat(aux,indice);
				strcat(aux,"]");
			}
			strcat(aux,";\n");
			break;
		}
	
	return aux;
}

//Variables
char *intr_argumento(int tipo, char *nombre,int esarray)
{
	char *aux = malloc(256);

	switch(tipo) {
		case 1:
			strcpy(aux,"float ");
			if(esarray) 
				strcat(aux,"*");
			else
				strcat(aux,"");
			strcat(aux,nombre);
			break;
		case 2:
			strcpy(aux,"char ");
			if(esarray) 
				strcat(aux,"**");
			else
				strcat(aux,"*");
			strcat(aux,nombre);
			break;
		case 3:
			strcpy(aux,"int ");
			if(esarray)
				strcat(aux,"*");
			else
				strcat(aux,"");
			strcat(aux,nombre);
			break;
		case 4:
			strcpy(aux,"char ");
			if(esarray) 
				strcat(aux,"**");
			else
				strcat(aux,"*");
			strcat(aux,nombre);
			break;
		case 6:
			strcpy(aux,"int ");
			if(esarray)
				strcat(aux,"*");
			else
				strcat(aux,"");	
			strcat(aux,nombre);
			break;
		}
	
	return aux;
}

//Salida
void vis_salida(int tipo,char *cad, int vis)
{
	switch(tipo){
		case 1:fprintf(salida,"printf(\" %%f \",%s);\n",cad);break;
		case 2:fprintf(salida,"printf(\" %%s \",%s);\n",cad);break;
		case 3:fprintf(salida,"printf(\" %%d \",%s);\n",cad);break;
		case 6:fprintf(salida,"printf(\" %%d \",%s);\n",cad);break;		
		case 4:if (vis==3)
					{
					fprintf(salida,"printf(\" %%s \",%s);\n",cad);break;}
					else
					{fprintf(salida,"printf(%s);\n",cad);break;}
					}
}


//Salida por pantalla
void vis_salida_sl(int tipo,char *cad, int vis)
{
	switch(tipo){
		case 1:fprintf(salida,"printf(\" %%f \\n\",%s);\n",cad);break;
		case 2:fprintf(salida,"printf(\" %%s \\n\",%s);\n",cad);break;
		case 3:fprintf(salida,"printf(\" %%d \\n\",%s);\n",cad);break;	
		case 6:fprintf(salida,"printf(\" %%d \\n\",%s);\n",cad);break;	
		case 4:if (vis==3)
			fprintf(salida,"printf(\" %%s \",%s);\n",cad);
			     else
			fprintf(salida,"printf(%s);\n",cad);
			fprintf(salida,"printf(\"\\n\");\n",cad);break;
		}
}


//Entrada por teclado
char *vis_entrada(int tipo,char *cad,int esarray,char *indice)
{
	
	char *aux = malloc(256);
	
	strcpy(aux,"scanf(\"");	
		
	switch(tipo) {
		case 1:
			strcat(aux,"%%f \",");
			if(!esarray) {
				strcat(aux,"&");
				strcat(aux,cad);	
				strcat(aux,");\n");	
			}
			else {
				strcat(aux,"&");
				strcat(aux,cad);	
				strcat(aux,"[");	
				strcat(aux,indice);	
				strcat(aux,"]");	
				strcat(aux,");\n");	
			}
			break;
		case 3:
			strcat(aux,"%%d \",");
			if(!esarray) {
				strcat(aux,"&");
				strcat(aux,cad);	
				strcat(aux,");\n");	
			}
			else {
				strcat(aux,"&");
				strcat(aux,cad);	
				strcat(aux,"[");	
				strcat(aux,indice);	
				strcat(aux,"]");	
				strcat(aux,");\n");	
			}
			break;
		case 4:
			strcat(aux,"%%s \",");
			if(!esarray) {
				strcat(aux,"&");
				strcat(aux,cad);	
				strcat(aux,");\n");	
			}
			else {
				strcat(aux,"&");
				strcat(aux,cad);	
				strcat(aux,"[");	
				strcat(aux,indice);	
				strcat(aux,"]");	
				strcat(aux,");\n");	
			}
			break;
		case 6:
			strcat(aux,"%%d \",");
			if(!esarray) {
				strcat(aux,"&");
				strcat(aux,cad);	
				strcat(aux,");\n");	
			}
			else {
				strcat(aux,"&");
				strcat(aux,cad);	
				strcat(aux,"[");	
				strcat(aux,indice);	
				strcat(aux,"]");	
				strcat(aux,");\n");	
			}
			break;
		default:
			yyerror("variable a leer no declarada");
			break;
		}
	

		
	return aux;
	
}

//Salida de expresiones
void vis_exp(int tipo,char *cad)
{
	fprintf(salida,"%s",cad);
}

//Función para traducir incrementos con comprobación de post o pre incremento
void intr_inc(char *nombre,int post)
{
	if(post)
		fprintf(salida,"%s++;\n",nombre);
	else
		fprintf(salida,"++%s;\n",nombre);
}

//////////////////////////////////////////////////////////////////////////
/*Funciones para la compilación*/
//////////////////////////////////////////////////////////////////////////
//Insertar o crear el árbol
int insertar(NODO expre1,NODO expre2, int ope, NODO *var)
{
	ARBOL *aux,*aux2;
	
	aux2= malloc(sizeof(ARBOL));
	aux= malloc(sizeof(ARBOL));

	if(aux==NULL)	{
	 printf("Error. No hay memoria para otro ARBOL.");
	 return 0;
	}
	else {
		aux->exp1=expre1;		
		aux->exp2=expre2;
		aux->op=ope;
		aux->var=var;
		aux->izq=NULL;
		
		if(INICIO==NULL) {
			INICIO=aux;
			FINAL=aux;
			aux->der=NULL;
			aux->raiz=NULL;
		}
		else if(FINAL->op==PLACEHOLDER) {
			aux->izq=FINAL->izq;
			aux->raiz=FINAL->raiz;
			*FINAL=*aux;
			
			aux2->op=PLACEHOLDER;
			FINAL->der=aux2;
			aux2->raiz=FINAL;
			FINAL=aux2;
			aux2->der=NULL;
		}
		else {
			FINAL->der=aux;
			aux->raiz=FINAL;
			FINAL=aux;
			aux->der=NULL;
		}
	}
}

//Insertar expresión en el arbol
int insertarexp(NODO expre1,NODO expre2, int ope) {

	ARBOL *aux,*aux2,*aux3;
	aux= malloc(sizeof(ARBOL));
	aux2= malloc(sizeof(ARBOL));
	
	
	if(aux2==NULL|| aux==NULL)	{
	 printf("Error. No hay memoria para otro ARBOL.");
	 return 0;
	}else if(INICIO==NULL){
		INICIO=aux2;
		FINAL=aux2;


		aux->exp1=expre1;
		aux->exp2=expre2;
		aux->op=ope;
		
		aux2->op=PLACEHOLDER;
		aux2->izq=aux;
		
	}
	else if(FINAL->izq!=NULL) {
		if(FINAL->der!=NULL) {
			printf("%d\n",ope);
			}
		
		aux->exp1=expre1;
		aux->exp2=expre2;
		aux->op=ope;
		aux->izq=NULL;
		aux2=FINAL;

		do{
			aux3=aux2;
			aux2=aux2->izq;

		}while(aux2!=NULL);

		aux3->izq=aux;

	}
	else {
		aux->exp1=expre1;
		aux->exp2=expre2;
		aux->op=ope;
		
		aux2->raiz=FINAL;
		FINAL->der=aux2;
		FINAL=FINAL->der;
		FINAL->op=PLACEHOLDER;
		FINAL->izq=aux;
		}
	
}

//Se inserta un nodo para en el arbol
int insertar_para(NODO expre1,NODO expre2, int ope, NODO *var) { 
	ARBOL *aux;
	
	aux= malloc(sizeof(ARBOL));

	if(aux==NULL)	{
	 printf("Error. No hay memoria para otro ARBOL.");
	 return 0;
	}
	else {
		aux->exp1=expre1;		
		aux->exp2=expre2;
		aux->op=ope;
		aux->var=var;
		aux->izq=NULL;
		
		strcpy(aux->exp1.nombre,var->nombre);
		
		if(INICIO==NULL) {
			INICIO=aux;
			FINAL=aux;
			aux->der=NULL;
			aux->raiz=NULL;
		}
		else if(FINAL->op==PLACEHOLDER) {
			aux->izq=FINAL->izq;
			aux->raiz=FINAL->raiz;
			*FINAL=*aux;
		}
		else {
			FINAL->der=aux;
			aux->raiz=FINAL;
			FINAL=aux;
			aux->der=NULL;
		}
	}
}

//Función para copiar los datos de un elemento a un nodo
void copiardatos(NODO *a, int tipo,int escons,int esarray,char *valstr,int valbool,float valnum,int valint,char *nombre, int esarg,int indice) {
	a->tipo=tipo;
	a->escons=escons;
	a->esarray=esarray;
	strcpy(a->valstr,valstr);
	a->valbool=valbool;
	a->valnum = valnum;
	a->valint = valint;
	strcpy(a->nombre,nombre);
	a->esarg=esarg;
	a->aux=indice;
}

//Inserta una funcion en el árbol
int insertar_fun(NODO *var, int ope) { 
	ARBOL *aux,*aux2;
	
	aux= malloc(sizeof(ARBOL));
	aux2= malloc(sizeof(ARBOL));

	if(aux==NULL||aux2==NULL)	{
	 printf("Error. No hay memoria para otro ARBOL.");
	 return 0;
	}
	else {
		strcpy(aux->exp1.nombre,var->nombre);
		aux->op=ope;
		
		if(INICIO==NULL) {
			INICIO=aux2;
			FINAL=aux2;
			aux2->izq=aux;
		}else if(INICIO->izq!=NULL) {
			aux2=INICIO;
			do{
				aux2=aux2->izq;
			}while(aux2->izq!=NULL);
			aux2->izq=aux;
			FINAL=aux;
		}else {
			INICIO->izq=aux;
			aux->raiz=INICIO;
			FINAL=aux;
			aux->der=NULL;
		}
	}
}
