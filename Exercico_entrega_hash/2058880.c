#include <stdio.h>
#include <stdlib.h>
#include "mt19937ar.h"
//T = tamanho da tabela
//E = número de chaves
//T = 1010000
//E = 1000000
#define T 1010000
#define E 1000000

struct No {
    int chave;
    struct No *prox;
}
;typedef struct No no;
;typedef struct No *hash[T];//Ponteiro para a estrutura, facilita na implementação do vetor de ponteiros para estrutura

int inicializa_tabela(hash tabela);

int insere_tabela(hash tabela, unsigned int chave);

int funcao_espalhamento(unsigned int chave);

int conta_hash(hash tabela, int hash);

int conta_tabela(hash tabela);

int conta_colisoes(hash tabela);

int main(void) {
    int ver = 0, chave = 0, i = 0, cod_hash = 0, cont = 0, maior = 0, coli = 0, aux = 0, media = 0;
    float m = 0.0;
    hash tabela;
    ver = inicializa_tabela(tabela); 
    if (ver == 1) printf("\n=>Tabela inicializada.\n");
    printf("\n=>Inserindo valores na tabela...\n");
    for (i = 0; i < E; i++) {
        insere_tabela(tabela, (unsigned int)genrand_int32());
    }
    cont = conta_tabela(tabela);
    printf("=>Número de hash vazios na tabela:%d\n", cont);
    for (i = 0; i < T; i++) {
        aux = conta_hash(tabela, i);
        media += aux;
        if (aux > maior) maior = aux;
    }
    printf("=>Números de nós da maior lista de colisões da tabela:%d\n", maior);
    coli = conta_colisoes(tabela);
    printf("=>Número de colisões:%d\n", coli);
    printf("=>Tamanho médio das listas:%.2f\n", (float)media/(float)(T-cont));
    return 0;
}

//Inicializa a tabela com todos os seus valores nulos. Caso após inserções continue nulo, a posição de tal hash está vazia
int inicializa_tabela(hash tabela) {
    int i = 0;
    for (i = 0; i < T; i++) {
        tabela[i] = NULL;
    }
    return 1;
}

//Insere um nó em um determinado local da tabela
int insere_tabela(hash tabela, unsigned int chave) {
    int hash_code = 0;
    hash_code = funcao_espalhamento(chave);
    no *novoNo = NULL;
	novoNo = (no*)malloc(sizeof(no));
	if (novoNo == NULL) return 0;
    else {
	    novoNo->chave = chave;
	    novoNo->prox = tabela[hash_code];
	    tabela[hash_code] = novoNo;
        return 1;
    }
}

//Cria os hash codes
int funcao_espalhamento(unsigned int chave) {
    return chave % T;
}

//Procura pela hash cujo a lista possui mais elementos
int conta_hash(hash tabela, int hash) {
    no *hashAux = NULL;
    hashAux = tabela[hash];
    int cont = 0;
    if (hashAux == NULL) return 0;
    else {
        while (hashAux != NULL) {
            hashAux = hashAux->prox;
            cont+=1;
        }
    }
    return cont;
}

//Conta número de elementos da tabela
int conta_tabela(hash tabela) {
    int i = 0, cont = 0;
    no *hashAux = NULL;
    for (i = 0; i < T; i++) {
        hashAux = tabela[i];
        if (hashAux == NULL) cont++;
    }
    return cont;
}

//Conta colisões da tabela
int conta_colisoes(hash tabela) {
    int i = 0, cont = 0;
    no *hashAux = NULL;
    for (i = 0; i < T; i++) {
        hashAux = tabela[i];
        if (hashAux != NULL) cont++;
    }
    return cont;
}

