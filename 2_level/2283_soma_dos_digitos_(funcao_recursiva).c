#include <stdio.h>

long long int sum (long long int num)
{
    return (num == 0)? 0: num % 10 + sum (num/10); 
}

int main() 
{
    long long int num;
    scanf("%lld", &num);
    
    printf("%lld\n", sum(num));
    
	return 0;
}