//Buscar e introducir en la lista de simbolos
NODO *buscar_simbolo(char nombre[20],NODO **com,NODO **fin)
{
	//variables
	NODO *nuevo,*aux, *retorno;
	aux=*com;//comienzo
	int encontrado=0;
	
	while ((aux!=NULL)&&(encontrado==0))
	{
		if (strcmp(aux->nombre,nombre)==0)//El símbolo existe
		{
      (encontrado=1);
			retorno=aux;
			return(retorno);//Devolver nodo
		}
	 aux=aux->sig;
	}

	if (!(nuevo=(NODO *)malloc(sizeof (NODO)))&&(encontrado!=1))
	{
		printf("No se ha podido reservar memoria \n");
		exit(0);
	}
    
	strcpy(nuevo->nombre,nombre);//Nombre
	nuevo->tipo=6;//Tipo génerico
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
			(nuevo->sig)=*com;			
			*com=nuevo;
			retorno=*com;
			return(retorno);
		}
	}
}

//Buscar e introducir en la lista de simbolos
NODO *introducir(char nombre[20],NODO **com,NODO **fin)
{
	//variables
	NODO *nuevo,*aux, *retorno;
	aux=*com;//comienzo

	if (!(nuevo=(NODO *)malloc(sizeof (NODO))))
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
		(nuevo->sig)=NULL;			
		(*fin)->sig=nuevo;
		*fin=nuevo;
		retorno=*fin;
		return(retorno);
	}
}

NODO *introducir_delim(char *nombre,NODO **com,NODO **fin) {
	//variables
	NODO *nuevo,*aux, *retorno;
	aux=*com;//comienzo

	if (!(nuevo=(NODO *)malloc(sizeof (NODO))))
	{
		printf("No se ha podido reservar memoria \n");
		exit(0);
	}
  
	strcpy(nuevo->nombre,nombre);//Nombre
	nuevo->tipo=5;//Tipo génerico
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
		(nuevo->sig)=NULL;			
		(*fin)->sig=nuevo;
		*fin=nuevo;
		retorno=*fin;
		return(retorno);
	}
}

NODO *buscar(char nombre[20],NODO **com,NODO **fin)
{
	//variables
	NODO *nuevo,*aux, *retorno;
	aux=*com;//comienzo
	int encontrado=0;
	char msj[255];
	
	while ((aux!=NULL)&&(encontrado==0))
	{
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

void listar(NODO **com) {

	NODO *aux;
	aux=*com;//comienzo
	
	
	while(aux!=NULL) {
		//if(aux->tipo!=0)
			printf("%s\t%d\n",aux->nombre,aux->tipo);
		aux=aux->sig;
	}
}

void revisar(NODO **com) {
	int error=0;
	NODO **aux;
	char msj[255];
	
	limpiar(com);
	
	aux=com;//comienzo
	
	while(*aux!=NULL) {
		while((*aux)->tipo!=5) {
			error=recorrer(com,(*aux)->nombre);
			if(error){
				strcpy(msj,"Error en las variables, la variable ");
				strcat(msj,(*aux)->nombre);
				strcat(msj," está repetida");
				
				yyerror(msj);	
			}
			*aux=(*aux)->sig;
		}
		*aux=(*aux)->sig;
	}
}

//recorre la lista
int recorrer(NODO **com,char *nombre) {
	NODO *aux;
	aux=*com;//comienzo
	int encontrado;
	aux=aux->sig;
	
	while(aux->sig!=NULL) {
		if(aux->tipo==5)
			return encontrado;
		if(strcmp(nombre,aux->nombre)==0) {
			encontrado=1;
			return encontrado;
			}
		aux=aux->sig;
	}
	return encontrado;
}

//Función para eliminar las variables que sobran de la lista
void limpiar(NODO **com) {
	NODO *aux,*aux2;
	aux=*com;//comienzo

	while(aux!=NULL) {
		if((*com)->tipo==0) { 
			aux2=*com;
			*com=(*com)->sig;
			free(aux2);
			aux=*com;
		}else if(aux->tipo==0) { 
			aux2->sig=aux->sig;
			free(aux);
			aux=aux2->sig;
		}else {
			aux2=aux;
			aux=aux->sig;
		}
	}
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
char *intr_variable(int tipo, char *nombre,int espun)
{
	char *aux = malloc(256);

	switch(tipo) {
		case 1:
			strcpy(aux,"float ");
			if(espun) 
				strcat(aux,"*");
			else
				strcat(aux,"");
			strcat(aux,nombre);
			strcat(aux,";\n");
			break;
		case 2:
			strcpy(aux,"char ");
			if(espun) 
				strcat(aux,"**");
			else
				strcat(aux,"*");
			strcat(aux,nombre);
			strcat(aux,";\n");
			break;
		case 3:
			strcpy(aux,"int ");
			if(espun)
				strcat(aux,"*");
			else
				strcat(aux,"");
			strcat(aux,nombre);
			strcat(aux,";\n");
			break;
		case 6:
			strcpy(aux,"int ");
			if(espun)
				strcat(aux,"*");
			else
				strcat(aux,"");	
			strcat(aux,nombre);
			strcat(aux,";\n");
			break;
		}
	
	return aux;
}

//Variables
char *intr_argumento(int tipo, char *nombre,int espun)
{
	char *aux = malloc(256);

	switch(tipo) {
		case 1:
			strcpy(aux,"float ");
			if(espun) 
				strcat(aux,"*");
			else
				strcat(aux,"");
			strcat(aux,nombre);
			break;
		case 2:
			strcpy(aux,"char ");
			if(espun) 
				strcat(aux,"**");
			else
				strcat(aux,"*");
			strcat(aux,nombre);
			break;
		case 3:
			strcpy(aux,"int ");
			if(espun)
				strcat(aux,"*");
			else
				strcat(aux,"");
			strcat(aux,nombre);
			break;
		case 6:
			strcpy(aux,"int ");
			if(espun)
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
char *vis_entrada(int tipo,char *cad,int espun)
{
	
	char *aux = malloc(256);
	
	strcpy(aux,"scanf(\"");	
		
	switch(tipo) {
		case 1:
			strcat(aux,"%%f \",");
			if(!espun) 
				strcat(aux,"&");
			break;
		case 2:
			strcat(aux,"%%s \",");
			if(!espun) 
				strcat(aux,"&");
			break;
		case 3:
			strcat(aux,"%%d \",");
			if(!espun) 
				strcat(aux,"&");
			break;
		case 6:
			strcat(aux,"%%f \",");
			if(!espun) 
				strcat(aux,"&");
			break;
		default:
			yyerror("variable a leer no declarada");
			break;
		}
	
	strcat(aux,cad);	
	strcat(aux,");\n");	
		
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
void copiardatos(NODO *a, int tipo,int escons,int espun,char *valstr,int valbool,float valnum,int valint,char *nombre) {
	a->tipo=tipo;
	a->escons=escons;
	a->espun=espun;
	strcpy(a->valstr,valstr);
	a->valbool=valbool;
	a->valnum = valnum;
	a->valint = valint;
	strcpy(a->nombre,nombre);
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
