#include<stdio.h>

short isValid(int n1, int n2, int n3)
{
	if(n1<=100 && n1>=0)
		if(n2<=100 && n2>=0)
			if(n3<=100 && n3>=0)
				return 1;

	return 0;
}

void situationOfStudent(double mean)
{
	if(mean>=70 && mean<=100)
		printf("A media do aluno foi %.2lf e ele foi APROVADO\n", mean);

	if(mean>40 && mean<70)
		printf("A media do aluno foi %.2lf e ele foi FINAL\n", mean);
	
	if(mean>=0 && mean<=40)
		printf("A media do aluno foi %.2lf e ele foi REPROVADO\n", mean);

}

int main(void)
{
	int n1, n2, n3;
		
	scanf("%d %d %d", &n1, &n2, &n3);

	if(isValid(n1, n2, n3))
	{
		situationOfStudent((n1+n2+n3)/3.0);
	}
	else
	{
		printf("Media invalida\n");
	}

	return 0;
}
