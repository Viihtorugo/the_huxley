#include <stdio.h>

typedef struct tree
{
    int ke;
    int kd;
} tree;

int heigth_tree(int k, int init, tree t[], int count)
{
    if (init == -1)
        return count;

    int c1 = heigth_tree(k, t[init].ke, t, count + 1);
    int c2 = heigth_tree(k, t[init].kd, t, count + 1);

    return (c1 > c2) ? c1 : c2;
}

int main()
{
    int n, k, b;
    scanf("%d %d %d", &n, &k, &b);

    tree t[n];

    for (int i = 0; i < n; i++)
    {
        t[i].kd = -1;
        t[i].ke = -1;
    }

    for (int i = 0; i < k; i++)
    {
        int b, e, d;
        scanf("%d %d %d", &b, &e, &d);

        t[b].ke = e;
        t[b].kd = d;
    }

    printf("%d\n", heigth_tree(k, b, t, 0));

    return 0;
}