#include <stdio.h>

int main ()
{
    int m, a, b;
    scanf("%d %d %d", &m, &a, &b);

    int c = m - (a + b);

    if (a > c)
    {
        c = a;
    }

    if (b > c)
    {
        c = b;
    }

    printf("%d\n", c);

    return 0;
}