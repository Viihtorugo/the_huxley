#include <stdio.h>

int main() 
{
    double n1, n2, n3;
    scanf("%lf %lf %lf", &n1, &n2, &n3);
    
    printf("%.2lf\n", (n1 + n2 + n3)/3);
    printf("%.2lf\n", (n1*2 + n2*2 + n3*3)/7);
    printf("%.2lf\n", (n1*1 + n2*2 + n3*2)/5);
    
	return 0;
}