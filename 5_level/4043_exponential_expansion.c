#include <stdio.h>
#include <math.h>

long double pot (long double b, long double e)
{
    if (e == 0)
        return 1;

    return b * pot(b, e - 1);
}

long double fat (long double n)
{
    if (n == 0 || n == 1)
        return 1;

    return (long double)n * fat(n - 1);
}

int it (long double e, long double x)
{
    int i = 0;
    long double aux = 0;

    while (1)
    {
        aux += pot(x, i) / fat(i);

        printf("e^%.1Lf com %d iteracoes -> %.5Lf\n", x, i, aux);
        i++;

        if (fabs(aux - e) <= 1e-4)
            break;
    }

    return i - 1;
}

int main ()
{
    long double x;
    scanf("%Lf", &x);

    long double e = exp(x);
    
    printf("\nNumero de iteracoes -> %d\n", it(e, x));
}