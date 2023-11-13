<<<<<<< HEAD
#include<stdio.h>

int main()
{
    float P, S, R;

    printf("\nIngrese las ventas de los tres vendedores: ");
    scanf("%f %f %f", &P, &S, &R);

    if (P > S)
        if (P > R)
             if (S > R)
             
             printf("\n\n El orden es P, S Y R: %8.2f %8.2f %8.2f", P, S, R);
             

             else
             
             printf("\n\n El orden es P, R Y S: %8.2f %8.2f %8.2f", P, R, S);
             
         else
         printf("\n\n El orden es R, P Y S: %8.2f %8.2f %8.2f", R, P, S);
     
     else

     if (S > R)

         if (P > R)
         printf("\n\n El orden es S, P Y R: %8.2f %8.2f %8.2f", S, P, R);       

         else
         printf("\n\n El orden es S, R Y P: %8.2f %8.2f %8.2f", S, R, P);    
     
     else
     printf("\n\n El orden es R, S Y P: %8.2f %8.2f %8.2f", R, S, P);
    
    return 0;
}
=======
#include<stdio.h>

int main()
{
    float P, S, R;

    printf("\nIngrese las ventas de los tres vendedores: ");
    scanf("%f %f %f", &P, &S, &R);

    if (P > S)
        if (P > R)
             if (S > R)
             
             printf("\n\n El orden es P, S Y R: %8.2f %8.2f %8.2f", P, S, R);
             

             else
             
             printf("\n\n El orden es P, R Y S: %8.2f %8.2f %8.2f", P, R, S);
             
         else
         printf("\n\n El orden es R, P Y S: %8.2f %8.2f %8.2f", R, P, S);
     
     else

     if (S > R)

         if (P > R)
         printf("\n\n El orden es S, P Y R: %8.2f %8.2f %8.2f", S, P, R);       

         else
         printf("\n\n El orden es S, R Y P: %8.2f %8.2f %8.2f", S, R, P);    
     
     else
     printf("\n\n El orden es R, S Y P: %8.2f %8.2f %8.2f", R, S, P);
    
    return 0;
}
>>>>>>> ffe060a60c1e42f9d38897794281b50bb8b0788c
