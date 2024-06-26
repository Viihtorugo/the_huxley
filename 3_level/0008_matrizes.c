#include <stdio.h>

int main ()
{
    while (1)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0)
            return 0;

        long double matrix[n][m], t = 0;

        int count = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = count;
                t += count;
                count++;
            }
        }
        
        long double a = 0, b = 0, c = 0, d = 0, x = 0, y = 0;

        for (int i = 0; i < n; i++)
        {
            a += matrix[i][0];
            b += matrix[i][m - 1];
        }

        for (int i = 0; i < m; i++)
        {
            c += matrix[0][i];
            d += matrix[n - 1][i];
        }
        
        for (int i = 0; i < n; i++)
            x += matrix[i][i];

        int aux;

        if (n > m)
        {
            aux = m;
        }
        else
        {
            aux = n;
        }

        for (int i = 1; i <= aux; i++)
            y += matrix[n - i][m - i];
        
        long double div = n*m;

        //printf("%.2LF %.2LF %.2LF %.2LF\n", t, x, y, div);

        long double  r = (t - (x+y) + (a*b) - (c*d)) / div;
        
        printf("%.2LF\n", r);
    }
    
}