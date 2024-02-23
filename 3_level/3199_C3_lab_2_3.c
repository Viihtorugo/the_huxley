#include <stdio.h>

int main()
{
    int n1, n2;
    scanf("%d %d", &n1, &n2);

    if (n2 == 0)
    {
        printf("-nan\n");
        return 0;
    }

    printf("%d", n1 / n2);

    long double d = (long double)n1 / (long double)n2;

    int dec = ((d - (n1 / n2)) * 10000000);

    if (dec % 10 > 3)
    {
        dec += 10;
    }

    dec /= 10;

    while (dec % 10 == 0)
        dec /= 10;

    printf(".%d\n", dec);

    return 0;
}