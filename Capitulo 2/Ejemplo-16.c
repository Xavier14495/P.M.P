<<<<<<< HEAD
#include<stdio.h>

int main()
{
    int CLA, CAT, ANT, RES;
    
    printf("\nIngrese la clave, categoria y antiguedad del trabajador:");
    scanf("%d %d %d", &CLA, &CAT, &ANT);
    
    switch(CAT)
    {
        case 3:
        
        case 4: if (ANT >= 5)
        
        RES = 1;
        
        else
        
        RES = 0;
        break;
        
        case 2: if (ANT >= 7)
        
        RES = 1;
        
        else
        
        RES = 0;
        break;
        
        default: RES = 0;
        break;
    }
    
    if (RES)
    
    printf("\nEl trabajador con clave %d reune las condiciones para el puesto", CLA);
    
    else
    
    printf("\nEl trabajador con clave %d no reune las condiciones para el puesto", CLA);

    return 0;
}
=======
#include<stdio.h>

int main()
{
    int CLA, CAT, ANT, RES;
    
    printf("\nIngrese la clave, categoria y antiguedad del trabajador:");
    scanf("%d %d %d", &CLA, &CAT, &ANT);
    
    switch(CAT)
    {
        case 3:
        
        case 4: if (ANT >= 5)
        
        RES = 1;
        
        else
        
        RES = 0;
        break;
        
        case 2: if (ANT >= 7)
        
        RES = 1;
        
        else
        
        RES = 0;
        break;
        
        default: RES = 0;
        break;
    }
    
    if (RES)
    
    printf("\nEl trabajador con clave %d reune las condiciones para el puesto", CLA);
    
    else
    
    printf("\nEl trabajador con clave %d no reune las condiciones para el puesto", CLA);

    return 0;
}
>>>>>>> ffe060a60c1e42f9d38897794281b50bb8b0788c
