#include <stdio.h>

int main()
{
    for (int i = 1;; i++)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
            return 0;

        int x1 = -1000000000, y1 = 1000000000,
            x2 = 1000000000, y2 = -1000000000;
        
        while (n > 0)
        {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            if (a > x1)
                x1 = a;
            if (b < y1)
                y1 = b;
            if (c < x2)
                x2 = c;
            if (d > y2)
                y2 = d;
            
            n--;
        }

        printf("Teste %d\n", i);
        if (x2 < x1 || y1 < y2)
            printf("nenhum\n");
        else
            printf("%d %d %d %d\n", x1, y1, x2, y2);

        printf("\n");
    }

}
