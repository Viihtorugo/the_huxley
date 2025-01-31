#include <stdio.h>
#include <limits.h>

typedef struct ret
{
    int y, x, u, v;
} ret;

void choice(int n, ret r[], int *y, int *x, int *u, int *v)
{
    for (int i = 0; i < n; i++)
    {
        if (r[i].y > *y)
        {
            *y = r[i].y;
        }

        if (r[i].v > *v)
        {
            *v = r[i].v;
        }

        if (r[i].u < *u)
        {
            *u = r[i].u;
        }

        if (r[i].x < *x)
        {
            *x = r[i].x;
        }
    }
}

int check (int n, ret r[], int y, int x, int u, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (r[i].y <= y && r[i].u <= y)
            return 0;
        
        if (r[i].x >= x && r[i].v >= x)
            return 0;
        
        if (r[i].y >= u && r[i].u >= u)
            return 0;
        
        if (r[i].v <=v&& r[i].v <= v)
            return 0;
    }
    
}

int main()
{
    for (int i = 1;; i++)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
            return 0;

        ret r[n];

        for (int i = 0; i < n; i++)
            scanf("%d %d %d %d", &r[i].y, &r[i].x, &r[i].u, &r[i].v);

        int y_max = INT_MIN, x_max = INT_MAX;
        int u_min = INT_MAX, v_min = INT_MIN;

        choice(n, r, &y_max, &x_max, &u_min, &v_min);

        printf("Teste %d\n", i);
        if (n != 1)
        {
            printf("%d %d %d %d\n", y_max, x_max, u_min, v_min);
        }
        else
        {
            printf("nenhum\n");
        }

        printf("\n");
    }
}