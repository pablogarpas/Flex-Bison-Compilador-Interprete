#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>int main() 
{
int aux2;
int aux1;
aux1=5;
for (aux1=0;aux1<10;aux1++){
for (aux2=0;aux2<10;aux2++){
printf(" %d \n",aux1);
printf(" %d \n",aux2);
if (aux1 == 10)
printf("hola\n");
} else {
printf("adios\n");
}
}
}
}
