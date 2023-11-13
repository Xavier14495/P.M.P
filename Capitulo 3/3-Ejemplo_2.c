#include<stdio.h>

int main()
{
    int I, N, NUM, SUM;
    SUM = 0;
    
    printf("Ingrese el número de datos:\t");  //Pide ingresar el numero de datos//
    scanf("%d", &N);                          //Escanea el dato ingresado y lo dirige a la direccion N//
    
    for (I=1; I<=N; I++)                      //Repite en bucle el programa hasta que ya no se cumpla la condicion. Inicia en 1 y pregunta si es mayor igual a N, de no serlo repite y le suma 1 a la I//
    {
        printf("Ingrese el dato número %d:\t", I);  //Pide ingresar el dato numerico//
        scanf("%d", &NUM);                          //Escanea el dato ingresado y lo dirige a la direccion NUM//
        
        if (NUM > 0)  //Si la variable NUM es mayor a 0 entonces realizara la operacion que esta abajo//
        
        SUM = SUM + NUM;
        
    }
    
    printf("\nLa suma de los números positivos es: %d", SUM);  // Impirme en la pantalla el resultado//

    return 0;
}