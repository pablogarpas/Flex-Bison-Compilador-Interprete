//Prototipos
NODO *ejecutar(ARBOL *var,int parar,char funcion[25]);
NODO procesarexp(ARBOL *aux,char funcion[25]);
//Variables globales
int nivel;//variable para controlar el nivel en el que parar
NODO *argini=NULL;//Lista de argumentos para pasar a una función
NODO *argfin=NULL;//Lista de argumentos para pasar a una función
NODO *auxnodo=NULL;

NODO *ejecutar(ARBOL *var,int parar,char funcion[25]) {
	ARBOL *aux,*aux2;
	NODO *variable,*variable2,*arg1,*arg2;
	int defecto;
	int encontrada;
	int i,k,j;
	char msj[255];
	
	aux=var;
	
	/*
	aux=INICIO;
	do{
		printf("%s\n",aux->exp1.nombre);
		aux2=aux;
		while(aux2!=NULL){
			printf("\t%d\n",aux2->op);
			aux2=aux2->der;
		}
		aux=aux->izq;
		
	}while(aux!=NULL);
	*/
	
	aux=var;
	
	do {
		//printf("%d\n",aux->op);
		switch(aux->op){
		case OP_ESCRIBIR:			
			if(aux->izq!=NULL) 
				aux->exp1=procesarexp(aux->izq,funcion);
				
			if(aux->exp1.espun) {
			variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				for (i=0;i<=aux->exp1.aux;i++) {
					if(variable->array==NULL) {
						arg1==(NODO *)malloc(sizeof (NODO));
						variable->array=arg1;
					}
					variable=variable->array;
				}		
				copiardatos(&aux->exp1,variable->tipo,1,variable->espun,variable->valstr,variable->valbool,variable->valnum,variable->valint,aux->exp1.nombre,0,variable->aux);
			}
			
			//printf("tipo:%d\n",aux->exp1.valint);
			
			//printf("val1:%d\n",com->sig->array->valint);
			
			//listar(&com);
			
			switch (aux->exp1.tipo){
				case 1:
					if(aux->exp1.escons) {
						printf("%f\n",aux->exp1.valnum);
					}
					else {
						variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
						printf("%f\n",variable->valnum);
					}
					break;
				case 3:
					if(aux->exp1.escons) {
						printf("%d\n",aux->exp1.valbool);
					}
					else {
						variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
						printf("%d\n",variable->valbool);
					}
					break;
				case 4:	
					if(aux->exp1.escons) {
						printf("%s\n",aux->exp1.valstr);
					}
					else {
						variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
						printf("%s\n",variable->valstr);
					}
					break;
				case 6: 
					if(aux->exp1.escons) {
						printf("%d\n",aux->exp1.valint);
					}
					else {
						variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
						printf("%d\n",variable->valint);
					}
					break;
				default:
					yyerror("Error al mostrar el elemento");
					break;
			}//switch
			break;
		case OP_ASIGNAR:		
			variable=buscar(aux->var->nombre,&com,&fin,funcion);
			
			//printf("var:\t%s\t%d\t%s\n",aux->var->nombre,aux->var->tipo,funcion);
			//listar(&com);
			
			if ((aux->var->tipo==aux->exp1.tipo)&&(aux->var->escons==0)&&(aux->exp1.espun==0)) {
				variable->tipo=aux->exp1.tipo;
				strcpy(variable->valstr,aux->exp1.valstr);
				variable->valbool= aux->exp1.valbool;
				variable->valnum = aux->exp1.valnum;
				variable->valint = aux->exp1.valint;
			}
			else if((aux->var->tipo=1)&&(aux->exp1.tipo==6)&&(aux->var->escons==0)&&(aux->exp1.espun==0)) {	
				variable->tipo=1;
				variable->valnum = aux->exp1.valint;
			}
			else if((aux->var->tipo=6)&&(aux->exp1.tipo==1)&&(aux->var->escons==0)&&(aux->exp1.espun==0)) {	
				variable->tipo=6;
				variable->valint = aux->exp1.valnum;
			}
			else if(aux->exp1.espun) {
				if (aux->var->tipo=aux->exp1.tipo) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
							arg1->tipo=aux->var->tipo;
						}
						variable=variable->array;
					}
						strcpy(variable->valstr,aux->exp1.valstr);
						variable->valbool= aux->exp1.valbool;
						variable->valnum = aux->exp1.valnum;
						variable->valint = aux->exp1.valint;
						//printf("%d\n",aux->exp1->tipo);
						//printf("%s\n",aux->var->nombre);
				}
				else 
					yyerror("Error en la asignación, no concuerdan los tipos o la variable es constante\n");	
			}
			else yyerror("Error en la asignación, no concuerdan los tipos o la variable es constante\n");	
			break;
		case OP_INC:
			if(aux->exp1.tipo==6) {			
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				variable->valint=variable->valint+1;				
			}else if(aux->exp1.tipo==1) {
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				variable->valnum=variable->valnum+1;
			}
			else
			yyerror("Error en el incremento: No se puede incrementar una variable no númerica");
			break;
		case OP_DEC:			
			if(aux->exp1.tipo==6) {			
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				variable->valint=variable->valint-1;				
			}else if(aux->exp1.tipo==1) {
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				variable->valnum=variable->valnum-1;
			}
			else
			yyerror("Error en el decremento: No se puede incrementar una variable no númerica");
			break;
		case OP_SI:		
			parar++;
			nivel++;
			
			if(aux->izq!=NULL) {
				aux->exp1=procesarexp(aux->izq,funcion);	
			}

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
				aux->exp1=procesarexp(aux->izq,funcion);
			
			while(aux->exp1.valbool) {
				ejecutar(aux->der,1,funcion);
				aux->exp1=procesarexp(aux->izq,funcion);
				}
			break;
		case OP_PARA:
			parar++;
			nivel++;
			
			variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
		
			variable->valint=aux->exp1.valint;
		
			while(variable->valint!= aux->exp2.valint) {
				ejecutar(aux->der,1,funcion);
				
				if(aux->exp1.valint < aux->exp2.valint)
					variable->valint++;
				if(aux->exp1.valint > aux->exp2.valint)
					variable->valint--;
			}
			break;
		case OP_SWITCH:
			parar++;
			nivel++;
					
			variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
		
			while(aux->der->op!=OP_FIN) {
				if(aux->der->op==OP_DEFAULT) {
					if(defecto==0)
						ejecutar(aux,1,funcion);	
				}
			
				if(aux->der->op==OP_CASE && aux->der->exp1.valint==variable->valint) {
					ejecutar(aux,1,funcion);
					defecto=1;
				}
					
				aux=aux->der;
			}
			defecto=0;
			break;
		case OP_FIN:
			if(parar==nivel) {
				return ;
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
			variable=buscar(aux->var->nombre,&com,&fin,funcion);
			
			if(aux->exp1.espun) {
				printf("Valor para la variable: %s\n",variable->nombre);
				for (i=0;i<=aux->exp1.aux;i++) {
					if(variable->array==NULL) {
						arg1=(NODO *)malloc(sizeof (NODO));
						variable->array=arg1;
						arg1->tipo=aux->var->tipo;
					}
					variable=variable->array;
				}
			}
			
			if(variable->tipo==4)
				fgets(variable->valstr,255,stdin);
			else if(variable->tipo==6) {
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
					
				if(encontrada==1){
					break;
					}
			}
			if(encontrada==1){
				encontrada=0;
				ejecutar(aux2,1,aux->exp1.nombre);
				}
			else
				yyerror("Error al llamar a la función; no se ha encontrado");
			break;
		case OP_ASIG_LLAMAR:
			aux2=INICIO;
			
			while(aux2->izq!=NULL) {
				aux2=aux2->izq;
				
				if(strcmp(aux2->exp1.nombre,aux->exp1.nombre)==0)
					encontrada=1;		
					
				if(encontrada)
					break;
			}
			if(encontrada){
				encontrada=0;
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				arg1=ejecutar(aux2,1,aux->exp1.nombre);
				
				if(aux->exp1.espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							variable2=(NODO *)malloc(sizeof (NODO));
							variable->array=variable2;
							variable2->tipo=variable->tipo;
						}
						variable=variable->array;
					}
				}
				
				
				if(arg1->tipo==variable->tipo) {
					copiardatos(variable,arg1->tipo,arg1->escons,arg1->espun,arg1->valstr,arg1->valbool,arg1->valnum,arg1->valint,variable->nombre,1,arg1->aux);
				}else{
					strcpy(msj,"Error en la variable de retorno de ");
					strcat(msj,aux->exp1.nombre);
					strcat(msj,", tipos incompatibles.");
				}
			}
			else
				yyerror("Error al llamar a la función; no se ha encontrado");
			break;
		case OP_DECL:
			if(recorrer(&com,aux->exp1.nombre,funcion)==0) {
				introducir(&aux->exp1,&com,&fin);
				//listar(&com);
			}else {
				strcpy(msj,"Error en las variables, la variable ");
				strcat(msj,aux->exp1.nombre);
				strcat(msj," ya existe.");
				yyerror(msj);	
			}
		 break;
		case OP_DECL_FUN:
		
			if(recorrer(&com,aux->exp1.nombre,funcion)==0) {
				introducir(&aux->exp1,&com,&fin);
				
				if (!(arg1=(NODO *)malloc(sizeof (NODO)))) {
					printf("No se ha podido reservar memoria \n");
					exit(0);
				}
				arg1->tipo=5;
				strcpy(arg1->nombre,funcion);
				introducir_arg(arg1,&argini,&argfin);
			}else {
				strcpy(msj,"Error en las variables, la variable ");
				strcat(msj,aux->exp1.nombre);
				strcat(msj," ya existe.");
				yyerror(msj);	
			}
		 break;
		case OP_DECL_ARG:
			strcpy(aux->exp1.cad,funcion);
			introducir_arg(&aux->exp1,&argini,&argfin);
			break;
		case OP_ARG:
			introducir(&aux->exp1,&com,&fin);
		 break;
		case OP_RETURN:

			introducir(&aux->exp1,&com,&fin);
			i=contar_arg(&com,&fin,funcion);
			k=contar(&argini,&argfin,funcion);

			//listar(&argini);
			//listar(&com);
			
			//printf("%d\t%d\n",i,k);
			
			if(k==i) {
			
				variable=buscar_fun(funcion,&com,&fin);
				variable2=buscar_fun(funcion,&argini,&argfin);
				
				while(variable!=NULL&&variable->esarg==0)
					variable=variable->sig;					
				
					variable2=variable2->sig;					
					
				for(k=0;k<i;k++) {
					arg1=variable;
					arg2=variable2;
					for(j=k;j>0;j--){
						arg1=arg1->sig;
						arg2=arg2->sig;
					}
					
					if(arg1->tipo==arg2->tipo){
						if(arg1->tipo!=2){
						arg2=buscar(arg2->nombre,&com,&fin,variable2->cad);
						
						copiardatos(arg1,arg2->tipo,arg2->escons,arg2->espun,arg2->valstr,arg2->valbool,arg2->valnum,arg2->valint,arg1->nombre,1,arg2->aux);
						}else{
							arg2=buscar(arg2->nombre,&com,&fin,variable2->cad);
							arg2=arg2->array;
							while(arg2!=NULL) {
								variable2=(NODO *)malloc(sizeof (NODO));
								copiardatos(variable2,arg2->tipo,arg2->escons,arg2->espun,arg2->valstr,arg2->valbool,arg2->valnum,arg2->valint,"",1,0);
								arg1->array=variable2;
								arg1=variable2;
								arg2=arg2->array;
							}
						}
					} else	
					yyerror("Error en los argumentos, tipos diferentes");	
				}
			}else {
				strcpy(msj,"Error al llamar a la función ");
				strcat(msj,funcion);
				strcat(msj,", número de argumentos incorrectos");
				yyerror(msj);	
			}

			if (!(arg1=(NODO *)malloc(sizeof (NODO)))) {
				printf("No se ha podido reservar memoria \n");
				exit(0);
			}
			auxnodo=arg1;
			
			arg1->tipo=aux->exp1.tipo;
		 	break;
		case OP_DEVOLVER:
			if(aux->exp1.escons==0) {
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				
				if(variable->tipo==auxnodo->tipo) {
					return variable;
					
				}
				else {
					strcpy(msj,"Error al devolver en la funcion ");
					strcat(msj,funcion);
					strcat(msj," tipos diferentes");
					yyerror(msj);	
				}
			}else{
				if(aux->exp1.tipo==auxnodo->tipo)
					return &aux->exp1;
				else {
					strcpy(msj,"Error al devolver en la funcion ");
					strcat(msj,funcion);
					strcat(msj," tipos diferentes");
					yyerror(msj);	
				}
			}
			break;
		}//switch
		aux=aux->der;
	}while(aux!=NULL);
}//función

