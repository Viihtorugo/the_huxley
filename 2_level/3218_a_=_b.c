#include <stdio.h>

int main() {
    
    long long int a, b;
    scanf("%lld %lld", &a, &b);

    unsigned char n = 1;

    long long int res[100000];
    int count = 0;
    
    while ((long long int)n < a)
        n = n << 1;
    
    n = n >> 1;

    while (a != b)
    {
        if (a - (long long int) n >= b)
        {
            a -= (long long int) n;
            res[count] = (long long int) n;
            count++;
        }

        n = n >> 1;
    }

    for (int i = 0; i < count; i++)
    {
        if (i + 1 == count)
        {
            printf("%lld\n", res[i]);
        }
        else
        {
            printf("%lld ", res[i]);
        }
    }
    
    
	return 0;
}