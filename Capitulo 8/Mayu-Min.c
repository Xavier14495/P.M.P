#include <stdio.h>

int main()
{
    int i, j, n;
    char FRA[20][50];
    int mi = 0, ma = 0;

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Ingrese la linea %d de texto: ", i + 1);
        fflush(stdin);

        gets(FRA[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; FRA[i][j] != '\0'; j++)
        {
            if (FRA[i][j] >= 'a' && FRA[i][j] <= 'z')
            {
                mi++;
            }
            else if (FRA[i][j] >= 'A' && FRA[i][j] <= 'Z')
            {
                ma++;
            }
        }
    }

    printf("\nNumero de letras minusculas: %d", mi);
    printf("\nNumero de letras mayusculas: %d", ma);

    return 0;
}

