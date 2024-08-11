#include <stdio.h>

void solved(int i, int n, int x, int y)
{
    if (i < n)
    {
        int point_x, point_y;
        scanf("%d %d", &point_x, &point_y);

        if (point_x == x || point_y == y)
        {
            printf("divisa\n");
        }
        else if (point_x > x)
        {
            if (point_y > y)
            {
                printf("NE\n");
            }
            else
            {
                printf("SE\n");
            }
        }
        else
        {
            if (point_y > y)
            {
                printf("NO\n");
            }
            else
            {
                printf("SO\n");
            }
        }

        solved(i + 1, n, x, y);
    }
}

int main ()
{
    while (1)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
            return 0;
        
        int x, y;
        scanf("%d %d", &x, &y);

        solved(0, n, x, y);
    }
    
    
}