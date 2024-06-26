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

int move_matrix(int m, int n, char matrix[n][m], int x, int y, int count)
{
    if (x >= m - 1 || y >= n || x < 0 || y < 0 || matrix[y][x] == '#')
        return 1;
    
    if (matrix[y][x] == 'd')
    {
        printf("Apos correr %d metros e quase desistir por causa da distância, Rebeka conseguiu escapar!\n", count);
        return 0;
    }

    char c = matrix[y][x];

    matrix[y][x] = '#';

    int v = move_matrix(m, n, matrix, x, y + 1, count + 1);
    
    if(v)
        v = move_matrix(m, n, matrix, x + 1, y, count + 1);
    
    if (v)
        v = move_matrix(m, n, matrix, x - 1, y, count + 1);
    
    if (v)
        v = move_matrix(m, n, matrix, x, y - 1, count + 1);

    matrix[y][x] = c;

    return v;
}

int main()
{
    int n, m;
    scanf("%dx%d", &n, &m);

    m++;

    char matrix[n][m];

    for (int i = 0; i < n; i++)
        scanf(" %s", matrix[i]);

    int x, y;

    start(m, n, matrix, &x, &y);

    if (move_matrix(m, n, matrix, x, y, 0))
        printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    

    return 0;
}