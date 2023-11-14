#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

struct Registro  //Estructura de datos que especifica los datos que se van a guardar cada vez que se ejecute una tirada
{
    int numerosAleatorios[3];
    int year, month, day, hour, minute, second;
    float apuesta;
};

// Funciones
void historial(struct Registro *registros, int numTiradas);
void tirar(struct Registro **registros, int *numTiradas);
void jugar(struct Registro **registros, int *numTiradas);
void Pale(struct Registro **registros, int *numTiradas);
void Tripleta(struct Registro **registros, int *numTiradas);
void Numero(struct Registro **registros, int *numTiradas);
void guardarDatos(struct Registro *registros, int numTiradas);
int cargarDatos(struct Registro **registros);
void clear(struct Registro **registros);

int main()
{
    int opcion;
    struct Registro *registros = NULL; //Se utiliza para declarar un puntero en la estructura registro y lo inicializa en NUll, asi se asegura que no tenga memoria dentro
    int numTiradas = 0;

    numTiradas = cargarDatos(&registros);

    srand((unsigned int)time(NULL)); /*Este es un nuevo tipo de linea de comando ya que una depende de la otra para realizarse, 
    primero el timeNull devuelve la fecha actual a 1 de Ene de 1970 que luego se cambiara cada vez que se ejecute el programa, 
    segundo esta el unsigned int el cual convertira el timeNull en un entero sin asignar y por ultimo srand 
    es una funcion de numeros aleatorios el cual convertira el entero sin asignar en la base de los numeros aleatorios*/

    do
    {
        // Menú de opciones
        printf("\n0. Salir\n");
        printf("1. Realizar tirada\n");
        printf("2. Historial\n");
        printf("3. Jugar\n");

        printf("\nElige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 0:
            // Salir del programa
            printf("\nAdios y vuelva pronto.\n");
            break;
        case 1:
            // Realizar tirada
            printf("\nTirada realizada y almacenada.\n");
            tirar(&registros, &numTiradas);
            break;
        case 2:
            // Ver historial de tiradas
            printf("\nHistorial\n------------------\n");
            historial(registros, numTiradas);
            break;
        case 3:
            // Abrir menu de juego
            jugar(&registros, &numTiradas);
            break;
        default:
            // Opción no válida
            printf("\nOpcion no valida. Por favor, elige una opcion del 0 al 3\n");
            break;
        }

    } while (opcion != 0); //Mientras que el valor no sea 0 el programa continuara

    // Guardar datos antes de salir
    guardarDatos(registros, numTiradas);

    // Liberar memoria antes de salir
    clear(&registros);

    return 0;
}

void historial(struct Registro *registros, int numTiradas)
{
    // Mostrar historial de tiradas
    for (int i = 0; i < numTiradas; i++) //Bucle que sirve para imprimir cada numero de tiradas
    {
        printf("Tirada %d - N1: %d %d %d\tFecha y hora: %d-%02d-%02d %02d:%02d:%02d\n", i + 1, registros[i].numerosAleatorios[0], registros[i].numerosAleatorios[1], registros[i].numerosAleatorios[2], registros[i].year, registros[i].month, registros[i].day, registros[i].hour, registros[i].minute, registros[i].second);
        printf("\n-----------------------------------------\n");
    }
}

