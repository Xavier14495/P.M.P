#include<stdio.h>

int main()
{
    int I;
    float SAL, NOM;

    NOM = 0;

    for (I=1; I<=15; I++)          //Repite en bucle el programa hasta que ya no se cumpla la condicion. Inicia en 1 y pregunta si es mayor igual a 15, de no serlo lo repite y le suma 1 a la I//
    {
        printf("\nIngrese el salario del profesor %d:\t", I);   //Pide ingresar un valor numerico y lo guarda en la variable I//
        scanf("%f", &SAL);                                      //Escanea el dato y lo dirige a la variable SAL//

        NOM = NOM + SAL;       //Suma la variable NOM que es igual a 0 + el salario ingresado//
    }
    
    printf("\nEl total de la nomina es: %.2f", NOM);        //Imprime el resultado con 2 decimales//

    return 0;
}