#include <stdio.h>

int main ()
{
    int h1, m1, h2, m2;

    while (1)
    {
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);

        if (h1 == 0 && h1 == h2 && h1 == m1 && h1 == m2)
        {
            return 0;
        }

        int m = 0;

        if (m1 > m2)
        {
            m2 += 60;
            h1++;
        }
        
        if (h1 > h2)
            h2 += 24;
        

        m = (h2 - h1) * 60 + (m2 - m1);
        
        printf("%d\n", m);
    }
    
}