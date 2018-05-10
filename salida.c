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
while (aux1 > 5) {
printf("adios\n");
aux1--;
switch (aux1){
default:
printf("qwe\n");
break;
case 3:
printf("asd\n");
break;
case 2:
printf("asd\n");
break;
case 1:
printf("asd\n");
break;
}
}
}
}
}
}
