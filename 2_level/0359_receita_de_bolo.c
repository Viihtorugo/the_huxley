#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    a = a / 2;
    b = b / 3;
    c = c / 5;

    int r;

    if (a < b)
    {
        r = a;
    }
    else
    {
        r = b;
    }

    if (r > c)
    {
        r = c;
    }

    printf("%d\n", r);

    return 0;
}