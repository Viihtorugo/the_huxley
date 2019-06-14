#include <stdio.h>

char *dayOfWeek (int nDay)
{
	if(nDay == 7)
		return "DOMINGO\0";

	if(nDay == 6)
		return "SEGUNDA\0";
	
	if(nDay == 5)
		return "TERCA\0";
	
	if(nDay == 4)
		return "QUARTA\0";
	
	if(nDay == 3)
		return "QUINTA\0";
	
	if(nDay == 2)
		return "SEXTA\0";
	
	if(nDay == 1)
		return "SABADO\0";
}

void input (int inLines, int nDay, int *countProm, int *countLines, int *day)
{
	if(nDay == 0)
		return;
	
	int prom, lines;
	
	scanf("%d %d", &prom, &lines);
	
	if(prom >= 5)
		*countProm+=1;
	
	if(lines >= 100)
		*countLines+=1;
	
	if(lines > inLines)
	{
		inLines = lines;
		*day = nDay;
	}

	input(inLines, --nDay, countProm, countLines, day);
}

int main()
{
	int countProm = 0, countLines = 0, day;
	
	input(0, 7, &countProm, &countLines, &day);
	
	printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE PROGRAMAS: %d\n", countProm);
	printf("QUANTIDADE DE DIAS QUE ATINGIU MEDIA DE LINHAS: %d\n", countLines);
	printf("DIA QUE MAIS PRODUZIU: %s\n", dayOfWeek(day));

	return 0;
}
