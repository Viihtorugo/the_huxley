#include <stdio.h>

unsigned long long reverse(char num[], int n)
{
    unsigned long long new_num = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        new_num = new_num * 10 + ((int)num[i] % (int)'0');
    }
    


    return new_num;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    n++;

    char num[n];
    scanf("%s", num);

    printf("%llu\n", reverse(num, n));

    return 0;
}