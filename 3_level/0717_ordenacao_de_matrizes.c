#include <stdio.h>

void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void sort(int n, int m, int matrix[][m])
{
    for (int k = 0; k < n * m; k++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (j - 1 == -1)
                {
                    if (i != 0 && matrix[i - 1][m - 1] > matrix[i][j])
                    {
                        swap(&matrix[i - 1][m - 1], &matrix[i][j]);
                    }
                }
                else
                {
                    if (matrix[i][j - 1] > matrix[i][j])
                        swap(&matrix[i][j - 1], &matrix[i][j]);
                }
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int matrix[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);

    sort(n, m, matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d", matrix[i][j]);

            if (j + 1 == m)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }

    return 0;
}