#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int prefixo, sufixo, tam;
    scanf("%d %d ", &prefixo, &sufixo);

    char palavra[100];
    scanf("%[^\n]s", palavra);

    tam = strlen(palavra);

    char secundaria1[100], secundaria2[100];
    scanf(" %[^\n]s", secundaria1);
    scanf(" %[^\n]s", secundaria2);

    if (prefixo <= 0 || sufixo <= 0 || prefixo > tam || sufixo > tam) {
        printf("TAMANHO INVALIDO\n");
        return 0;
    }

    // Prefixo:
    for (int i = 0; i < prefixo; i++) {
        printf("%c", toupper(palavra[i]));
    }
    printf(" :\n");

    for (int i = 0; i < prefixo; i++) {
        printf("%c", palavra[i]);
    }

    for (int i = 0; i < strlen(secundaria1); i++) {
        printf("%c", secundaria1[i]);
    }
    printf("\n");

    for (int i = 0; i < prefixo; i++) {
        printf("%c", palavra[i]);
    }

    for (int i = 0; i < strlen(secundaria2); i++) {
        printf("%c", secundaria2[i]);
    }
    printf("\n\n");

    // Sufixo:
    for (int i = sufixo; i < strlen(palavra); i++) {
        printf("%c", toupper(palavra[i]));
    }
    printf(" :\n");

    for (int i = 0; i < strlen(secundaria1); i++) {
        printf("%c", secundaria1[i]);
    }

    for (int i = sufixo; i < strlen(palavra); i++) {
        printf("%c", palavra[i]);
    }
    printf("\n");

    for (int i = 0; i < strlen(secundaria2); i++) {
        printf("%c", secundaria2[i]);
    }

    for (int i = sufixo; i < strlen(palavra); i++) {
        printf("%c", palavra[i]);
    }
    printf("\n");

    return 0;
}