void tirar(struct Registro **registros, int *numTiradas)
{
    // Realizar una nueva tirada y almacenarla en registros
    time_t tiempoActual;
    time(&tiempoActual);

    struct tm *infoTiempo = localtime(&tiempoActual); //guarda la hora local de la maquina en la estructura con el nombre infoTiempo

    (*numTiradas)++; //aumenta en 1 el numero de tiradas

    // Reasignar memoria para la nueva tirada
    struct Registro *temp = realloc(*registros, sizeof(struct Registro) * (*numTiradas));
    if (temp == NULL) //Si los datos que se ingresan vienen vacios entonces es un error
    {
        // Manejar error si la asignación de memoria falla
        printf("Error al asignar memoria para la nueva tirada.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        *registros = temp;
    }

    // Preguntar al usuario la cantidad que quiere apostar
    printf("Ingresa la cantidad que quieres apostar en esta tirada: ");
    scanf("%f", &(*registros)[*numTiradas - 1].apuesta);

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

void jugar(struct Registro **registros, int *numTiradas)
{
    int opcionJuego;

    //Menu de juego
    printf("\n------------------------------------------\n");
    printf("1. Pale\n");
    printf("2. Tripleta\n");
    printf("3. Numero Especifico\n");
    printf("\nElige una opcion para jugar:");

    scanf("%d", &opcionJuego);

    switch (opcionJuego)
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
        if ((*registros)[i].numerosAleatorios[0] == numero1 && (*registros)[i].numerosAleatorios[1] == numero2) //Si 3 numeros ingresados coinciden con la tirada entonces gana
        {
            printf("Felicidades, has ganado con el Pale en la tirada %d. Cantidad ganada: %.2f\n", i + 1, (*registros)[i].apuesta * 2);
            return;
        }
        else if ((*registros)[i].numerosAleatorios[0] == numero2 && (*registros)[i].numerosAleatorios[1] == numero1) 
        {
            printf("Felicidades, has ganado con el Pale en la tirada %d. Cantidad ganada: %.2f\n", i + 1, (*registros)[i].apuesta * 2);
            return;
        }
    }

    printf("Lo siento, no has ganado con el Pale.\n"); //En caso de no coincidir pierde
}

void Tripleta(struct Registro **registros, int *numTiradas)
{
    // Jugar una Tripleta (escoge tres números y busca si ha salido en alguna tirada)
    int numero1, numero2, numero3;

    printf("\nIngresa tres numeros para jugar la Tripleta (ejemplo: 12 34 56): ");
    scanf("%d %d %d", &numero1, &numero2, &numero3);

    // Buscar en las tiradas anteriores
    for (int i = 0; i < *numTiradas; i++) //Analiza las tiradas para compararlas con las ingresadas
    {
        if ((*registros)[i].numerosAleatorios[0] == numero1 && (*registros)[i].numerosAleatorios[1] == numero2 && (*registros)[i].numerosAleatorios[2] == numero3) //Si 2 numeros ingresados coinciden con la tirada entonces gana
        {
            printf("Felicidades, has ganado con la Tripleta en la tirada %d. Cantidad ganada: %.2f\n", i + 1, (*registros)[i].apuesta * 3);
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
        for (int j = 0; j < 3; j++) //Analiza los 3 numeros de la tirada
        {
            if ((*registros)[i].numerosAleatorios[j] == numero) //Si un numero ingresado coincide con la tirada entonces gana
            {
                printf("Felicidades, has ganado con el Numero en la tirada %d. Cantidad ganada: %.2f\n", i + 1, (*registros)[i].apuesta * 1.5);
                return;
            }
        }
    }

    printf("Lo siento, no has ganado con el Numero.\n");
}

// Función para guardar los datos en el disco
void guardarDatos(struct Registro *registros, int numTiradas)
{
    FILE *archivo = fopen("datos.dat", "wb"); //Abre el archivo donde se guardaran los datos de las tiradas
    
    if (archivo == NULL) //Si no existe el archivo o no lo encuentra entonces habra un error
    {
        printf("Error al abrir el archivo para escritura.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numTiradas; i++) //Al existir el archivo guardara la estructura de datos que en este caso son las tiradas
    {
        fwrite(&registros[i], sizeof(struct Registro), 1, archivo);
    }

    fclose(archivo); //Cierra el archivo
}
// Función para cargar los datos desde el disco
int cargarDatos(struct Registro **registros)
{
    FILE *archivo = fopen("datos.dat", "rb");  //En caso de no existir un archivo el programa creara uno en donde guardarlos
    if (archivo == NULL)
    {
        printf("No se encontro un archivo existente. Se crearan nuevos datos.\n"); 
        return 0;
    }

    fseek(archivo, 0, SEEK_END); //Buscara el final del archivo
    int numTiradas = ftell(archivo) / sizeof(struct Registro); //Identifica la longitud en Bytes del archivo
    fseek(archivo, 0, SEEK_SET); //Establece el principio del archivo

    *registros = malloc(sizeof(struct Registro) * numTiradas); /*Reserva memoria dinámica para almacenar todas las estructuras de registro y se debe utilizar un doble puntero 
    para que la dirección de memoria principal pueda actualizarse dentro de la función.*/
    if (*registros == NULL)
    {
        printf("Error al asignar memoria para cargar los datos.\n");
        fclose(archivo);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numTiradas; i++)
    {
        fread(&(*registros)[i], sizeof(struct Registro), 1, archivo); //Lee la estructura de datos y la guarda
    }

    fclose(archivo);

    return numTiradas;
}
