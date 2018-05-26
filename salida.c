#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define resultado "Variable igual a 5"
#define resultado1 "Variable diferente de 5"
int main() 
{
int aux;
aux=5;
for (aux=3;aux<5;aux++){
if (aux == 5) {
printf(" %s \n",resultado);
} else {
printf(" %s \n",resultado1);
}
}
}
