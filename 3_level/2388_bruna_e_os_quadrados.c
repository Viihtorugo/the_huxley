#include <stdio.h>

int min (int a, int b, int c)
{
    int min = a;

    if (b <  min)
        min = b;

    if (c < min)
        min = c;

    return min;
}

int search_square(int n, int matrix[n][n])
{
    if (n == 1)
        return matrix[0][0];
    
    int m = 0;

    int aux[n][n];

    for (int i = 0; i < n; i++)
    {
        aux[0][i] = matrix[0][i];
        aux[i][0] = matrix[i][0];
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j])
            {
                aux[i][j] = 1 + min(aux[i - 1][j], aux[i][j - 1], aux[i - 1][j - 1]);
            }
            else
            {
                aux[i][j] = 0;
            }

            if (aux[i][j] > m)
                m = aux[i][j];
        }
    }

    return m*m;
}

int main()
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    printf("%d\n", search_square(n, matrix));

    return 0;
}