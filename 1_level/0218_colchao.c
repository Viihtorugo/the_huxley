#include <stdio.h>

int main ()
{
    int a, b, c, h, l;
    scanf("%d %d %d %d %d", &a, &b, &c, &h, &l);

    int porta = h * l;
    int v1 = 0, v2 = 0;

    if (a <= h)
    {
        v1 = 1;
        a = 0;
    }
    else if (b <= h)
    {
        v1 = 1;
        b = 0;
    }
    else if (c <= h)
    {
        v1 = 1;
        c = 0;
    }

    if (v1)
    {
        if (a == 0)
        {
            if (b <= l)
            {
                v2 = 1;
            }
            else if (c <= l)
            {
                v2 = 1;
            }
        }
        else if (b == 0)
        {
            if (b <= l)
            {
                v2 = 1;
            }
            else if (c <= l)
            {
                v2 = 1;
            }
        }
        else
        {
            if (b <= l)
            {
                v2 = 1;
            }
            else if (a <= l)
            {
                v2 = 1;
            }
        }
    }
    
    
    if (v1 && v2)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}