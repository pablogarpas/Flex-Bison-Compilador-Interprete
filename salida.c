#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int qwe(int aux7){
printf(" %s \n","qwe");
}
int prueba(int aux2, char *aux4){
printf(" %d \n",aux2);
printf(" %s \n",aux4);
aux2=18;
qwe(aux2);
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
