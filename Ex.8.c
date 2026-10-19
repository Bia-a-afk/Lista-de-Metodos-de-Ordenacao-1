#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRA 100

typedef struct {
    char original[MAX_PALAVRA];
    char chave[MAX_PALAVRA];
} Palavra;


void criarChave(char original[], char chave[]) {
    int i;

    for (i = 0; original[i] != '\0'; i++) {
        chave[i] = tolower(original[i]);
    }

    chave[i] = '\0';

    int n = strlen(chave);

    for (i = 1; i < n; i++) {
        char x = chave[i];
        int j = i - 1;

        while (j >= 0 && chave[j] > x) {
            chave[j + 1] = chave[j];
            j--;
        }

        chave[j + 1] = x;
    }
}


int compararPalavras(const void *a, const void *b) {
    Palavra x = *(const Palavra *)a;
    Palavra y = *(const Palavra *)b;

    return strcmp(x.chave, y.chave);
}


int main(void) {
    int n;

    printf("Quantas palavras deseja digitar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade invalida.\n");
        return 0;
    }

    Palavra palavras[n];

    for (int i = 0; i < n; i++) {
        printf("Digite a palavra %d: ", i + 1);
        scanf("%99s", palavras[i].original);

        criarChave(
            palavras[i].original,
            palavras[i].chave
        );
    }

    qsort(
        palavras,
        n,
        sizeof(Palavra),
        compararPalavras
    );
        
    printf("\nGrupos de anagramas:\n");

    for (int i = 0; i < n; i++) {
        if (i == 0 ||
            strcmp(palavras[i].chave,
                   palavras[i - 1].chave) != 0) {
            printf("\nChave %s: ",
                   palavras[i].chave);
        }

        printf("%s ", palavras[i].original);
        
    
    }

    printf("\n");

    return 0;
}

