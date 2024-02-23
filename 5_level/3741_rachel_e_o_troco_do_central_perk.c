#include <stdio.h>

int main ()
{
    float v1, v2;
    scanf("%f %f", &v1, &v2);

    printf("%.2f\n", v2 - v1);

    int troco = (v2*100) - (v1*100);

    int nota_de_cinquenta = troco / 5000;
    troco -= nota_de_cinquenta*5000;
    int nota_de_vinte = troco / 2000;
    troco -= nota_de_vinte*2000;
    int nota_de_dez = troco / 1000;
    troco -= nota_de_dez*1000;
    int nota_de_cinco = troco / 500;
    troco -= nota_de_cinco*500;
    int nota_de_dois = troco / 200;
    troco -= nota_de_dois*200;

    int moeda_de_um = troco / 100;
    troco -= moeda_de_um*100;
    int moeda_de_cinquenta = troco / 50;
    troco -= moeda_de_cinquenta*50;
    int moeda_de_vinte_e_cinco = troco / 25;
    troco -= moeda_de_vinte_e_cinco*25;
    int moeda_de_dez = troco / 10;
    troco -= moeda_de_dez*10;
    int moeda_de_cinco = troco / 5;
    troco -= moeda_de_cinco*5;

    int notas = nota_de_cinquenta + nota_de_vinte;
    notas += nota_de_dez + nota_de_cinco + nota_de_dois;

    int moedas = moeda_de_um + moeda_de_cinquenta;
    moedas += moeda_de_vinte_e_cinco + moeda_de_dez + moeda_de_cinco;

    printf("%d notas e %d moedas\n", notas, moedas);

    return 0;
}