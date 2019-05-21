#include<stdio.h>

void chancesOfApproval(double percentage)
{
	if(percentage >= 80 && percentage <= 100)
		printf("%.2lf%% 94.00%% Excelente\n", percentage);
	
	if(percentage >= 60 && percentage < 80)
		printf("%.2lf%% 80.00%% Muito Bom\n", percentage);

	if(percentage >= 40 && percentage < 60)
		printf("%.2lf%% 56.82%% Bom\n", percentage);
	
	if(percentage >= 20 && percentage < 40)
		printf("%.2lf%% 31.65%% Ruim\n", percentage);
	
	if(percentage >= 0 && percentage < 20)
		printf("%.2lf%% 4.40%% Pessimo\n", percentage);	
}


int main (void)
{
	int numQuestions, quantAnswers;

	scanf("%d %d", &numQuestions, &quantAnswers);
	
	chancesOfApproval(quantAnswers*100.0/numQuestions);
	
	return 0;
}
