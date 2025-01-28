#include <stdio.h>

int main ()
{
    int l;
    scanf("%d", &l);

    int freq[101] = {0}, num;

    for (int i = 0; i < l; i++)
    {
        scanf("%d", &num);
        freq[num]++;
    }
    
    for (int i = 0; i < 101; i++)
    {
        if (freq[i] > 0)
        {
            printf("%d %d\n", i, freq[i]);
        }
    }

    return 0;
}