#include <stdio.h>

void build_matrix (int n, int matrix[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            matrix[i][j] = i + 1;
            matrix[j][i] = i + 1;
        }
    }
    
}

int main ()
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    build_matrix(n, matrix);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d", matrix[i][j]);

            if (j + 1 == n)
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