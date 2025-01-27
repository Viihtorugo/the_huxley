#include <stdio.h>

int main ()
{
    int n;
    scanf("%d", &n);

    int num1, num2;
    char op;
    scanf("%d %c %d", &num1, &op, &num2);

    if (op == '+')
    {
        if (num1 + num2 > n)
        {
            printf("OVERFLOW\n");
        }
        else
        {
            printf("OK\n");
        }
    }
    else
    {
        if (num1 * num2 > n)
        {
            printf("OVERFLOW\n");
        }
        else
        {
            printf("OK\n");
        }
    }

    return 0;
}