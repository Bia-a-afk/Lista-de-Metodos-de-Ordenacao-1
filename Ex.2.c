#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionsort_al(int n, int v[]) {
    for (int j = 1; j < n; ++j) {
        int x = v[j];
        int i;

        for (i = j - 1; i >= 0; --i) {
            if (rand() > RAND_MAX / 2)
                v[i + 1] = v[i];
            else
                break;
        }

        v[i + 1] = x;
    }
}

int main() {
    srand((unsigned)time(NULL));

    int c123 = 0, c132 = 0, c213 = 0;
    int c231 = 0, c312 = 0, c321 = 0;
    
    for (int tentativa = 0; tentativa < 600000; tentativa++) {
    int v[3] = {1, 2, 3};

    insertionsort_al(3, v);
    
    if (v[0] == 1 && v[1] == 2 && v[2] == 3)
    c123++;
else if (v[0] == 1 && v[1] == 3 && v[2] == 2)
    c132++;
else if (v[0] == 2 && v[1] == 1 && v[2] == 3)
    c213++;
else if (v[0] == 2 && v[1] == 3 && v[2] == 1)
    c231++;
else if (v[0] == 3 && v[1] == 1 && v[2] == 2)
    c312++;
else if (v[0] == 3 && v[1] == 2 && v[2] == 1)
    c321++;
}

printf("Permutacao 123: %d\n", c123);
printf("Permutacao 132: %d\n", c132);
printf("Permutacao 213: %d\n", c213);
printf("Permutacao 231: %d\n", c231);
printf("Permutacao 312: %d\n", c312);
printf("Permutacao 321: %d\n", c321);

    return 0;
}