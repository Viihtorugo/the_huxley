#include <stdio.h>

int verification(int a, int b, int c)
{
    if (a + b + c == 19)
        return 1;

    if (a - b - c == 19)
        return 1;

    return 0;
}

int check(int num)
{
    int div[100];
    int count = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            div[count] = i;
            count++;
        }
    }

    for (int i = count; i >= 0; i--)
        for (int j = 0; j < count; j++)
            for (int k = 0; k < count; k++)
                if (div[i] * div[j] * div[k] == num && verification(div[i], div[j], div[k]))
                    return 1;

    return 0;
}

int main()
{
    for (;;)
    {
        int num;
        scanf("%d", &num);

        if (num == -1)
            break;

        if (check(num))
        {
            printf("INFECTADO\n");
        }
        else
        {
            printf("SAFE\n");
        }
    }

    return 0;
}