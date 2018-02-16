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
void intr_cabecera()
{
   fprintf(salida,"int main() \n{\n");
}

//Librerias
void intr_lib(char *nombre)
{
	fprintf(salida,"#include <%s> \n",nombre);
}

//Constantes
void intr_const_num(double num,char *nombre)
{
	fprintf(salida,"#define %s %f\n",nombre,num);
}

//Constantes
void intr_const_int(int num,char *nombre)
{
	fprintf(salida,"#define %s %d\n",nombre,num);
}

//Cadenas
void intr_const_cad(char *cad,char *nombre)
{
	fprintf(salida,"#define %s \"%s\"\n",nombre,cad);
}


//Variables
void intr_variable(int tipo, char *nombre,int espun)
{
	switch(tipo){
		case 1:
			if(espun)
				fprintf(salida,"float *%s;\n",nombre);
			else
				fprintf(salida,"float %s;\n",nombre);	
			break;
		case 2:
			if(espun)
				fprintf(salida,"char **%s;\n",nombre);
			else
				fprintf(salida,"char *%s;\n",nombre);
			break;
		case 3:
			if(espun)
				fprintf(salida,"int *%s;\n",nombre);
			else
				fprintf(salida,"int %s;\n",nombre);
			break;
		case 6:
			if(espun)
				fprintf(salida,"int *%s;\n",nombre);
			else
				fprintf(salida,"int %s;\n",nombre);
			break;	
		}
}


//Asignaciones
void intr_sentencia(char *nombre,char *trad,int aux1,int aux2)
{
	if (aux1==0 && aux2==0)
		fprintf(salida,"%s=%s;\n",nombre,trad);
	if (aux1==2 && aux2==0)
		fprintf(salida,"*%s=%s;\n",nombre,trad);
	if (aux1==0 && aux2==2)
		fprintf(salida,"%s=*%s;\n",nombre,trad);
	if (aux1==2 && aux2==2)
		fprintf(salida,"*%s=*%s;\n",nombre,trad);
	if (aux1==2 && aux2==3)
		fprintf(salida,"*%s=&%s;\n",nombre,trad);
	if (aux1==3 && aux2==2)
		fprintf(salida,"&%s=*%s;\n",nombre,trad);
	if (aux1==3 && aux2==3)
		fprintf(salida,"&%s=&%s;\n",nombre,trad);
	if (aux1==0 && aux2==3)
		fprintf(salida,"%s=&%s;\n",nombre,trad);
	if (aux1==3 && aux2==0)
		fprintf(salida,"&%s=%s;\n",nombre,trad);
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
void vis_entrada(int tipo,char *cad)
{
	switch(tipo){
		case 1:fprintf(salida,"scanf(\" %%f \",&%s);\n",cad);break;
		case 2:fprintf(salida,"scanf(\" %%s \",&%s);\n",cad);break;
		case 3:fprintf(salida,"scanf(\" %%d \",&%s);\n",cad);break;
		case 6:fprintf(salida,"scanf(\" %%d \",&%s);\n",cad);break;		
		}
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
