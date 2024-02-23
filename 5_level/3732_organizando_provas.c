#include <stdio.h>

void solve ()
{
    int n = 1, i = 0, count = 1;

    char string[4][21];

    while (1)
    {
        scanf("%d", &n);

        if (n == 0)
            break;

        scanf(" %[^\n]s", string[n - 1]);

        i++;

        if (i == 4)
        {
            printf("%d)\n", count);
            count++;

            printf("a)%s c)%s\n", string[0], string[2]);
            printf("b)%s d)%s\n", string[1], string[3]);

            i = 0;
        }
    }
}

int main ()
{
    solve ();

    return 0;
}