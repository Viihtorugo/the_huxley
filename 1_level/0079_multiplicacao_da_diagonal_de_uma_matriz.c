#include <stdio.h>
 
void set_matrix (int i, int d, int matrix[4][4])
{
    if (i < 4 * 4)
    {
        scanf("%d", &matrix[i%4][i/4]);
        
        if (i/4 == i%4)
            matrix[i%4][i/4] *= d;
        
        set_matrix(i + 1, d, matrix);
    }
}

void print_matrix (int i, int n, int matrix[][n])
{
    if (i < 4 * 4)
    {
        printf("%d", matrix[i/4][i%4]);
        
        printf(" ");
            
        if (i % 4 == 3)
            printf("\n");
        
        print_matrix(i + 1, n, matrix);
    }
}

void loop()
{
    int k;
    scanf("%d", &k);
    
    if (k != 0)
    {
        int matrix[4][4];
        
        set_matrix(0, k, matrix);
        print_matrix(0, 4, matrix);
        
        loop();
    }
}

int main()
{
    loop();
    return 0;
}

