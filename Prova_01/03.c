#include <stdio.h>
#include <stdlib.h>

int soma1 = 0;

int soma(int *v, int ini, int fim);

int main (void) {
    int somal = 0, num = 0;
    printf("\n=>Digite o número de elementos do vetor: ");
    scanf("%d", &num);
    int v[num], i = 0, valor = 0;
    for (i = 0; i < num; i++) {
        printf("\n=>Gerando valor aleatório...\n");
        valor = rand () % 50;
        printf("\n=>Inserindo %d no vetor...\n", valor);
        v[i] = valor;
    }
    somal = soma(v, 0, num-1);
    printf("\n=>Vetor:\n");
    for (i = 0; i < num; i++) {
        printf("%d ", v[i]);
    }
    printf("\n\nSoma:%d\n", somal);
    return 0;
}

int soma(int *v, int ini, int fim) {
    if (fim < ini) return soma1;
    int meio = 0;
    meio = (fim+ini)/2;
    soma1 += v[meio];
    soma(v, meio+1, fim);
    soma(v, ini, meio-1);
    return soma1;
}
