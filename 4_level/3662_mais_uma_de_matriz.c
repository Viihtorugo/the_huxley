#include <stdio.h>

void solved (int n, int m, int matrix[n][m])
{
    int sum;

    for (int i = 0; i < n; i++)
    {
        sum = 0;

        for (int j = 0; j < m; j++)
        {
            sum += matrix[i][j];
        }
        
        printf("Linha %d: %d\n", i, sum);
    }

    for (int j = 0; j < m; j++)
    {
        sum = 0;
        
        for (int i = 0; i < n; i++)
        {
            sum += matrix[i][j];
        }
        
        printf("Coluna %d: %d\n", j, sum);
    }
    

    if (n == m)
    {
        sum = 0;
        
        for (int i = 0; i < n; i++)
            sum += matrix[i][i];

        printf("Diagonal principal: %d\n", sum);
    }
        
}

int main ()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int matrix[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);

    solved(n, m, matrix);

    return 0;
}