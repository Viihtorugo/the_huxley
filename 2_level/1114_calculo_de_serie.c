#include <stdio.h>

int pot (int n, int i)
{
    return (i != 0) ? n*pot(n, i-1) : 1;
}

int isPrime(int n, int i)
{
    if (i == 1)
        return 1;
    
    if (n % i == 0)
        return 1 + isPrime(n, i-1);
    
    return isPrime(n, i-1);
}

int nextPrime (int n, int i)
{
    if(isPrime(n, n) == 2)
        if(n >= i)
            return n;
        
    return nextPrime(n+1, i);
}

void serie (int n, int i, int prime, double *count)
{
    int pot2  = pot(2, i-1);
    
    if (i <= n)
    {
        if (i % 2 == 0)
        {
            *count += pot2/(3.0 * (i/2));
        }
        else
        {
            if(i != 1)
                prime = nextPrime(prime+1, i);
            
            *count += (double) prime/pot2;
        }
        
        serie(n, i+1, prime, count);
    }
    
}

int main()
{
    int n;
    double count = 0;
    
    scanf("%d", &n);
    
    serie(n, 1, 1, &count);
    printf("S: %.2lf\n", count);

    return 0;
}

