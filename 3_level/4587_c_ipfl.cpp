#include <stdio.h>

void swap(char *x, char *y)
{
    char aux = *x;
    *x = *y;
    *y = aux;
}

int main()
{
    int n;
    scanf("%d", &n);

    char string[(2 * n) + 1];
    scanf(" %s", string);

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int x, y, z;

        scanf("%d %d %d", &x, &y, &z);

        if (x == 1)
        {
            swap(&string[y - 1], &string[z - 1]);
        }
        else if (x == 2)
        {
            for (int i = 0; i < n; i++)
            {
                swap(&string[i], &string[n + i]);
            }
        }
    }

    printf("%s\n", string);

    return 0;
}