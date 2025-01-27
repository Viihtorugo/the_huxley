#include <stdio.h>

int small (int i, int n, int num)
{
    if (i < n)
    {
        int r;
        scanf("%d", &r);

        if (r < num)
            num = r;

        return small(i + 1, n, num);
    }

    return num;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    printf("%d\n", small(0, n, 100000000));

    return 0;
}