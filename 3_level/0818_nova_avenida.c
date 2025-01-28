#include <stdio.h>

int main ()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int r[n + 1][m], min = __INT_MAX__;


    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                r[i][j] = 0;
            }
            else
            {
                scanf("%d", &r[i][j]);
                r[i][j] = r[i][j] + r[i - 1][j];

                if (i == n)
                    if (min > r[i][j])
                        min = r[i][j];
            }
        }      
    }

    printf("%d\n", min);

    return 0;
}