#include <stdio.h>

int ver_order(long long int n)
{
    while (n != 0)
    {
        int u = n % 10;
        n = n / 10;

        if (u < n % 10)
            return 0;
    }

    return 1;
}

long long int new_number(long long int number, int dig, int rep)
{
    if (number % 10 <= dig)
    {
        dig = number % 10;
        number = number / 10;

        return new_number(number, dig, rep + 1);
    }
    else
    {
        while (rep != 0)
        {
            number = number * 10;
            rep--;
        }

        return number - 1;
    }
}

int main()
{
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        long long int n;
        scanf("%lld", &n);

        while (ver_order(n) == 0 && n >= 1)
        {
            n = new_number(n / 10, n % 10, 1);
        }

        printf("Caso #%d: %lld\n", i + 1, n);
    }

    return 0;
}