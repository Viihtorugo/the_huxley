#include <stdio.h>

int main ()
{
    int n, count = 0;
    scanf("%d", &n);

    char r[n + 1], a[n + 1];
    scanf("%s\n%s", r, a);

    for(int i = 0; i < n; i++)
        if (r[i] == a[i])
            count++;

    
    printf("%d\n", count);

    return 0;
}