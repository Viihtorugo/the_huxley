#include <stdio.h>

int main ()
{	
	double dolar, icms, valueProduct, valueFreight;

	scanf("%lf %lf %lf %lf", &dolar, &icms, &valueProduct, &valueFreight);
	
	double impImportacao, aliquota = icms/100;
	
	valueProduct *= dolar;
	valueFreight *= dolar;
	
	double total;

	if(valueProduct >= 2500*dolar)
	{	
		impImportacao = valueProduct*0.6;
		total = (valueProduct + impImportacao)/(1-aliquota);
		icms = aliquota * total;
	}
	else
	{	
		impImportacao = (valueProduct + valueFreight)*0.6;
		total = (valueProduct + valueFreight + impImportacao)/(1-aliquota);
		icms = aliquota * total;
	}

	printf("%.2lf\n", dolar);
	printf("%.2lf\n", valueProduct);
	printf("%.2lf\n", valueFreight);
	printf("%.2lf\n", valueProduct + valueFreight);
	printf("%.2lf\n", impImportacao);
	printf("%.2lf\n", icms);
	printf("%.2lf\n", icms + impImportacao);
	
	if(valueProduct >= 2500*dolar)
	{
		printf("%.2lf\n", total + valueFreight);
		printf("Impostos calculados sem o frete\n");
	}
	else
	{
		printf("%.2lf\n", total);
		printf("Impostos calculados com o frete\n");
	}

	return 0;
}
