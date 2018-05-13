//Prototipos
int ejecutar(ARBOL *var,int parar);
NODO procesarexp(ARBOL *aux);
//Variables globales
int nivel;//variable para controlar el nivel en el que parar

int ejecutar(ARBOL *var,int parar) {
	ARBOL *aux,*aux2;
	NODO *variable;
	int defecto;
	int encontrada;
	
	aux=var;
	
	/*
	do{
		printf("%d\n",aux->op);
		aux=aux->der;
	}while(aux!=NULL);
	*/	
	
	aux=var;

	
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
						variable=buscar(aux->exp1.nombre,&com,&fin);
						printf("%f\n",variable->valnum);
					}
					break;
				case 2:	
					if(aux->exp1.escons) {
						printf("%s\n",aux->exp1.valstr);
					}
					else {
						variable=buscar(aux->exp1.nombre,&com,&fin);
						printf("%s\n",variable->valstr);
					}
					break;
				case 3:
					if(aux->exp1.escons) {
						printf("%d\n",aux->exp1.valbool);
					}
					else {
						variable=buscar(aux->exp1.nombre,&com,&fin);
						printf("%d\n",variable->valbool);
					}
					break;
				case 4:	
					if(aux->exp1.escons) {
						printf("%s\n",aux->exp1.valstr);
					}
					else {
						variable=buscar(aux->exp1.nombre,&com,&fin);
						printf("%s\n",variable->valstr);
					}
					break;
				case 6: 
					if(aux->exp1.escons) {
						printf("%d\n",aux->exp1.valint);
					}
					else {
						variable=buscar(aux->exp1.nombre,&com,&fin);
						printf("%d\n",variable->valint);
					}
					break;
				default:
					yyerror("Error al mostrar el elemento");
					break;
			}//switch
			break;
		case OP_ASIGNAR:		
			variable=buscar(aux->var->nombre,&com,&fin);
				variable->valnum=variable->valnum+1;
			
			if ((aux->var->tipo==aux->exp1.tipo)&&(aux->var->escons==0)&&(aux->var->espun==0)) {
				variable->tipo=aux->exp1.tipo;
				strcpy(variable->valstr,aux->exp1.valstr);
				variable->valbool= aux->exp1.valbool;
				variable->valnum = aux->exp1.valnum;
				variable->valint = aux->exp1.valint;
			}
			else if((aux->var->tipo=2)&&(aux->exp1.tipo==4)&&(aux->var->escons==0)&&(aux->var->espun==0)) {	
				strcpy(variable->valstr,aux->exp1.valstr);
			}
			else if((aux->var->tipo=1)&&(aux->exp1.tipo==6)&&(aux->var->escons==0)&&(aux->var->espun==0)) {	
				variable->valnum = aux->exp1.valint;
			}
			else if((aux->var->tipo=6)&&(aux->exp1.tipo==1)&&(aux->var->escons==0)&&(aux->var->espun==0)) {	
				variable->valint = aux->exp1.valnum;
			}
			else yyerror("Error en la asignación, no concuerdan los tipos o la variable es constante\n");	
			break;
		case OP_INC:
			if(aux->var->tipo==6) {			
				variable=buscar(aux->exp1.nombre,&com,&fin);
				variable->valint=variable->valint+1;				
			}else if(aux->var->tipo==1) {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				variable->valnum=variable->valnum+1;
			}
			else
			yyerror("Error en el incremento: No se puede incrementar una variable no númerica");
			break;
		case OP_DEC:			
			if(aux->var->tipo==6) {			
				variable=buscar(aux->exp1.nombre,&com,&fin);
				variable->valint=variable->valint-1;				
			}else if(aux->var->tipo==1) {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				variable->valnum=variable->valnum-1;
			}
			else
			yyerror("Error en el incremento: No se puede incrementar una variable no númerica");
			break;
		case OP_SI:		
			parar++;
			nivel++;
			
			if(aux->izq!=NULL) 
				aux->exp1=procesarexp(aux->izq);	
			
			if(aux->exp1.valbool==0) {
				while(aux->op!=OP_ELSE) {
					aux=aux->der;
				}
			}
			break;
		case OP_ELSE:
			while(aux->der->op!=OP_FIN) {
					aux=aux->der;
				}
			break;
		case OP_WHILE:		
			parar++;
			nivel++;
			
			if(aux->izq!=NULL) 
				aux->exp1=procesarexp(aux->izq);
			
			while(aux->exp1.valbool) {
				ejecutar(aux->der,1);
				aux->exp1=procesarexp(aux->izq);
				}
			break;
		case OP_PARA:
			parar++;
			nivel++;
			
			variable=buscar(aux->exp1.nombre,&com,&fin);
		
			variable->valint=aux->exp1.valint;
		
			while(variable->valint!= aux->exp2.valint) {
				ejecutar(aux->der,1);
				
				if(aux->exp1.valint < aux->exp2.valint)
					variable->valint++;
				if(aux->exp1.valint > aux->exp2.valint)
					variable->valint--;
			}
			break;
		case OP_SWITCH:
			parar++;
			nivel++;
					
			variable=buscar(aux->exp1.nombre,&com,&fin);
		
			while(aux->der->op!=OP_FIN) {
				if(aux->der->op==OP_DEFAULT) {
					if(defecto==0)
						ejecutar(aux,1);	
				}
			
				if(aux->der->op==OP_CASE && aux->der->exp1.valint==variable->valint) {
					ejecutar(aux,1);
					defecto=1;
				}
					
				aux=aux->der;
			}
			defecto=0;
			break;
		case OP_FIN:
			if(parar==nivel) {
				return 1;
				nivel++;
			}
			break;
		case OP_CASE:
			if(parar==nivel) {
				return 1;
				nivel++;
			}
			break;
		case OP_DEFAULT:
			if(parar==nivel) {
				return 1;
				nivel++;
			}
			break;
		case OP_LEER:
			variable=buscar(aux->var->nombre,&com,&fin);
			
			if(variable->tipo==4 || variable->tipo==2)
				fgets(variable->valstr,255,stdin);
			else if(variable->tipo==6) {
			printf("asd\n");fflush(stdout);
				scanf("%d",&(variable->valint));
				}
			else if(variable->tipo==3)
				scanf("%d",&(variable->valbool));
			else if(variable->tipo==1)
				scanf("%lf",&(variable->valnum));
			else
				yyerror("Error al leer: tipo no reconocido");
			break;
		case OP_LLAMAR:
			aux2=INICIO;

			while(aux2->izq!=NULL) {
				aux2=aux2->izq;
				
				if(strcmp(aux2->exp1.nombre,aux->exp1.nombre)==0)
					encontrada=1;		
					
				if(encontrada)
					break;
			}
			if(encontrada)
				ejecutar(aux2,1);
			else
				yyerror("Error al llamar a la función; no se ha encontrado");
			break;
		case OP_DECL:
			introducir(&aux->exp1,&com,&fin);
		 break;
		}//switch
		aux=aux->der;
	}while(aux!=NULL);
}//función

