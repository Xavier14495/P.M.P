#include <stdio.h>

const int TAM = 10;
void Lectura(int[][TAM], int);
void Imprime(int[][TAM], int);

int main()
{
    int MAT[TAM][TAM];
    Lectura(MAT, TAM);
    Imprime(MAT, TAM);
}

void Lectura(int A[][TAM], int F)
{
    int I, J;
    for (I = 0; I < F; I++) /*Por que utiliza una variable F? y donde especifica su valor?*/
    {
        for (J = 0; J < F; J++)
        {
            printf("Ingrese el elemento %d %d: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
    }
}

void Imprime(int A[][TAM], int F)
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < TAM; J++) /*Por que cuando J sea menor a TAM dejara de ser verdadero y a que se refiere?*/
        {
            if (I == J) /*Por que busca igualar I y J?*/
            {
                printf("\nDiagonal %d %d: %d ", I, J, A[I][J]);
            }
        }
    }
}