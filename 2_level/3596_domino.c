#include <stdio.h>

int main ()
{
    long long n;
    scanf("%Ld", &n);

    printf("%Ld\n", ((n + 1)*(n + 2))/2);

    return 0;
}