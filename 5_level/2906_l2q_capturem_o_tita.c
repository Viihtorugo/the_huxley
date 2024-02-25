#include <stdio.h>

int check(int n, int m, int *c1, int *c2)
{
    while (*c1 < 50)
    {
        if (*c2 > *c1)
        {
            return 1;
        }

        *c1 += n;
        *c2 += m;
    }

    return 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int c1 = 5, c2 = 0;

    if (check(n, m, &c1, &c2))
    {
        printf("Capturamos ele, comandante!\n");
        printf("altura alcancada pelo tita: %d\n", c1);
        printf("altura alcancada pelo soldado: %d\n", c2);
    }
    else
    {
        printf("Comandante, a operacao falhou!\n");
        printf("altura alcancada pelo soldado: %d\n", c2);
    }

    return 0;
}