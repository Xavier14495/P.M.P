#include <stdio.h>
#include <ctype.h>

// void minymay(FILE *arc);//

int main()
{
    FILE *ar;
    int min = 0, may = 0;
    int p;

    if ((ar = fopen("arc5.txt", "r")) != NULL)
    {
        while ((p = fgetc(ar)) != EOF)
        {
            if (isalpha(p))
            {
                if (isupper(p))
                {
                    may++;
                }

                else if (islower(p))
                {
                    min++;
                }
            }
        }

        fclose(ar);

        printf("\nNumero de minisculas: %d", min);
        printf("\nNumero de mayusculas: %d", may);
    }

    else
    {
        printf("No se pudo abrir el archivo");
    }

    return (0);
}

/*void minymay(FILE *arc)
{
    int min = 0, may = 0;
    char p;

   while ((p = fgetc(arc)) != EOF)
    {
        p = fgetc(arc);

        if (isupper(p))
        {
            min++;
        }

        else if (islower(p))
        {
            may++;
        }

    }

    printf("\nnumero de minisculas: %d", min);
    printf("\nnumero de mayusculas: %d", may);
}*/