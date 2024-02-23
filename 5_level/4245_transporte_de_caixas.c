#include <stdio.h>

int move (int n, int v)
{
    if (n != 0)
    {
        int c, l, h;
        scanf("%d %d %d", &c, &l, &h);

        if (h <= 10)
        {
            printf("%d\n", c*l*h);
            v = 1;
        }

        return move(n - 1, v);
    }

    return v;
}

int main ()
{
    int n;
    scanf("%d", &n);

    if (move(n, 0) == 0)
    {
        printf("Nenhuma caixa passa pelo tunel!\n");
    }

    return 0;
}