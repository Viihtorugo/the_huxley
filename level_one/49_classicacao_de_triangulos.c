#include<stdio.h>
 
int main(void)
{        
        float l1, l2, l3;

        scanf("%f %f %f", &l1, &l2, &l3);
        
        if(l1 == l2)
	{	
		if(l2 != l3){
			printf("isosceles\n");
		}
		else
		{
			printf("equilatero\n");
		}
	}
	else
	{
		if(l1 == l3 || l2 == l3)
		{
			printf("isosceles\n");
		}
		else
		{
			printf("escaleno\n");
		}
	}
	
	return 0;
}
