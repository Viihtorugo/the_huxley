#include <stdio.h>

int main ()
{
    double n;
    scanf("%lf", &n);

    if (n > 7)
    {
        printf("bolinha verde\n");
    }
    else if (n >= 5 && n <= 7)
    {
        printf("bolinha amarela\n");
    }
    else
    {
        printf("bolinha vermelha\n");
    }
}