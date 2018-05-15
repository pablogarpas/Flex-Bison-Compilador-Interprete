#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int qwe(){
printf(" %s \n","asd");
return 21;
}
int prueba(int aux2, char *aux4){
printf(" %d \n",aux2);
printf(" %s \n",aux4);
aux2=18;
qwe();
return aux2;
}
int main() 
{
int aux;
char *aux3;
aux=15;
aux3="holi";
aux=qwe();
printf(" %d \n",aux);
}
