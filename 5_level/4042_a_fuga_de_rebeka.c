#include <stdio.h>
#include <limits.h>

void start(int m, int n, char matrix[n][m], int *x, int *y)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 'o')
            {
                *y = i;
                *x = j;
                return;
            }
        }
    }
}

void move_matrix(int m, int n, char matrix[n][m], int x, int y, int count, int *v, int array[])
{
    if (x >= m - 1 || y >= n || x < 0 || y < 0 || matrix[y][x] == '#' || count >= array[*v])
        return;
    
    if (matrix[y][x] == 'd')
    {
        array[*v] = count;
        *v += 1;
    }

    char c = matrix[y][x];

    matrix[y][x] = '#';

    move_matrix(m, n, matrix, x, y + 1, count + 1, v, array);
    move_matrix(m, n, matrix, x + 1, y, count + 1, v, array);
    move_matrix(m, n, matrix, x - 1, y, count + 1, v, array);
    move_matrix(m, n, matrix, x, y - 1, count + 1, v, array);

    matrix[y][x] = c;
}

int main()
{
    int n, m;
    scanf("%dx%d", &n, &m);

    m++;

    char matrix[n][m];

    for (int i = 0; i < n; i++)
        scanf(" %s", matrix[i]);

    int x, y, v = 0, array[1000000] = {INT_MAX};

    start(m, n, matrix, &x, &y);

    move_matrix(m, n, matrix, x, y, 0, &v, array);

    if (v == 0)
    {
        printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    }
    else
    {
        int m = INT_MAX;

        for (int i = 0; i < v; i++)
            if (m > array[i])
                m = array[i];

        printf("Apos correr %d metros e quase desistir por causa da distância, Rebeka conseguiu escapar!\n", m);
    }

    return 0;
}