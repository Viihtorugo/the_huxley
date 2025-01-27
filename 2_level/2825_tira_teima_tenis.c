#include <stdio.h>

int main ()
{
    int x, y;
    printf("Digite as coordenadas (X, Y) separadas por ENTER:\n");
    scanf("%d %d", &x, &y);

    if (x >= 0 && x <= 432)
    {
        if (y >= 0 && y <= 468)
        {
            printf("BOLA DENTRO\n");
        }
        else
        {
            printf("BOLA FORA\n");
        }
    }
    else
    {
        printf("BOLA FORA\n");
    }

    return 0;
}