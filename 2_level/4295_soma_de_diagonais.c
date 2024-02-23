#include <stdio.h>

int char_to_int(int *i, char string[], int s)
{
    int num = 0;

    while ((string[*i] != '\0') && (string[*i] >= '0' && string[*i] <= '9'))
    {
        num = num * 10 + ((int)string[*i]) % ((int)'0');
        *i += 1;
    }

    if (s)
        num = -num;

    return num;
}

int sum (int m1[], int m2[], int d1, int d2, int t1, int t2)
{
    int s = 0;

    int c1 = t1;

    if (c1 != 1)
        c1--;

    if (d1 - 1 != 0)
        c1 = c1 / (d1 - 1);

    for (int i = 0; i < t1; i += c1)
        s += m1[i];
    
    
    for (int i = t2 - d2; i > 0; i -= (d2 - 1))
        s += m2[i];

    return s;
}

int main ()
{
    char in1[1000000], in2[1000000];
    scanf("%[^\n]s", in1);
    scanf(" %[^\n]s", in2);

    printf("%s\n%s\n", in1, in2);

    int t1 = 0, t2 = 0;
    int m1[100000], m2[100000];

    for (int i = 0; in1[i] != '\0'; i++)
    {
        if (in1[i] >= '0' && in1[i] <= '9')
        {
            m1[t1++] = char_to_int(&i, in1, 0);
            
        }
        else if (in1[i] == '-')
        {
            m1[t1++] = char_to_int(&i, in1, 1);
        }
    }

    for (int i = 0; in2[i] != '\0'; i++)
    {
        if (in2[i] >= '0' && in2[i] <= '9')
        {
            m2[t2++] = char_to_int(&i, in2, 0);
            
        }
        else if (in2[i] == '-')
        {
            m2[t2++] = char_to_int(&i, in2, 1);
        }
    }

    int d1 = 0, d2 = 0;

    for (int i = 1; in1[i] != ']'; i++)
    {
        if (in1[i] >= '0' && in1[i] <= '9')
        {
            d1++;

            while(in1[i] >= '0' && in1[i] <= '9')
                i++;

            i--;
        }
    }

    for (int i = 1; in2[i] != ']'; i++)
    {
        if (in2[i] >= '0' && in2[i] <= '9')
        {
            d2++;

            while(in2[i] >= '0' && in2[i] <= '9')
                i++;

            i--;
        }
    }
    
    printf("t1 = %d, t2 = %d e d1 = %d, d2 = %d\n", t1, t2, d1, d2);
    printf("soma: %d\n", sum(m1, m2, d1, d2, t1, t2));

    //printf("%d\n", sum(m1, m2, d1, d2, t1, t2));

    return 0;
}