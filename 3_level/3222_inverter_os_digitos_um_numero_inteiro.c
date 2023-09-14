#include <stdio.h>

void print(long long int num)
{
    if (num != 0)
    {
        printf("%lld", num%10);
        print(num/10);
    }
}

int main()
{
    long long int num;
    
    scanf("%lld", &num);
    print(num);
    printf("\n");
    
	return 0;
}