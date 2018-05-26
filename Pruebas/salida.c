#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main() 
{
int aux;
aux=0;
while (aux < 50) {
switch (aux){
default:
printf(" %s \n","Se acaba el bucle");
aux=60;
break;
case 5:
printf(" %s \n","aux es 5");
aux=6;
break;
case 10:
printf(" %s \n","aux es 10");
aux=5;
break;
case 0:
aux=10;
break;
}
}
}
