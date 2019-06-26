#include <stdio.h>

typedef struct student
{
	int number;
	char firstName[20];
	char lastName[20];
	double average;
	int absence;
	char status;
} Student;

void getString(char *name)
{
	char c;
	int i = 0;

	do
	{
		c = getchar();
		*name = c;
		name++;
		i++;
	}while(c != ' ');
	
	name--;
	*name = '\0';
	name -= i;	
}

double averageStudents(int n, Student *students)
{
	int i;
	double sum = 0;
	
	for(i = 0; i < n; i++)
		sum += students[i].average;
	
	return sum/n;
}

int absenceStudents(int n, Student *students)
{
	int i, sum = 0;
	
	for(i = 0; i < n; i++)
		sum += students[i].absence;
	
	return sum;
}

int main ()
{
	int n, i, null = 1;
	
	scanf("%d", &n);

	Student students[n];
	
	for(i = 0; i < n; i++)
	{
		scanf("%d ", &students[i].number);
		getString(students[i].firstName);
		getString(students[i].lastName);
		scanf("%lf %d %c", &students[i].average, &students[i].absence, &students[i].status);
	}
	
	double averageClass = averageStudents(n, students);
	int absenceClass = absenceStudents(n, students);
	
	for(i = 0; i < n; i++)
	{
		if(students[i].status == 'M')
		{
			if(students[i].average > averageClass)
			{
				if(students[i].absence * 1.0 < absenceClass * 0.1)
				{
					null = 0;
					printf("%d:%s\n", i, students[i].lastName);
				}
			}
		}
	}
	
	if(null)
		printf("VAZIO\n");

	return 0;
}