NODO procesarexp(ARBOL *aux,char funcion[25]){
	NODO retorno;
	NODO *variable,*arg1;
	
	
	int i,k,j;
	char *a,*b;
	float real1,real2;
	int bool1,bool2;
	
	a= malloc(sizeof(NODO));
	b= malloc(sizeof(NODO));

	if(aux!=INICIO && aux->izq!=NULL) {
		aux->exp1=procesarexp(aux->izq,funcion);
		}
	/*
	do{
		printf("%s\n",aux->exp1.nombre);
		aux=aux->izq;
	}while(aux!=NULL);
	*/
	switch(aux->op){
		case OP_IGUALDAD:
			if(aux->exp1.escons) {
				i=aux->exp1.valint;
				real1=aux->exp1.valnum;
				bool1=aux->exp1.valbool;
				strcpy(a,aux->exp1.valstr);
			} else {
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else  {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (j=0;j<=aux->exp2.aux;j++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
					k=variable->valint;
					real2=variable->valnum;
					bool2=variable->valbool;
					strcpy(b,variable->valstr);
					aux->exp2.tipo=variable->tipo;
				}
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
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
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
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valbool;
				} else
					i=aux->exp1.valbool;
					
				if(!aux->exp2.escons) {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
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
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valbool;
				} else
					i=aux->exp1.valbool;
					
				if(!aux->exp2.escons) {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else  {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (j=0;j<=aux->exp2.aux;j++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
					k=variable->valint;
					real2=variable->valnum;
					bool2=variable->valbool;
					strcpy(b,variable->valstr);
					aux->exp2.tipo=variable->tipo;
				}
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}
			
				if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}	
			
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else  {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (j=0;j<=aux->exp2.aux;j++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
					k=variable->valint;
					real2=variable->valnum;
					bool2=variable->valbool;
					strcpy(b,variable->valstr);
					aux->exp2.tipo=variable->tipo;
				}
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}	
		
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else  {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (j=0;j<=aux->exp2.aux;j++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
					k=variable->valint;
					real2=variable->valnum;
					bool2=variable->valbool;
					strcpy(b,variable->valstr);
					aux->exp2.tipo=variable->tipo;
				}
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
			variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
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
			variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else  {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (j=0;j<=aux->exp2.aux;j++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
					k=variable->valint;
					real2=variable->valnum;
					bool2=variable->valbool;
					strcpy(b,variable->valstr);
					aux->exp2.tipo=variable->tipo;
				}
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else  {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (j=0;j<=aux->exp2.aux;j++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
					k=variable->valint;
					real2=variable->valnum;
					bool2=variable->valbool;
					strcpy(b,variable->valstr);
					aux->exp2.tipo=variable->tipo;
				}
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else  {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (j=0;j<=aux->exp2.aux;j++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
					k=variable->valint;
					real2=variable->valnum;
					bool2=variable->valbool;
					strcpy(b,variable->valstr);
					aux->exp2.tipo=variable->tipo;
				}
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else  {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (j=0;j<=aux->exp2.aux;j++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
					k=variable->valint;
					real2=variable->valnum;
					bool2=variable->valbool;
					strcpy(b,variable->valstr);
					aux->exp2.tipo=variable->tipo;
				}
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else  {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp2.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
					k=variable->valint;
					real2=variable->valnum;
					bool2=variable->valbool;
					strcpy(b,variable->valstr);
					aux->exp2.tipo=variable->tipo;
				}
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
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
				variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (i=0;i<=aux->exp1.aux;i++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp1.nombre,&com,&fin,funcion);
					i=variable->valint;
					real1=variable->valnum;
					bool1=variable->valbool;
					strcpy(a,variable->valstr);
					aux->exp1.tipo=variable->tipo;
				}
			}
				
			if(aux->exp2.escons) {
				k=aux->exp2.valint;
				real2=aux->exp2.valnum;
				bool2=aux->exp2.valbool;
				strcpy(b,aux->exp2.valstr);
			} else  {
				variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
				if(variable->espun) {
					for (j=0;j<=aux->exp2.aux;j++) {
						if(variable->array==NULL) {
							arg1=(NODO *)malloc(sizeof (NODO));
							variable->array=arg1;
						}
						variable=variable->array;
					}
				k=variable->valint;
				real2=variable->valnum;
				bool2=variable->valbool;
				strcpy(b,variable->valstr);
				aux->exp2.tipo=variable->tipo;
				} else {
					variable=buscar(aux->exp2.nombre,&com,&fin,funcion);
					k=variable->valint;
					real2=variable->valnum;
					bool2=variable->valbool;
					strcpy(b,variable->valstr);
					aux->exp2.tipo=variable->tipo;
				}
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
