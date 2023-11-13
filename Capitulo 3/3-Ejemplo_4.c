#include<stdio.h>
#include<math.h>

int main()
{
    int NUM;
    long CUA, SUC = 0;

    printf("\nIngrese un numero entero -0 para terminar-:\t"); //Pide ingresar un numero entero y de colocar un cero terminara el programa//
    scanf("%d", &NUM); //Escanea el valor colocado//
    
    while (NUM) //Mientras la variable NUM no sea 0 realizara la operacion//
    {
        CUA = pow (NUM, 2);  //pow es un comando para elevar un numero, en este caso el numero ingresado anterior mente se elevara al cuadrado//
        
        printf("%d al cubo es %ld", NUM, CUA); //Imprime el resultado obtenido de la operacion//
        
        SUC = SUC + CUA; //Suma el valor de SUC y le suma el valor de CUA obtenido anteriormente//
        
        printf("\nIngrese un numero entero -0 para terminar-:\t");  //Pide ingresar nuevamente un numero entero, en caso de querer terminar colocar un 0//
        scanf("%d", &NUM); //Escanea el valor colocado//
        
    }
    
    printf("\nLa suma de los cuadrados es %ld", SUC); //Imprime el resultado de las sumas de los cuadrados//
    return 0;
}