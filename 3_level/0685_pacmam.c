#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    char m[n][n];

    for (int i = 0; i < n; i++)
        scanf("%s\n", m[i]);

    int max = _MIN_INT_;

        int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < n; j++)
            {
                if (m[i][j] == 'o')
                {
                    count++;
                }
                else if (m[i][j] == 'A')
                {
                    if (count > max)
                        max = count;

                    count = 0;
                }
            }
        }
        else
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (m[i][j] == 'o')
                {
                    count++;
                }
                else if (m[i][j] == 'A')
                {
                    if (count > max)
                        max = count;

                    count = 0;
                }
            }
        }
    }

    printf("%d\n", max);

    return 0;
}