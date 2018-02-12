//Buscar e introducir en la lista de simbolos
NODO *buscar_simbolo(char nombre[20],NODO **com,NODO **fin)
{
	//variables
	NODO *nuevo,*aux, *retorno;
	int existe=0;
	aux=*com;//comienzo
	
	while ((aux!=NULL)&&(existe==0))
	{
		if (strcmp(aux->nombre,nombre)==0)//El símbolo existe
		{
		        (existe=1);
			retorno=aux;
			return(retorno);//Devolver nodo
		}
	 aux=aux->sig;
	}

	if (!(nuevo=(NODO *)malloc(sizeof (NODO)))&&(existe!=1))
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
		if (existe==0)
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
   fprintf(salida,"main() \n{\n");
}


//Constantes
void intr_const_num(double num,char *nombre)
{
	fprintf(salida,"#define %s %f\n",nombre,num);
}

//Cadenas
void intr_const_cad(char *cad,char *nombre)
{
	fprintf(salida,"#define %s \"%s\"\n",nombre,cad);
}


//Variables
void intr_variable(int tipo, char *nombre)
{
	switch(tipo){
		case 1:fprintf(salida,"float %s;\n",nombre);break;
		case 2:fprintf(salida,"char *%s;\n",nombre);break;
		case 3:fprintf(salida,"int %s;\n",nombre);break;
		case 6:fprintf(salida,"int %s;\n",nombre);break;	
		}
}


//Asignaciones
void intr_sentencia(char *nombre,char *trad)
{
	fprintf(salida,"%s=%s;\n",nombre,trad);
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
void vis_salida_rc(int tipo,char *cad, int vis)
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
