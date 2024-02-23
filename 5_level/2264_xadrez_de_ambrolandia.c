#include <stdio.h>

int count_move (int y, int x, int n, int matrix[n][n])
{
    int count = 0;

    for (int i = y + 1; i < n; i++)
    {
        if (matrix[i][x] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    for (int i = y - 1; i >= 0; i--)
    {
        if (matrix[i][x] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    for (int i = x + 1; i < n; i++)
    {
        if (matrix[y][i] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    for (int i = x - 1; i >= 0; i--)
    {
        if (matrix[y][i] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    

    for (int i = 1; (i + y < n) && (i + x < n); i++)
    {
        if (matrix[i + y][i + x] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    for (int i = 1; (y - i >= 0) && (x - i >= 0); i++)
    {
        if (matrix[y - i][x - i] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    for (int i = 1; (y + i < n) && (x - i >= 0); i++)
    {
        if (matrix[y + i][x - i] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }

    for (int i = 1; (y - i >= 0) && (x + i < n); i++)
    {
        if (matrix[y - i][x + i] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    
    return count;
}

int max_move (int n, int matrix[n][n])
{
    int max = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                int count = count_move(i, j, n, matrix);

                if (count > max)
                    max = count;
            }
        }
        
    }
    
    return max;
}

int main ()
{
    int n;
    scanf("%d", &n);

    int matrix[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
        
    printf("%d\n", max_move(n, matrix));

    return 0;
}