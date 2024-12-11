#include <stdio.h>

int main()
{
    int x1, x2, y1, y2;

    while (1)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        if (x1 == 0 && x1 == x2 && x2 == y1 && y1 == y2)
            return 0;

        int x = x1 - x2;
        int y = y1 - y2;

        if (x < 0)
            x = x * -1;

        if (y < 0)
            y = y * -1;

        if (x1 == x2 && y1 == y2)
        {
            printf("0\n");
        }
        else
        {
            if (x == y || x1 == x2 || y1 == y2)
            {
                printf("1\n");
            }
            else
            {
                printf("2\n");
            }
        }
    }
}