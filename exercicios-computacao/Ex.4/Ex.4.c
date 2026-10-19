#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparar(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

void analisar(int n, int v[]) {
    if (n <= 0) {
        printf("Vetor vazio.\n");
        return;
    }

    qsort(v, n, sizeof(int), comparar);

    int distintos = 1;
    int atual = 1;
    int maior = 1;
    int moda = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] != v[i - 1]) {
            distintos++;
            atual = 1;
        } else {
            atual++;
        }

        if (atual > maior) {
            maior = atual;
            moda = v[i];
        }
    }

    printf("Valores distintos: %d\n", distintos);
    printf("Moda: %d\n", moda);
    printf("Frequencia da moda: %d\n", maior);
}


void analisarIngenuo(int n, int v[]) {
    if (n <= 0) {
        printf("Vetor vazio.\n");
        return;
    }

    int distintos = 0;
    int maior = 0;
    int moda = v[0];

    for (int i = 0; i < n; i++) {
        int primeiraVez = 1;
        int frequencia = 0;

        for (int j = 0; j < n; j++) {
            if (v[j] == v[i]) {
                frequencia++;
            }
        }

        for (int j = 0; j < i; j++) {
            if (v[j] == v[i]) {
                primeiraVez = 0;
                break;
            }
        }

        if (primeiraVez) {
            distintos++;
        }

        if (frequencia > maior) {
            maior = frequencia;
            moda = v[i];
        }
    }

    printf("Valores distintos: %d\n", distintos);
    printf("Moda: %d\n", moda);
    printf("Frequencia da moda: %d\n", maior);
}


int main(void) {
    int tamanhos[] = {10000, 100000};
    int quantidade = 2;

    srand((unsigned)time(NULL));

    for (int k = 0; k < quantidade; k++) {
        int n = tamanhos[k];
        int *original = malloc(n * sizeof(int));
        int *ordenado = malloc(n * sizeof(int));
        int *ingenuo = malloc(n * sizeof(int));

        if (original == NULL || ordenado == NULL ||
            ingenuo == NULL) {
            printf("Erro de memoria.\n");
            free(original);
            free(ordenado);
            free(ingenuo);
            return 1;
        }

        for (int i = 0; i < n; i++) {
            original[i] = rand() % 1000;
        }

        for (int i = 0; i < n; i++) {
            ordenado[i] = original[i];
            ingenuo[i] = original[i];
        }

        clock_t inicio = clock();
        analisar(n, ordenado);
        clock_t fim = clock();

        printf("Ordenacao + varredura: %.6f s\n",
               (double)(fim - inicio) / CLOCKS_PER_SEC);

        inicio = clock();
        analisarIngenuo(n, ingenuo);
        fim = clock();

        printf("Solucao ingenua: %.6f s\n",
               (double)(fim - inicio) / CLOCKS_PER_SEC);

        free(original);
        free(ordenado);
        free(ingenuo);
    }

    return 0;
}
