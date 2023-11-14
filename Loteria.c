#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Registro
{
    int numerosAleatorios[3];
    int year, month, day, hour, minute, second;
};

// Declaraciones de funciones
void historial(struct Registro *registros, int numTiradas);
void tirar(struct Registro **registros, int *numTiradas);
void clear(struct Registro **registros);
void jugar(struct Registro **registros, int *numTiradas, int opcion);
void Pale(struct Registro **registros, int *numTiradas);
void Tripleta(struct Registro **registros, int *numTiradas);
void Numero(struct Registro **registros, int *numTiradas);

int main()
{
    int opcion;
    int opcionJuego;
    struct Registro *registros = NULL;
    int numTiradas = 0;

    srand((unsigned int)time(NULL));

    do
    {
        // Menú de opciones
        printf("\n0. Salir \n");
        printf("1. Realizar tirada \n");
        printf("2. Historial\n");
        printf("3. Jugar\n");

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
         case 3:
            // Jugar
            printf("\n------------------------------------------\n");
            printf("1. Pale\n");
            printf("2. Tripleta\n");
            printf("3. Numero Especifico\n");

            printf("\nElige una opcion para jugar:");
            scanf("%d", &opcionJuego);

            jugar(&registros, &numTiradas, opcionJuego);
            break;
          default:
            // Opción no válida
            printf("\nOpcion no valida. Por favor, elige una opcion del 0 al 3\n");
            break;
        }

    } while (opcion != 0);

    // Liberar memoria antes de salir
    clear(&registros);

    return 0;
}

// Implementaciones de funciones

void historial(struct Registro *registros, int numTiradas)
{
    // Mostrar historial de tiradas
    for (int i = 0; i < numTiradas; i++)
    {
        printf("Tirada %d - N1: %d %d %d\tFecha y hora: %d-%02d-%02d %02d:%02d:%02d\n", i + 1, registros[i].numerosAleatorios[0], registros[i].numerosAleatorios[1], registros[i].numerosAleatorios[2], registros[i].year, registros[i].month, registros[i].day, registros[i].hour, registros[i].minute, registros[i].second);
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

void jugar(struct Registro **registros, int *numTiradas, int opcion)
{
    switch (opcion)
    {
    case 1:
        Pale(registros, numTiradas);
        break;
    case 2:
        Tripleta(registros, numTiradas);
        break;
    case 3:
        Numero(registros, numTiradas);
        break;
    default:
        printf("Opcion no valida. Por favor, elige una opcion del 1 al 3\n");
    }
}

void Pale(struct Registro **registros, int *numTiradas)
{
    // Jugar un Pale (escoge dos números y busca si ha salido en alguna tirada)
    int numero1, numero2;

    printf("\nIngresa dos numeros para jugar el Pale (ejemplo: 12 34): ");
    scanf("%d %d", &numero1, &numero2);

    // Buscar en las tiradas anteriores
    for (int i = 0; i < *numTiradas; i++)
    {
        if ((*registros)[i].numerosAleatorios[0] == numero1 && (*registros)[i].numerosAleatorios[1] == numero2)
        {
            printf("Felicidades Has ganado con el Pale en la tirada %d.\n", i + 1);
            return;
        }
        else if ((*registros)[i].numerosAleatorios[0] == numero2 && (*registros)[i].numerosAleatorios[1] == numero1)
        {
            printf("Felicidades Has ganado con el Pale en la tirada %d.\n", i + 1);
            return;
        }
    }

    printf("Lo siento, no has ganado con el Pale.\n");
}

void Tripleta(struct Registro **registros, int *numTiradas)
{
    // Jugar una Tripleta (escoge tres números y busca si ha salido en alguna tirada)
    int numero1, numero2, numero3;

    printf("\nIngresa tres numeros para jugar la Tripleta (ejemplo: 12 34 56): ");
    scanf("%d %d %d", &numero1, &numero2, &numero3);

    // Buscar en las tiradas anteriores
    for (int i = 0; i < *numTiradas; i++)
    {
        if ((*registros)[i].numerosAleatorios[0] == numero1 && (*registros)[i].numerosAleatorios[1] == numero2 && (*registros)[i].numerosAleatorios[2] == numero3)
        {
            printf("Felicidades Has ganado con la Tripleta en la tirada %d.\n", i + 1);
            return;
        }
    }

    printf("Lo siento, no has ganado con la Tripleta.\n");
}

void Numero(struct Registro **registros, int *numTiradas)
{
    // Jugar un Número específico (escoge un número y busca si ha salido en alguna tirada)
    int numero;

    printf("\nIngresa un numero para jugar (ejemplo: 42): ");
    scanf("%d", &numero);

    // Buscar en las tiradas anteriores
    for (int i = 0; i < *numTiradas; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((*registros)[i].numerosAleatorios[j] == numero)
            {
                printf("Felicidades Has ganado con el Numero en la tirada %d.\n", i + 1);
                return;
            }
        }
    }

    printf("Lo siento, no has ganado con el Numero.\n");
}