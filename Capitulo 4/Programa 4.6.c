#include <stdio.h>

void f1(int*);

int main()
{
    int I, K = 4;
    
    for (I = 1; I <= 3; I++)
    {
        printf("\n\nValor de K antes de llamar a la funcion: %d", ++K);
        f1(&K);
        printf("\nValor de K despues de llamar a la funcion: %d", K);
    }
}

void f1(int*R)
{
    *R += *R;
}