#include <stdio.h>
#include <math.h>

int main ()
{
    double d, vf, vg;

    while (1)
    {
        scanf("%lf %lf %lf", &d, &vf, &vg);

        if(d == -1 && vf == -1 && vg == -1)
            return 0;
        
        double dgf = sqrt(d * d + 12 * 12);

        if (dgf/vg <= 12/vf)
        {
            printf("S\n");
        }
        else
        {
            printf("N\n");
        }

    }

}