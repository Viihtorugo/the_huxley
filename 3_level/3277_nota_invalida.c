#include <stdio.h>

char *validade(int n)
{
    if (n < 0 || n > 10)
    {
        return "invalida\n";
    }
    else
    {
        return "valida\n";
    }
}

int main ()
{
    int n;
    scanf("%d", &n);

    printf("%s", validade(n));

    return 0;
}