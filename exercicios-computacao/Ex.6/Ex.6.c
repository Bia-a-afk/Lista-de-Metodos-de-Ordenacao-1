
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ini;
    int fim;
} Intervalo;

Intervalo r = {9, 12};


int comparar(const void *a, const void *b) {
    Intervalo x = *(const Intervalo *)a;
    Intervalo y = *(const Intervalo *)b;

    if (x.ini < y.ini) return -1;
    if (x.ini > y.ini) return 1;
    return 0;
}


void unirIntervalos(int n, Intervalo v[]) {
    if (n <= 0) {
        printf("Nenhuma reuniao.\n");
        return;
    }

    int iniAtual = v[0].ini;
    int fimAtual = v[0].fim;
    int total = 0;
    
    for (int i = 1; i < n; i++) {
        if (v[i].ini > fimAtual) {
            printf("[%d, %d] ", iniAtual, fimAtual);
            
            total += fimAtual - iniAtual;

            iniAtual = v[i].ini;
            fimAtual = v[i].fim;
        } else {
            if (v[i].fim > fimAtual) {
                fimAtual = v[i].fim;
            }
        }
    }

    printf("[%d, %d]\n", iniAtual, fimAtual);
    total += fimAtual - iniAtual;
    printf("Tempo total em reunioes: %d minutos\n", total);
}


int main(void) {
    Intervalo reunioes[] = {
        {12, 14},
        {2, 5},
        {6, 9},
        {4, 7}
    };

    int n = 4;

    qsort(reunioes, n, sizeof(Intervalo), comparar);

    unirIntervalos(n, reunioes);

    printf("\n");
    return 0;
}
