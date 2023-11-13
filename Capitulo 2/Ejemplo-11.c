<<<<<<< HEAD
#include<stdio.h>

int main()
{
    int DIS, TIE;
    float BIL;

    printf("Ingrese la distancia entre ciudades y el tiempo de estancia: ");
    scanf("%d %d", &DIS, &TIE);

    if ((DIS * 2 > 500) && (TIE > 10))

    BIL = DIS * 2 * 0.19 * 0.8;

    else

    BIL = DIS * 2 * 0.19;

    printf("\n\nCosto del billete: %7.2f", BIL);
    return 0;
}
=======
#include<stdio.h>

int main()
{
    int DIS, TIE;
    float BIL;

    printf("Ingrese la distancia entre ciudades y el tiempo de estancia: ");
    scanf("%d %d", &DIS, &TIE);

    if ((DIS * 2 > 500) && (TIE > 10))

    BIL = DIS * 2 * 0.19 * 0.8;

    else

    BIL = DIS * 2 * 0.19;

    printf("\n\nCosto del billete: %7.2f", BIL);
    return 0;
}
>>>>>>> ffe060a60c1e42f9d38897794281b50bb8b0788c
