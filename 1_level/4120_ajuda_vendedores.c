#include <stdio.h>

int main ()
{
    double value;
    scanf("%lf", &value);

    double new_value = value*0.90;

    printf("A vista com desconto de 10%%: %.2lf\n", new_value);
    printf("Valor da parcela em 3x sem juros: %.2lf\n", value/3);
    printf("Comissao do vendedor a vista: %.2lf\n", new_value*0.05);
    printf("Comissao do vendedor a prazo: %.2lf\n", value*0.05);
}