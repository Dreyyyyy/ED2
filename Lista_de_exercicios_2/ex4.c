#include <stdio.h>
#include <stdlib.h>

/*4. Apresente um algoritmo para pesquisar uma dada chave em um vetor de inteiros de n
elementos. A comparação da busca deve ser sempre com o primeiro elemento do (sub-
)vetor considerado.*/

int busca_chave_rec(int *v, int chave, int fim);

int main() {
    int n = 0, i = 0, chave = 0, res = 0;
    printf("Digite o número de elementos do vetor: ");
    scanf("%d", &n);
    int v[n];
    for (i = 1; i <= n; i++) {
        chave = rand () % 100;
        *(v+i) = chave;
    }
    for (i = 1; i <= n; i++){
        printf("%d ", *(v+i));
    }
    printf("\n");
    printf("=>Busque pela chave: ");
    scanf("%d", &chave);
    res = busca_chave_rec(v, chave, *(v+n));
    if (res == 0) {
        printf("Chave não encontrada!\n");
    }
    else {
        printf("Chave %d encontrada!\n", res);
    }
    return 0;
}

int busca_chave_rec(int *v, int chave, int fim) {
    if (*v == fim) {//Caso base 1: Se percorrer todo o vetor e chegar ao fim, só restará duas opções
        if (*v == chave) {//Ou o último elemento (primeiro elemento do sub-vetor) do vetor é igual a chave
            return *v;
        }
        else return 0;//Ou então a chave não se encontra no vetor
    }
    else {
        if (*v == chave) {//Caso base 2: Se o primeiro elemento do sub-vetor for igual ao buscado, retorna o mesmo
            return *v;    
        }
        else {
            busca_chave_rec(v+1, chave, fim);//Caso recursivo: Retorna o vetor uma posição a frente(formando um sub-vetor)
        }
    }
}

