#include <stdio.h>

void rainhas_bactracking(int k, int n, int *col, int *count)
{

    if (n == 9)
    {
        *count = *count + 1;

        printf("%d      ", *count);

        for (int i = 1; i <= 8; i++)
        {
            printf("%d", col[i]);

            if (i + 1 != 9)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
        }

        return;
    }

    int l = (k % 8) + 1;

    while (l <= 8)
    {
        int i;

        for (i = 1; i <= 8; i++)
        {
            if (col[i] != 0)
            {
                int v1 = col[i] - l;

                if (v1 < 0)
                    v1 *= -1;

                int v2 = i - k;

                if (v2 < 0)
                    v2 *= -1;

                if (col[i] == l || v1 == v2)
                    break;
            }
        }

        if (i == 9)
        {
            col[(n % 8) + 1] = l;
            rainhas_bactracking(l, n + 1, col, count);
            col[(n % 8) + 1] = 0;
        }

        l++;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x, y, count = 0;
        scanf("%d %d", &x, &y);

        int col[9];

        for (int j = 0; j <= 8; j++)
            col[j] = 0;

        col[y] = x;

        printf("SOLN       COLUMN\n");
        printf("#      1 2 3 4 5 6 7 8\n\n");

        rainhas_bactracking(x + 1, 2, col, &count);
    }

    return 0;
}