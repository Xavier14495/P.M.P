#include<stdio.h>

int main()
{
    float PAG, SPA;
    SPA = 0;

    printf("Ingrese el primer pago:\t"); //Pide ingresar el primer pago//
    scanf("%f", &PAG);                   //Escanea el dato y lo almacena en la direccion PAG//
    
    while (PAG)                          //Mientras la variable PAG no sea igual a 0 se realizara la operacion que esta dentro//
    {
        SPA = SPA + PAG;                 //Suma SPA valor 0 + el pago ingresado//
        
        printf("Ingrese el siguiente pago:\t ");    //Pide ingresar un nuevo pago//
        scanf("%f", &PAG);                          //Escanea el pago y lo almacena en la direccion PAG//
        
    }
    
    printf("\nEl total de pagos del mes es: %.2f", SPA); //Imprime el total de pagos almacenados en SPA con solo 2 decimales//
    
    return 0;
}