NODO procesarexp(ARBOL *aux){
	NODO retorno;
	NODO *variable;
	
	
	int i,k;
	char *a,*b;
	float real1,real2;
	int bool1,bool2;
	
	a= malloc(sizeof(NODO));
	b= malloc(sizeof(NODO));

	if(aux!=INICIO && aux->izq!=NULL)
		aux->exp1=procesarexp(aux->izq);
	
	do{
		printf("%s\n",aux->exp1.nombre);
		aux=aux->izq;
	}while(aux!=NULL);
	
	aux=INICIO;
	
	switch(aux->op){
		case OP_IGUALDAD:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
			retorno.tipo=3;//asigno tipo bool
			
			if ((aux->exp1.tipo)==(aux->exp2.tipo))
			{ 	
				if (aux->exp1.tipo==1)//si es numero
				{
					if (real1!=real2) retorno.valbool =0 ;
					else retorno.valbool=1;
				} 
				else if(aux->exp1.tipo==2)//si es string
				{
					if (strcmp(a,b)!=0) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				if (aux->exp1.tipo==3)//si es numero
				{
					if (bool1!=bool2) retorno.valbool =0 ;
					else retorno.valbool=1;
				}  	
				else if(aux->exp1.tipo==4)//si es cte cadena
				{
					if (strcmp(aux->exp1.cad,aux->exp2.cad)!=0) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				if (aux->exp1.tipo==6)//si es numero
				{
					if (i!=k) retorno.valbool =0 ;
					else retorno.valbool=1;
				} 
			}	

			else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
			{
			if (strcmp(a,aux->exp2.cad)!=0) retorno.valbool =0; 
			else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
			{
			if (strcmp(aux->exp1.cad,b)!=0) retorno.valbool =0; 
			else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
			{
				if (i!=real2) retorno.valbool =0; 
				else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
			{
				if (real1!=k) retorno.valbool =0; 
				else retorno.valbool=1;
			}
			else yyerror("Error en la desigualdad: Operaciones sobre tipos diferentes \n");                                                            
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_NOT:
			if (aux->exp1.tipo==3) 
			{
				retorno.tipo=3;
				if(aux->exp1.escons)
					retorno.valbool = !aux->exp1.valbool;
				else {
					variable=buscar(aux->exp1.nombre,&com,&fin);
					retorno.valbool=!(variable->valbool);
				}
			}
			else yyerror("Error en la negación: Operaciones sobre tipos incorrectos\n");
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_OR:
			if ((aux->exp2.tipo==3) && (aux->exp2.tipo==3)) {
				retorno.tipo=3;
				if(!aux->exp1.escons) {
					variable=buscar(aux->exp1.nombre,&com,&fin);
					i=variable->valbool;
				} else
					i=aux->exp1.valbool;
					
				if(!aux->exp2.escons) {
					variable=buscar(aux->exp2.nombre,&com,&fin);
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
					variable=buscar(aux->exp1.nombre,&com,&fin);
					i=variable->valbool;
				} else
					i=aux->exp1.valbool;
					
				if(!aux->exp2.escons) {
					variable=buscar(aux->exp2.nombre,&com,&fin);
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
		case OP_DESIGUALDAD:		
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
			retorno.tipo=3;//asigno tipo bool
			
			if ((aux->exp1.tipo)==(aux->exp2.tipo))
			{ 	
				if (aux->exp1.tipo==1)//si es numero
				{
					if (real1!=real2) retorno.valbool =0 ;
					else retorno.valbool=1;
				} 
				else if(aux->exp1.tipo==2)//si es string
				{
					if (strcmp(a,b)!=0) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				if (aux->exp1.tipo==3)//si es numero
				{
					if (bool1!=bool2) retorno.valbool =0 ;
					else retorno.valbool=1;
				}  	
				else if(aux->exp1.tipo==4)//si es cte cadena
				{
					if (strcmp(aux->exp1.cad,aux->exp2.cad)!=0) retorno.valbool =0; 
					else retorno.valbool=1;
				}
				if (aux->exp1.tipo==6)//si es numero
				{
					if (i!=k) retorno.valbool =0 ;
					else retorno.valbool=1;
				} 
			}	

			else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
			{
			if (strcmp(a,aux->exp2.cad)!=0) retorno.valbool =0; 
			else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
			{
			if (strcmp(aux->exp1.cad,b)!=0) retorno.valbool =0; 
			else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
			{
				if (i!=real2) retorno.valbool =0; 
				else retorno.valbool=1;
			}
			else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
			{
				if (real1!=k) retorno.valbool =0; 
				else retorno.valbool=1;
			}
			else yyerror("Error en la desigualdad: Operaciones sobre tipos diferentes \n");                                                            
			retorno.valbool=!retorno.valbool;
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
			
		case OP_MENOR:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
			
				if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
			//printf("%d\t%d\n",i,k);

			retorno.tipo=3;//Se asigna el tipo bool
			if ((aux->exp1.tipo)==(aux->exp2.tipo))
			{ 	
				if (aux->exp1.tipo==1)//si es real
				{
					if (real1<real2) retorno.valbool=1 ;
					else retorno.valbool=0;
				} 
				else if(aux->exp1.tipo==2)//si es string
				{
					if (strcmp(a,b)<0) retorno.valbool =1; 
					else retorno.valbool=0;
				} 	
				else if(aux->exp1.tipo==4)//si es cte cadena
				{
					if (strcmp(aux->exp1.cad,aux->exp2.cad)<0) retorno.valbool =1; 
					else retorno.valbool=0;
				}
				else if(aux->exp1.tipo==6)//si es entero
				{
					if (i<k) retorno.valbool=1 ;
					else retorno.valbool=0;
				}
			}	

			else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
			{
				if (strcmp(a,aux->exp2.cad)<0) retorno.valbool =1; 
				else retorno.valbool=0;
			}
			else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
			{
				if (strcmp(aux->exp1.cad,b)<0) retorno.valbool =1; 
				else retorno.valbool=0;
			}
			else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
			{
				if (i<real2) retorno.valbool =1; 
				else retorno.valbool=0;
			}
			else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
			{
				if (real1<k) retorno.valbool =1; 
				else retorno.valbool=0;
			}
			else yyerror("Error en el menor: Operaciones sobre tipos diferentes\n");
			retorno.tipo=3;
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_MAYOR:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}	
			
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

			retorno.tipo=3;//asigno tipo bool
			if ((aux->exp1.tipo)==(aux->exp2.tipo))
			{ 	
				if (aux->exp1.tipo==1)//si es numero
				{
				if (real1>real2) retorno.valbool =1 ;
				else retorno.valbool=0;
				} 
				else if(aux->exp1.tipo==2)//si es string
				{
				if (strcmp(a,b)>0) retorno.valbool =1; 
				else retorno.valbool=0;
				} 	
				else if(aux->exp1.tipo==4)//si es cte cadena
				{
					if (strcmp(aux->exp1.cad,aux->exp2.cad)>0) retorno.valbool =1; 
					else retorno.valbool=0;
				}
				else if(aux->exp1.tipo==6)//si es cte cadena
				{
					if (i>k) retorno.valbool =1 ;
					else retorno.valbool=0;
				} 	 	
			}	

			else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
			{
			if (strcmp(a,aux->exp2.cad)>0) retorno.valbool =1; 
			else retorno.valbool=0;
			}
			else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
			{
				if (strcmp(aux->exp1.cad,b)>0) retorno.valbool =1; 
				else retorno.valbool=0;
			}
			else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
			{
				if (i>real2) retorno.valbool =1; 
				else retorno.valbool=0;
			}
				else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
			{
				if (real1>k) retorno.valbool =1; 
				else retorno.valbool=0;
			}

			else yyerror("Error en el mayor: Operaciones sobre tipos diferentes\n"); 
			retorno.tipo=3;
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_MAI:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}	
		
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

		retorno.tipo=3;//asigno tipo bool
		if ((aux->exp1.tipo)==(aux->exp2.tipo))
		{ 	
			if (aux->exp1.tipo==1)//si es numero
			{
				if (real1>=real2) retorno.valbool =1 ;
				else retorno.valbool=0;
			} 
			else if(aux->exp1.tipo==2)//si es string
			{
				if (strcmp(a,b)>=0) retorno.valbool =1; 
				else retorno.valbool=0;
			} 	
			else if(aux->exp1.tipo==4)//si es cte cadena
			{
				if (strcmp(aux->exp1.cad,aux->exp2.cad)>=0) retorno.valbool =1; 
				else retorno.valbool=0;
			} 	
			else if (aux->exp1.tipo==6)//si es numero
			{
				if (i>=k) retorno.valbool =1 ;
				else retorno.valbool=0;
			} 
		}	

		else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
		{
			if (strcmp(a,aux->exp2.cad)>=0) retorno.valbool =1; 
			else retorno.valbool=0;
		}
		else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
		{
			if (strcmp(aux->exp1.cad,b)>=0) retorno.valbool =1; 
			else retorno.valbool=0;
		}
			else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
		{
			if (i>=real2) retorno.valbool =1; 
			else retorno.valbool=0;
		}
			else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
		{
			if (real1>=k) retorno.valbool =1; 
			else retorno.valbool=0;
		}

		else yyerror("Error en el mayor o igual: Operaciones sobre tipos diferentes\n"); 
			retorno.tipo=3;
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_MEI:
		if(aux->exp1.escons) {
			i=aux->exp1.valint;
			real1=aux->exp1.valnum;
			bool1=aux->exp1.valbool;
			strcpy(a,aux->exp1.valstr);
		} else {
			variable=buscar(aux->exp1.nombre,&com,&fin);
			i=variable->valint;
			real1=variable->valnum;
			bool1=variable->valbool;
			strcpy(a,variable->valstr);
		}
			
		if(aux->exp2.escons) {
			k=aux->exp2.valint;
			real2=aux->exp2.valnum;
			bool2=aux->exp2.valbool;
			strcpy(b,aux->exp2.valstr);
		} else {
			variable=buscar(aux->exp2.nombre,&com,&fin);
			k=variable->valint;
			real2=variable->valnum;
			bool2=variable->valbool;
			strcpy(b,variable->valstr);
		}

		retorno.tipo=3;//asigno tipo bool
		if ((aux->exp1.tipo)==(aux->exp2.tipo))
		{ 	
			if (aux->exp1.tipo==1)//si es numero
			{
			if (real1<=real2) retorno.valbool =1 ;
				else retorno.valbool=0;
			} 
			else if(aux->exp1.tipo==2)//si es string
			{
				if (strcmp(a,b)<=0) retorno.valbool =1; 
				else retorno.valbool=0;
			} 	
			else if(aux->exp1.tipo==4)//si es cte cadena
			{
				if (strcmp(aux->exp1.cad,aux->exp2.cad)<=0) retorno.valbool =1; 
				else retorno.valbool=0;
			} 	
			if (aux->exp1.tipo==6)//si es numero
			{
				if (i<=k) retorno.valbool =1 ;
				else retorno.valbool=0;
			} 
		}	

		else if ((aux->exp1.tipo==2)&&(aux->exp2.tipo==4))//cadena y constante
		{
			if (strcmp(a,aux->exp2.cad)<=0) retorno.valbool =1; 
			else retorno.valbool=0;
		}
		else if ((aux->exp1.tipo==4)&&(aux->exp2.tipo==2))//constante y cadena
		{
			if (strcmp(aux->exp1.cad,b)<=0) retorno.valbool =1; 
			else retorno.valbool=0;
		}
		else if ((aux->exp1.tipo==6)&&(aux->exp2.tipo==1))//constante y cadena
		{
			if (i>=real2) retorno.valbool =1; 
			else retorno.valbool=0;
		}
			else if ((aux->exp1.tipo==1)&&(aux->exp2.tipo==6))//constante y cadena
		{
			if (real1>=k) retorno.valbool =1; 
			else retorno.valbool=0;
		}

		else yyerror("Error en el menor o igual: Operaciones sobre tipos diferentes\n");
			retorno.tipo=3;
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_SUMA:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
			if ((aux->exp1.tipo==1) && (aux->exp2.tipo==1)){
				retorno.tipo=1;
				retorno.valnum = real1 + real2;
			}
			else if((aux->exp1.tipo==2) && (aux->exp2.tipo==2)){
				retorno.tipo=2;
				strcpy(retorno.valstr,strcat(a,b));
			}
			else if((aux->exp1.tipo==2) && (aux->exp2.tipo==4)){
				retorno.tipo=2;
				strcpy(retorno.valstr,strcat(a,aux->exp2.cad));
			}
			else if((aux->exp1.tipo==4) && (aux->exp2.tipo==2)){
				retorno.tipo=2;
				strcpy(retorno.valstr,strcat(aux->exp1.cad,b));
			}
			else if((aux->exp1.tipo==4) && (aux->exp2.tipo==4)){
				retorno.tipo=4;
				strcpy(retorno.cad,strcat(aux->exp1.cad,aux->exp2.cad));
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==6)){
				retorno.tipo=6;
				retorno.valint = i + k;
			}
			else if((aux->exp1.tipo==1) && (aux->exp2.tipo==6)){
				retorno.tipo=1;
				retorno.valnum = real1 + k;
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==1)){
				retorno.tipo=1;
				retorno.valnum = i + real2;
			}
			else{
			yyerror("Error en la suma: Operaciones sobre tipos diferentes\n");
			}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_RESTA:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
			if ((aux->exp1.tipo==1) && (aux->exp2.tipo==1)) {
				retorno.tipo=1;
				retorno.valnum = real1 - real2;
				}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==6)){
				retorno.tipo=6;
				retorno.valint = i - k;
			}
			else if((aux->exp1.tipo==1) && (aux->exp2.tipo==6)){
				retorno.tipo=1;
				retorno.valnum = real1 - k;
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==1)){
				retorno.tipo=1;
				retorno.valnum = i - real2;
			}
			else {                   
			yyerror("Error en la resta: Operaciones sobre tipos diferentes\n");
			}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_MULT:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}
			
				if ((aux->exp1.tipo==1) && (aux->exp2.tipo==1))	{
					retorno.tipo=1;
					retorno.valnum = real1 * real2;
				}
				else if((aux->exp1.tipo==6) && (aux->exp2.tipo==6)){
					retorno.tipo=6;
					retorno.valint = i * k;
				}
				else if((aux->exp1.tipo==1) && (aux->exp2.tipo==6)){
					retorno.tipo=1;
					retorno.valnum = real1 * k;
				}
				else if((aux->exp1.tipo==6) && (aux->exp2.tipo==1)){
					retorno.tipo=1;
					retorno.valnum = i * real2;
				}		
				else {		                   
				yyerror("Error en la multiplicación: Operaciones sobre tipos diferentes\n");
				}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_DIV:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

			if ((aux->exp1.tipo==1) && (aux->exp2.tipo==1))		{
				if (real2 == 0)
					yyerror("Error en la división: División por cero.\n");
				retorno.tipo=1;
				retorno.valnum = real1 / real2;
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==6)){
				if (k == 0)
					yyerror("Error en la división: División por cero.\n");			
				retorno.tipo=6;
				retorno.valint = i / k;
			}
			else if((aux->exp1.tipo==1) && (aux->exp2.tipo==6)){
				if (real2 == 0)
					yyerror("Error en la división: División por cero.\n");			
				retorno.tipo=1;
				retorno.valnum = real1 / k;
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==1)){
				if (k == 0)
					yyerror("Error en la división: División por cero.\n");
				retorno.tipo=1;
				retorno.valnum = i / real2;
			}
			else	{		                  
				yyerror("Error en la division: Operaciones sobre tipos diferentes\n");
			}
			
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_MOD:	
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

			if ((aux->exp1.tipo==6)&& (aux->exp2.tipo==6)) {
				retorno.tipo=6;
				retorno.valint = i%k;
			}
			else {
				yyerror("Error: Operaciones sobre tipos diferentes\n");
			}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_CAM:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}

			if (aux->exp1.tipo==1)	{
				retorno.tipo=1;
				retorno.valnum = -real1;
			}
			else if (aux->exp1.tipo==6) {
				retorno.tipo=6;
				retorno.valint = -i;
			}
			else	{                               
			yyerror("Error en el cambio de signo: Operaciones sobre tipos diferentes\n");
			}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
		case OP_POW:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin);
				i=variable->valint;
				real1=variable->valnum;
				bool1=variable->valbool;
				strcpy(a,variable->valstr);
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
			}

			if ((aux->exp1.tipo==1)&& (aux->exp2.tipo==1))
			{
			retorno.tipo=1;
			retorno.valnum = pow(real1,real2);
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==6)){
				retorno.tipo=6;
				retorno.valint = pow(i,k);
			}
			else if((aux->exp1.tipo==1) && (aux->exp2.tipo==6)){
				retorno.tipo=1;
				retorno.valnum = pow(real1,k);
			}
			else if((aux->exp1.tipo==6) && (aux->exp2.tipo==1)){
				retorno.tipo=1;
				retorno.valnum = pow(i,real2);
			}
			else {
				yyerror("Error en el exponencial: Operaciones sobre tipos diferentes\n");
			}
			retorno.escons=1;
			retorno.espun=0;
			return retorno;
			break;
	}//switch
}//función