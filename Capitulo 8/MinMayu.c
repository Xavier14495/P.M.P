#include <stdio.h>

int esDigito(char c);
void shuffle(char* cadena);

int main() 
{
    int i, j, n;
    char FRA[20][50];

    printf("\nIngrese el numero de filas del arreglo: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Ingrese la linea %d de texto: ", i + 1);
        fflush(stdin);
        gets(FRA[i]);
    }

    int mi = 0, ma = 0;
    for (i = 0; i < n; i++) {
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

    for (i = 0; i < n; i++) {
        for (j = 0; FRA[i][j] != '\0'; j++) 
        {
            if (esDigito(FRA[i][j])) 
            {
                printf("\n%c es un digito en la cadena %d", FRA[i][j], i+1);
            }
        }
    }

    for (i = 0; i < n; i++) {
        shuffle(FRA[i]);
        printf("\nCadena %d con mayusculas y minusculas intercambiadas: %s", i+1, FRA[i]);
    }

    return 0;
}

int esDigito(char c) 
{
    return (c >= '0' && c <= '9');
}

void shuffle(char* cadena) 
{
    int i = 0;
    while (cadena[i] != '\0') 
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') 
        {
            cadena[i] = cadena[i] - 32; 
        } 
        
        else if (cadena[i] >= 'A' && cadena[i] <= 'Z') 
        {
            cadena[i] = cadena[i] + 32; 
        }
        i++;
    }
}