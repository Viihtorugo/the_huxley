#include <stdio.h>

int n, aux, num, count;
int main ()
{
    scanf("%d", &n);

    count = 1;
    scanf("%d", &num);

    for(int i = 1; i < n; i++)
    {
        scanf("%d", &aux);

        if (aux != num)
        {
            ++count;
            num = aux;
        }
    }

    printf("%d\n", count);

    return 0;
}