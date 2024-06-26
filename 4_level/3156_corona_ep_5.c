#include <stdio.h>
#include <math.h>

int is_prime(long long num)
{
    if(num <= 1)
        return 0;

    for (long long i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return 0;
    
    return 1;
}

void solved()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);

    for (long long i = a; i <= b; i++)
        if(is_prime(i))
            printf("%lld\n", i);
}

int main ()
{   
    solved();

    return 0;
}