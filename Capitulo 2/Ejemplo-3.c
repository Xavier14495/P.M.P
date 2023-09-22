#include<stdio.h>

int main()
{
    float PRO;

    printf("Ingrese promedio: ");
    scanf("%f", &PRO);

    if (PRO >= 6.0)
    
        printf("\nAprobado");
    
    else

        printf("\nReprobado");
    
    return 0;
}
