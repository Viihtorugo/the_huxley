#include <stdio.h>

int cresc(int a[])
{
    for (int i = 1; i < 5; i++)
        if (a[i - 1] > a[i])
            return 0;

    return 1;
}

int decresc(int a[])
{
    for (int i = 1; i < 5; i++)
        if (a[i - 1] < a[i])
            return 0;

    return 1;
}

int main ()
{
    int a[5];
    
    for (int i = 0; i < 5; i++)
        scanf("%d", &a[i]);

    int c = cresc(a);
    int d = decresc(a);

    if (c == 1 && d == 0)
    {
        printf("C\n");
    }
    else if (c == 0 && d == 1)
    {
        printf("D\n");
    }
    else
    {
        printf("N\n");
    }

    return 0;
}