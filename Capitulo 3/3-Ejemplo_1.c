#include<stdio.h>

int main()
{
    int I;
    float SAL, NOM;

    NOM = 0;

    for (I=1; I<=15; I++)          //Repite en bucle el programa hasta que ya no se cumpla la condicion. Inicia en 1 y pregunta si es mayor igual a 15, de no serlo lo repite y le suma 1 a la I//
    {
        printf("\nIngrese el salario del profesor %d:\t", I);
        scanf("%f", &SAL);

        NOM = NOM + SAL;
    }
    
    printf("\nEl total de la nomina es: %.2f", NOM);

    return 0;
}