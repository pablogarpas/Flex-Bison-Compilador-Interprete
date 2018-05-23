#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int qwe(int *auxi){
printf(" %d \n",auxi[2]);
return 5;
}
int main() 
{
int aux[5];
aux[0]=2;
aux[1]=4;
aux[2]=8;
aux[2]=qwe(aux);
printf(" %d \n",aux[2] * 2);
}
