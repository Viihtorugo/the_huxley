#include<stdio.h>

int main()
{
	char r, h, t;
	double a, l, s;
	
	scanf("%c %c %c %lf %lf %lf", &r, &h, &t, &a, &l, &s);
	
	if(r == 'H')
		printf("A taxa de sucesso do humano para entrar em Novigrad e de 100.00%%\n");
	
	if(r == 'A')
	{
		
		
		if(a < 1.5)
			s+=2;
		
		if(a > 1.8)
			s-=5;
				
		double m = 10 * ((l+s)/2);

		if(m >=0)
		{
			printf("A taxa de sucesso do anao para entrar em Novigrad e de %.2lf%%\n", m);
		}
		else
		{
			printf("A taxa de sucesso do anao para entrar em Novigrad e de 0.00%%\n");
		}
	}
	
	if(r == 'B')
	{
		
		double m;
		
		if(t == 'n' && h != 'D')
		{
			m = 100.0;
		}
		else
		{
			if(h == 'D')
			{
				m = 0.0;
			}
			else
			{
				if(t == 'c')
				{
					l+=3;
					s+=3;
				}

				if(t == 's')
					s-=1;
			
				if(a < 1.7)
					s+=3;
				

				if(a > 2.0)
					s-=4;
				
				m = 10 * ((l+s)/2);
			}
		}

		if(m >=0)
		{
			printf("A taxa de sucesso do bruxo para entrar em Novigrad e de %.2lf%%\n", m);
		}
		else
		{
			printf("A taxa de sucesso do bruxo para entrar em Novigrad e de 0.00%%\n");
		}
	}
	
	if(r == 'E')
	{

		double m;
		
		if(h == 'N')
		{
			m = 0.0;		
		}
		else
		{	
			if(t == 'n')
			{
				m = 0.0;
			}
			else
			{
				if(t == 'c')
					l-=2;
				
				if(t == 's')
					s-=1;
			
				if(a < 1.6)
					s+=1;
				
				if(a > 1.9)
					s-=6;

				m = 10 * ((l+s)/2);
			}
		}

		if(m >=0)
		{
			printf("A taxa de sucesso do elfo para entrar em Novigrad e de %.2lf%%\n", m);
		}
		else
		{
			printf("A taxa de sucesso do elfo para entrar em Novigrad e de 0.00%%\n");
		}
	}
	
	return 0;
}
