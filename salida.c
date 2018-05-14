#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int prueba(int aux2, char *aux4){
printf(" %d \n",aux2);
printf(" %s \n",aux4);
return aux2;
}
int main() 
{
int aux;
char *aux3;
aux=15;
aux3="qwe";
prueba(aux, aux3);
}
