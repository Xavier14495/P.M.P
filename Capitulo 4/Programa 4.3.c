#include <stdio.h>

void f1(void);
int X = 5;

int main()
{
    int I;
    for (I = 1; I <= 3; I++)
        f1();
}

void f1(void)
{
    int K_2 = 2;
    K_2 += K_2;

    printf("\n\nEl valor de la variable local es: %d", K_2);

    X = X + K_2;

    printf("\nEl valor de la variable global es: %d", X);
}