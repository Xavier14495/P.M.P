#include <stdio.h>
#include <stdlib.h>
#define MAX_NOMBRES 50
#define MAX_CARACTERES 100

// Definición de la estructura de la tabla
struct Tabla
{
    char nombres[MAX_NOMBRES][MAX_CARACTERES];
    int cantidadNombres;
};

// Función para guardar la tabla en un archivo
void guardarTablaEnArchivo(struct Tabla tabla, const char *nombreArchivo)
{
    FILE *archivo;
    archivo = fopen(nombreArchivo, "wb");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para escritura.\n");
        return;
    }

    // Escribir la estructura de la tabla en el archivo
    fwrite(&tabla, sizeof(struct Tabla), 1, archivo);

    fclose(archivo);
}

// Función para leer la tabla desde un archivo
struct Tabla leerTablaDesdeArchivo(const char *nombreArchivo)
{
    struct Tabla tabla;
    FILE *archivo;
    archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para lectura.\n");
        tabla.cantidadNombres = 0; // Devolver una tabla vacía si hay un error al leer el archivo
        return tabla;
    }

    // Leer la estructura de la tabla desde el archivo
    fread(&tabla, sizeof(struct Tabla), 1, archivo);
    fclose(archivo);

    return tabla;
}

// Función para crear una nueva tabla con nombres
struct Tabla crearNuevaTabla()
{
    struct Tabla nuevaTabla;
    int cantidadNombres;

    printf("¿Cuántos nombres desea ingresar? (máximo %d): ", MAX_NOMBRES);
    scanf("%d", &cantidadNombres);

    nuevaTabla.cantidadNombres = cantidadNombres;

    for (int i = 0; i < cantidadNombres; i++)
    {
        printf("Ingrese el nombre %d: ", i + 1);
        scanf("%s", nuevaTabla.nombres[i]);
    }

    return nuevaTabla;
}

// Función para mostrar la tabla
void mostrarTabla(struct Tabla tabla)
{
    printf("La tabla contiene los siguientes nombres:\n");
    for (int i = 0; i < tabla.cantidadNombres; i++)
    {
        printf("%d. %s\n", i + 1, tabla.nombres[i]);
    }
}

// Función para mostrar el menú y opciones disponibles
void mostrarMenu()
{
    printf("\n1. Crear y guardar una nueva tabla en un archivo\n");
    printf("2. Modificar nombre del archivo\n");
    printf("3. Leer una tabla desde un archivo\n");
    printf("4. Salir\n");
}

int main()
{
    struct Tabla tablaActual;
    tablaActual.cantidadNombres = 0;
    int opcion;
    char nombreArchivo[MAX_CARACTERES];

    do
    {
        mostrarMenu();
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            tablaActual = crearNuevaTabla();
            printf("Ingrese el nombre del archivo para guardar la tabla: ");
            scanf("%s", nombreArchivo);
            guardarTablaEnArchivo(tablaActual, nombreArchivo);
            printf("Tabla guardada en el archivo.\n");
            break;

        case 2:
            printf("Ingrese el nuevo nombre del archivo: ");
            scanf("%s", nombreArchivo);
            guardarTablaEnArchivo(tablaActual, nombreArchivo);
            printf("Nombre del archivo modificado.\n");
            break;

        case 3:
            printf("Ingrese el nombre del archivo para leer la tabla: ");
            scanf("%s", nombreArchivo);
            tablaActual = leerTablaDesdeArchivo(nombreArchivo);
            printf("Tabla leída desde el archivo:\n");
            mostrarTabla(tablaActual);
            break;

        case 4:
            printf("Saliendo del programa.\n");
            break;

        default:
            printf("Opción no válida. Por favor, seleccione una opción válida.\n");
            break;
        }
    }
    while (opcion != 4);

    return 0;
}