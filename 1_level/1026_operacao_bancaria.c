#include <stdio.h>
#define MAX 100

void set_matrix (int i, int *c, int *d, double matrix[][MAX])
{
    if (i < MAX)
    {
        int op;
        scanf("%d", &op);
        
        
        switch (op)
        {
            case 1:
                scanf("%lf", &matrix[op][*c]);
                *c += 1;
                break;
                
            case 0:
                scanf("%lf", &matrix[op][*d]);
                *d += 1;
                break;
                
            default:
                return;
        }
        
        set_matrix (i + 1, c, d, matrix);
    }
}

double total_credito (int i, int line, int c, double matrix[][MAX])
{
    if (i < c)
    {
        return matrix[line][i] + total_credito (i + 1, line, c, matrix);
    }
    
    return 0;
}

double total_debito (int i, int line, int d, double matrix[][MAX])
{
    if (i < d)
    {
        return matrix[line][i] + total_debito (i + 1, line, d, matrix);
    }
    
    return 0;
}

int main() 
{
    
    double matrix[2][MAX];
    int c = 0, d = 0;
    
    set_matrix(0, &c, &d, matrix);
    
    double cred = total_credito(0, 1, c, matrix);
    double deb = total_debito(0, 0, d, matrix);
    
    printf("Creditos: R$ %.2lf\n", cred);
    printf("Debitos: R$ %.2lf\n", deb);
    printf("Saldo: R$ %.2lf\n", cred - deb);
    
	return 0;
}