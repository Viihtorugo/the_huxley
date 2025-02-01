#include <stdio.h>
#include <math.h>

int is_prime(int n)
{
    int count = 2;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            count++;
        }
    }
    
    if (count == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main ()
{
    int n;
    int num;
    scanf("%d", &n);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);

        if (is_prime(num) && num != 2)
        {
            count -= num;

        }
        else
        {
            count += num;
        }
    }
    
    if (count < 0)
    {
        printf("Foi de base\n");
    }
    else
    {
        printf("Ele ainda tem %d dias de vida\n", count);
    }

    return 0;
}