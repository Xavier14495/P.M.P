#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Registro
{
    int numerosAleatorios[3];
    int year, month, day, hour, minute, second;
};

void historial(struct Registro *registros, int numTiradas);
void tirar(struct Registro **registros, int *numTiradas);
void liberarRegistros(struct Registro **registros) ;
void Resultado(const char *mensaje);


int main()
{
    int opcion;
    struct Registro *registros = NULL;
    int numTiradas = 0;

    srand((unsigned int)time(NULL));

    do
    {
        printf("\n0. Salir \n");
        printf("1. Realizar tirada \n");
        printf("2. Historial\n");
        printf("\nElige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 0:
            printf("\nHas elegido salir. Adios.\n");
            break;
        case 1:
            printf("\nTirada\n");
            tirar(&registros, &numTiradas);
            break;
        case 2:
            printf("\nHistorial\n\n");
            historial(registros, numTiradas);
            break;

        default:
            printf("\nOpcion no valida. Por favor, elige una opcion del 1 al 3.\n");
            break;
        }

    } while (opcion != 0);

    liberarRegistros(&registros);

    return 0;
}

void historial(struct Registro *registros, int numTiradas)
{
    for (int i = 0; i < numTiradas; i++)
    {
        printf("Tirada %d - N1: %d %d %d\tFecha y hora: %d-%02d-%02d %02d:%02d:%02d\n",
               i + 1, registros[i].numerosAleatorios[0], registros[i].numerosAleatorios[1], registros[i].numerosAleatorios[2],
               registros[i].year, registros[i].month, registros[i].day,
               registros[i].hour, registros[i].minute, registros[i].second);
    }
}

void tirar(struct Registro **registros, int *numTiradas)
{
    time_t tiempoActual;
    time(&tiempoActual);

    struct tm *infoTiempo = localtime(&tiempoActual);

    (*numTiradas)++;

    // Intenta asignar memoria para la nueva tirada
    struct Registro *temp = realloc(*registros, sizeof(struct Registro) * (*numTiradas));
    if (temp == NULL) {
        // Manejar el error de realloc
        printf("Error al asignar memoria para la nueva tirada.\n");
        exit(EXIT_FAILURE); // o manejar el error de otra manera
    } else {
        // Asignación exitosa, actualiza el puntero
        *registros = temp;
    }

    // Genera los números aleatorios y guarda la fecha y hora
    for (int i = 0; i < 3; i++)
    {
        (*registros)[*numTiradas - 1].numerosAleatorios[i] = rand() % 101;
    }

    (*registros)[*numTiradas - 1].year = infoTiempo->tm_year + 1900;
    (*registros)[*numTiradas - 1].month = infoTiempo->tm_mon + 1;
    (*registros)[*numTiradas - 1].day = infoTiempo->tm_mday;
    (*registros)[*numTiradas - 1].hour = infoTiempo->tm_hour;
    (*registros)[*numTiradas - 1].minute = infoTiempo->tm_min;
    (*registros)[*numTiradas - 1].second = infoTiempo->tm_sec;

    printf("Tirada realizada y almacenada.\n");
}


void liberarRegistros(struct Registro **registros) 
{
    free(*registros);
    *registros = NULL;
}



void Resultado(const char *mensaje)
{
    printf("%s\n", mensaje);
}