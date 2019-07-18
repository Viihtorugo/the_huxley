#include <stdio.h>

int countNum (int n, int *count)
{
    int num;
    scanf("%d", &num);
    
    if(n == 10)
        return num;
    
    int aux = countNum(n+1, count);
    
    if(num == aux)
        *count += 1;
        
    return aux;
}

int main() 
{
    int count = 0;
    
    countNum(0, &count);
    
    printf("%d\n", count);
    
	return 0;
}
