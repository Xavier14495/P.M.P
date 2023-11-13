#include <stdio.h>
#include <string.h>

typedef struct
{
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado
{
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion;
};

void Leer(struct empleado *a)
{
    printf("\nIngrese el nombre del empleado: ");
    fgets(a->nombre, 20, stdin);
    strtok(a->nombre, "\n"); // Elimina el salto de línea de la entrada

    printf("Ingrese el departamento de la empresa: ");
    fgets(a->departamento, 20, stdin);
    strtok(a->departamento, "\n");

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    getchar(); // Captura el salto de línea después del scanf

    printf("--Ingrese a direccion del empleado--");

    printf("\n\tCalle: ");
    fgets(a->direccion.calle, 20, stdin);
    strtok(a->direccion.calle, "\n");

    printf("\tNumero: ");
    scanf("%d", &a->direccion.numero);
    getchar();

    printf("\tCodigo Postal: ");
    scanf("%d", &a->direccion.cp);
    getchar();

    printf("\tLocalidad: ");
    fgets(a->direccion.localidad, 20, stdin);
    strtok(a->direccion.localidad, "\n");
}

int main()
{
    struct empleado e0 = {"Arturo", "Compras", 15500.75, {"San Jeronimo", 120, 3490, "Toluca"}};
    struct empleado e1, e3, e4;

    printf("\nIngrese el nombre del empleado 1: ");
    fgets(e1.nombre, 20, stdin);
    strtok(e1.nombre, "\n");

    printf("Ingrese el departamento de la empresa: ");
    fgets(e1.departamento, 20, stdin);
    strtok(e1.departamento, "\n");

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1.sueldo);
    getchar();

    printf("--Ingrese la dirección del empleado--");
    printf("\n\tCalle: ");
    fgets(e1.direccion.calle, 20, stdin);
    strtok(e1.direccion.calle, "\n");

    printf("\tNumero: ");
    scanf("%d", &e1.direccion.numero);
    getchar();

    printf("\tCódigo Postal: ");
    scanf("%d", &e1.direccion.cp);
    getchar();

    printf("\tLocalidad: ");
    fgets(e1.direccion.localidad, 20, stdin);
    strtok(e1.direccion.localidad, "\n");

    printf("\nIngrese el nombre del empleado 3: ");
    fgets(e3.nombre, 20, stdin);
    strtok(e3.nombre, "\n");

    printf("Ingrese el departamento de la empresa: ");
    fgets(e3.departamento, 20, stdin);
    strtok(e3.departamento, "\n");

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    getchar();

    printf("--Ingrese la dirección del empleado--");
    printf("\n\tCalle: ");
    fgets(e3.direccion.calle, 20, stdin);
    strtok(e3.direccion.calle, "\n");

    printf("\tNumero: ");
    scanf("%d", &e3.direccion.numero);
    getchar();

    printf("\tCódigo Postal: ");
    scanf("%d", &e3.direccion.cp);
    getchar();

    printf("\tLocalidad: ");
    fgets(e3.direccion.localidad, 20, stdin);
    strtok(e3.direccion.localidad, "\n");

    Leer(&e4);

    printf("\nDatos del empleado 1\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s", e0.nombre, e0.departamento, e0.sueldo, e0.direccion.calle, e0.direccion.numero, e0.direccion.cp, e0.direccion.localidad);

    printf("\nDatos del empleado 4\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s", e4.nombre, e4.departamento, e4.sueldo, e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);

    return 0;
}