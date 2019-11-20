#include<stdio.h>

int compare_strings(int i, char string1[], char string2[])
{
	if (string1[i] == string2[i])
	{
		if (string1[i] == '\0' && string2[i] == '\0')
			return 1;

		return compare_strings(i + 1, string1, string2);
	}
	
	return 0;
}

int count_spaces (int i, char string[])
{
	if (string[i] == '\0')
		return 0;

	if (string[i] == ' ')
		return 1 + count_spaces(i + 1, string);
	
	return count_spaces(i + 1, string);
}

int count_letra_a (int i, char string[])
{
	if (string[i] == '\0')
		return 0;

	if (string[i] == 'a' || string[i] == 'A')
		return 1 + count_letra_a(i + 1, string);
	
	return count_letra_a(i + 1, string);
}

int count_par_de_letras (int i, char par[], char string[])
{
	if (string[i + 1] == '\0')
		return 0;	

	if (par[0] == string[i] && par[1] == string[i + 1])
		return 1 + count_par_de_letras(i + 1, par, string);
	
	return count_par_de_letras(i + 1, par, string);
}

int is_valid (char a, char b)
{
	if ( ((int) a >= 65 && (int) a <= 90) || ((int) a >= 97 && (int) a <= 122) )
		if ( ((int) b >= 65 && (int) b <= 90) || ((int) b >= 97 && (int) b <= 122))
			return 1;
	
	return 0;
}

int par_de_letras(int i, char string[], char *par, int count_par)
{
	
	if ((string[i] == '\0' || string[i + 1]) && compare_strings(0, par, "12"))
	{
		return 1;
	}
	else if (string[i] == '\0' || string[i + 1])
	{
		printf("%s\n%d\n", par, count_par);
	}
	
	if (string[i + 1] == ' ')
		return par_de_letras(i + 2, string, par, count_par);
	
	if (is_valid(string[i], string[i + 1]))
	{
		par[0] = string[i];
		par[1] = string[i + 1];
		
		
		int aux_count = count_par_de_letras(0, par, string);
		
		if (aux_count > count_par)
			count_par = aux_count;
		
		return par_de_letras(i + 1, string, par, count_par);
	}
	else
	{
		return par_de_letras(i + 1, string, par, count_par);
	}
}

void loop()
{
	char string[81];
	scanf("%[^\n]s", string);
	
	if (compare_strings(0, string, "NAO QUERO MAIS"))
		return;

	printf("%d\n", count_spaces(0, string));
	printf("%d\n", count_letra_a(0, string));
	
	char par[2] = "12";

	if (par_de_letras(0, string, par, 0))
		printf("NENHUM PAR\n");
	
}

int main ()
{

	loop();
	return 0;
}
