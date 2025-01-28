#include <stdio.h>

int main ()
{
    long long n, m;
    scanf("%lld %lld", &n, &m);

    long long array[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &array[i]);
    
    long long count = 0;

    for (int i = 0; i < n; i++)
    {
        long long diff = 0;

        if (array[i] > m)
        {
            diff = array[i] - m;
            
            if (i + 1 != n)
            {
                array[i + 1] -= diff; 
            }
        }
        else
        {
            diff = m - array[i];

            if (i + 1 != n)
            {
                array[i + 1] += diff; 
            }
        }

        count += diff;

    }
    
    printf("%lld\n", count);
}