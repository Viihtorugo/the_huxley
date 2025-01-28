#include <stdio.h>

int main ()
{
    double p, a;
    scanf("%lf %lf", &p, &a);

    double imc = p / (a*a);

    printf("%.2lf\n", imc);

    if (imc > 25 || imc < 18)
    {
        printf("atencao\n");
    }
    else
    {
        printf("normal\n");
    }

    return 0;
}