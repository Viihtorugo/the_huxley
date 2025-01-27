#include <stdio.h>

int check(int y, int x, int n, int m, int matrix[][m])
{
    for (int i = y + 1; i < n; i++)
    {
        if (matrix[i][x] != 0)
        {
            return 1;
        }
    }

    return 0;
}

int check_zero(int y, int x, int n, int m, int matrix[][m])
{
    for (int i = y; i < n; i++)
    {
        for (int j = x; j >= 0; j--)
        {
            if (matrix[i][j] != 0)
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int matrix[n][m], v = 0, n_v = 0;

    for (int i = 0; i < n; i++)
    {
        int z = 0;

        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);

            if (v && matrix[i][j] != 0)
            {
                printf("N\n");
                return 0;
            }

            if (matrix[i][j] == 0)
                z++;
        }

        if (z == m)
        {
            n_v = i;
            v = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (check_zero(i, j - 1, n, m, matrix))
                {
                    printf("N\n");
                    return 0;
                }

                if (check(i, j, n, m, matrix))
                {
                    printf("N\n");
                    return 0;
                }

                break;
            }
        }
    }

    printf("S\n");

    return 0;
}