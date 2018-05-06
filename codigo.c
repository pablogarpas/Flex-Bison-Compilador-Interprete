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

//Función para traducir decrementos con comprobación de post o pre decremento
void intr_dec(char *nombre,int post)
{
	if(post)
		fprintf(salida,"%s++;\n",nombre);
	else
		fprintf(salida,"++%s;\n",nombre);
}

//Comprobación para las estructuras de control
int ejecutar(int pos,int array[]) {
	int i;
	int aux=1;
	
	for(i=0;i<=pos;i++) {
		if(!array[i])
			aux=0;
	}
	return aux;
}
