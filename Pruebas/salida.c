#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int prueba(int aux1){
printf(" %d \n",aux1);
if (aux1 != 20) {
aux1++;
prueba(aux1);
} else {
return 1;
}
}
int main() 
{
int aux;
char *retorno;
aux=0;
prueba(aux);
printf(" %s \n","Fin recursividad");
}
