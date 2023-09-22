#include<stdio.h>

int main ()

{
    float PRE, NPR;

    printf("Ingrese precio: ");
    scanf("%f", &PRE);

    if (PRE > 1500)
    {
        NPR = PRE * 1.11;
        printf("\n Nuevo precio: %7.2f", NPR);
    }

    return 0;
}
