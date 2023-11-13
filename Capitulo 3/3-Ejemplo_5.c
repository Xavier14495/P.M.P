#include<stdio.h>

int main()
{
    float PAG, SPA = 0;

    printf("Ingrese el primer pago:\t"); //Pide ingresar el primer pago//
    scanf("%f", &PAG);                   //Escanea el pago y lo guarda en la direccion PAG//

    do  //Hace que el programa ejecute el comando dentro del parentesis//
    {
        SPA = SPA + PAG; //Suma el primer pago ingresado mas la variable SPA que es igual 0//

        printf("Ingrese el siguiente pago -0 para terminar-:\t");  //Pide ingresar un nuevo pago//
        scanf("%f", &PAG);  //Escanea el pago y lo almacena en la direccion PAG//
        
    }
    
    while (PAG);  //Si la variale pag es 0 realizara el programa de abajo//
     
    printf("\nEl total de pagos del mes es: %.2f", SPA); //Imprime el resultado del programa//

    return 0;
}