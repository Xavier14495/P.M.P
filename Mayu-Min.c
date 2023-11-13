#include<stdint.h>

int main()
{
    char I[30];

    printf("\nIngrese el grupo de caracteres: ");
    getschar(&I[30]);

    printf("%c", I[30]);
    return 0;
}
