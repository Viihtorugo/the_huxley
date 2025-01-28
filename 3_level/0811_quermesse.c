#include <stdio.h>

int winner(int i, int n, int w)
{
    if (i <= n)
    {
        int num;
        scanf("%d", &num);

        if (w == 0 && i == num)
            w = i;

        return winner(i + 1, n, w);
    }

    return w;
}

int main()
{
    int n, i = 1;

    while (1)
    {
        scanf("%d", &n);

        if (n == 0)
            return 0;

        printf("Teste %d\n%d\n\n", i, winner(1, n, 0));

        i++;
    }
}