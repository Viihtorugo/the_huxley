#include <stdio.h>

int sum (int n)
{
    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);

        if (num % 2 == 0)
        {
            soma = soma + 1;
        }
        else
        {
            soma = soma - 1;
        }
    }
    
    return soma;
}

int main ()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", sum(n));

    return 0;
}