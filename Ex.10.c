#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercalar(int v[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            i++;
        } else {
            int valor = v[j];
            int k = j;

            while (k > i) {
                v[k] = v[k - 1];
                k--;
            }

            v[i] = valor;
            i++;
            meio++;
            j++;
        }
    }
}

void mergesort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergesort(v, inicio, meio);
        mergesort(v, meio + 1, fim);

        intercalar(v, inicio, meio, fim);
    }
}

void intercalarAux(int v[], int aux[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            aux[k] = v[i];
            i++;
        } else {
            aux[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= meio) {
        aux[k] = v[i];
        i++;
        k++;
    }

    while (j <= fim) {
        aux[k] = v[j];
        j++;
        k++;
    }

    for (int p = inicio; p <= fim; p++) {
        v[p] = aux[p];
    }
}

void mergesortAux(int v[], int aux[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergesortAux(v, aux, inicio, meio);
        mergesortAux(v, aux, meio + 1, fim);

        intercalarAux(v, aux, inicio, meio, fim);
    }
}

int main() {
    int n = 5000;

    int *original = malloc(n * sizeof(int));
    int *v1 = malloc(n * sizeof(int));
    int *v2 = malloc(n * sizeof(int));
    int *aux = malloc(n * sizeof(int));

    if (original == NULL || v1 == NULL ||
        v2 == NULL || aux == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(original);
        free(v1);
        free(v2);
        free(aux);
        return 1;
    }

    srand(42);

    for (int i = 0; i < n; i++) {
        original[i] = rand();
        v1[i] = original[i];
        v2[i] = original[i];
    }

    clock_t inicio = clock();
    mergesort(v1, 0, n - 1);
    clock_t fim = clock();
    double tempoSemAux = (double)(fim - inicio) / CLOCKS_PER_SEC;

    inicio = clock();
    mergesortAux(v2, aux, 0, n - 1);
    fim = clock();
    double tempoComAux = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Tamanho do vetor: %d\n", n);
    printf("Tempo sem auxiliar: %.6f segundos\n", tempoSemAux);
    printf("Tempo com auxiliar: %.6f segundos\n", tempoComAux);

    free(original);
    free(v1);
    free(v2);
    free(aux);

    return 0;
}