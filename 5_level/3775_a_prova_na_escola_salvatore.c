#include <stdio.h>
#include <math.h>

int main ()
{
    double e1, e2, e3, e4, e5;
    scanf("%lf %lf %lf %lf %lf", &e1, &e2, &e3, &e4, &e5);
    
    int temp;
    scanf("%d", &temp);

    char m, d;
    scanf(" %c %c", &m, &d);

    printf("%.2lf\n", (e5 - e1)/temp);

    if (m == 'm')
        printf("%.2lf\n", (e1 + e2 + e3 + e4 + e5)/5);
    
    if (d == 'd')
    {
        double average = (e1 + e2 + e3 + e4 + e5)/5.0;
        double x1 = e1 - average;
        double x2 = e2 - average;
        double x3 = e3 - average;
        double x4 = e4 - average;
        double x5 = e5 - average;
        double var = ((x1 * x1) + (x2 * x2) + (x3 * x3) + (x4 * x4) + (x5 * x5))/5;

        double desv = sqrt(var);

        printf("%.2lf\n", ((e5 - e1)/temp) / 2);
        printf("%.2lf\n", ((e5 - e1)/temp) / 4);
    }

    return 0;
}