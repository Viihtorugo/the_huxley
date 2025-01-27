#include <stdio.h>

int main ()
{
    int b1 = 160 * 70;

    int t, b;
    scanf("%d %d", &t, &b);
    
    int b2 = b1 - (((t + b) * 70)/2);

    if (b2 == b1/2)
    {
        printf("0\n");
    }
    else if (b2 < b1 - b2)
    {
        printf("1\n");
    }
    else
    {
        printf("2\n");
    }

    return 0;
}