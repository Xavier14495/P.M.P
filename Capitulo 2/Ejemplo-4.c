<<<<<<< HEAD
#include<stdio.h>

int main()
{
    float PRE, NPR;

    printf("Ingrese el precio: ");
    scanf("%f", &PRE);

    if (PRE < 1500)
    {
        NPR = PRE * 1.11;
    }
    
    else
    {
        NPR = PRE * 1.08;
    }

    printf("\nNuevo precio: %8.2f", NPR);
    
    return 0;
}
=======
#include<stdio.h>

int main()
{
    float PRE, NPR;

    printf("Ingrese el precio: ");
    scanf("%f", &PRE);

    if (PRE < 1500)
    {
        NPR = PRE * 1.11;
    }
    
    else
    {
        NPR = PRE * 1.08;
    }

    printf("\nNuevo precio: %8.2f", NPR);
    
    return 0;
}
>>>>>>> ffe060a60c1e42f9d38897794281b50bb8b0788c
