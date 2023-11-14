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
void clear(struct Registro **registros);

int main()
{
    int opcion;
    struct Registro *registros = NULL;
    int numTiradas = 0;

    srand((unsigned int)time(NULL));

    do
    {
        // Menú de opciones
        printf("\n0. Salir \n");
        printf("1. Realizar tirada \n");
        printf("2. Historial\n");

        printf("\nElige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 0:
            // Salir del programa
            printf("\nHas elegido salir. Adios.\n");
            break;
        case 1:
            // Realizar tirada
            printf("\nTirada realizada y almacenada.\n");
            tirar(&registros, &numTiradas);
            break;
        case 2:
            // Ver historial de tiradas
            printf("\nHistorial\n\n");
            historial(registros, numTiradas);
            break;
        default:
            // Opción no válida
            printf("\nOpcion no valida. Por favor, elige una opcion del 0 al 2\n");
            break;
        }

    } while (opcion != 0);

    // Liberar memoria antes de salir
    clear(&registros);

    return 0;
}

void historial(struct Registro *registros, int numTiradas)
{
    // Mostrar historial de tiradas
    for (int i = 0; i < numTiradas; i++)
    {
        printf("Tirada %d - N1: %d %d %d\tFecha y hora: %d-%02d-%02d %02d:%02d:%02d\n", i + 1,
               registros[i].numerosAleatorios[0], registros[i].numerosAleatorios[1], registros[i].numerosAleatorios[2],
               registros[i].year, registros[i].month, registros[i].day,
               registros[i].hour, registros[i].minute, registros[i].second);
    }
}

void tirar(struct Registro **registros, int *numTiradas)
{
    // Realizar una nueva tirada y almacenarla en registros
    time_t tiempoActual;
    time(&tiempoActual);

    struct tm *infoTiempo = localtime(&tiempoActual);

    (*numTiradas)++;

    // Reasignar memoria para la nueva tirada
    struct Registro *temp = realloc(*registros, sizeof(struct Registro) * (*numTiradas));
    if (temp == NULL)
    {
        // Manejar error si la asignación de memoria falla
        printf("Error al asignar memoria para la nueva tirada.\n");
        exit(EXIT_FAILURE);
    }
    
    else
    {
        *registros = temp;
    }

    // Generar tres números aleatorios
    for (int i = 0; i < 3; i++)
    {
        (*registros)[*numTiradas - 1].numerosAleatorios[i] = rand() % 101;
    }

    // Almacenar la fecha y hora actual
    (*registros)[*numTiradas - 1].year = infoTiempo->tm_year + 1900;
    (*registros)[*numTiradas - 1].month = infoTiempo->tm_mon + 1;
    (*registros)[*numTiradas - 1].day = infoTiempo->tm_mday;
    (*registros)[*numTiradas - 1].hour = infoTiempo->tm_hour;
    (*registros)[*numTiradas - 1].minute = infoTiempo->tm_min;
    (*registros)[*numTiradas - 1].second = infoTiempo->tm_sec;
}

void clear(struct Registro **registros)
{
    // Liberar la memoria asignada para registros
    free(*registros);
    *registros = NULL;
}
