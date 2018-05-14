#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int prueba(int aux2, char *aux4){
printf(" %d \n",aux2);
printf(" %s \n",aux4);
aux2=16;
return aux2;
}
int main() 
{
int aux;
char *aux3;
aux=15;
aux3="holi";
aux=prueba(aux, aux3);
printf(" %d \n",aux);
}
