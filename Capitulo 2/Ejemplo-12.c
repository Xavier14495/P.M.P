<<<<<<< HEAD
#include<stdio.h>
#include<math.h>

int main()
{
    int T, P, N;
    printf("Ingrese los valores de T, P y N: ");
    scanf("%d %d %d", &T, &P, &N);

    if (P != 0)
    {
        if (pow(T / P, N) == (pow(T, N) / pow(P, N)))

        printf("\nSe comprueba la igualdad");

        else
        printf("\nNo se comprueba la igualdad");
    }
        else
        printf("\nP tiene que ser diferente de cero”");
    
    return 0;
}
=======
#include<stdio.h>
#include<math.h>

int main()
{
    int T, P, N;
    printf("Ingrese los valores de T, P y N: ");
    scanf("%d %d %d", &T, &P, &N);

    if (P != 0)
    {
        if (pow(T / P, N) == (pow(T, N) / pow(P, N)))

        printf("\nSe comprueba la igualdad");

        else
        printf("\nNo se comprueba la igualdad");
    }
        else
        printf("\nP tiene que ser diferente de cero”");
    
    return 0;
}
>>>>>>> ffe060a60c1e42f9d38897794281b50bb8b0788c
