#include <stdio.h>

int backtracking(int i, int j, int n, int m, char map[][m], int *check, int count)
{
    if (i == n || j == m || map[i][j] == '|')
        return count;
    
    if(map[i][j] == 'o')
        count++;

    if(map[i][j] == '8')
        count+=2;

    if (i == n - 1 && j == m - 1)
    {
        *check = 1;
        return count;
    }

    int aux2 = backtracking(i, j + 1, n, m, map, check, count);
    int aux1 = backtracking(i + 1, j, n, m, map, check, count);

    if (aux1 > aux2)
        return aux1;
    
    return aux2;
}

void solved()
{
    int n, m;
    scanf("%d %d", &n, &m);

    char  map[n][m];
    for (int i = 0; i < n; i++)
        scanf(" %s", map[i]);
    
    int check = 0;

    int count = backtracking(0, 0, n, m, map, &check, 0);

    if (check)
    {
        printf("SIM\n");
    }
    else
    {
        printf("NAO\n");
    }

    printf("Valor maximo de moedas: %d\n", count);
}

int main ()
{
    
    solved();
    return 0;
}