#include <stdio.h>

int main ()
{
    int t = 1, num;

    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &num);

        t += (num - 1);
    }
    
    printf("%d\n", t);

    return 0;
}