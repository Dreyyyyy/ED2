/*6. Apresente um algoritmo chamado MixedTraversal que funciona da seguinte maneira: Se
o campo chave do no raiz de uma dada áarvore for par, percorra esta árvore em pré-ordem
do contrario percorra a árvore dada em pós-ordem.*/

#include <stdio.h>
#include <stdlib.h>

struct arvBin {
  int chave;
  struct arvBin *esq;
  struct arvBin *dir;
};
typedef struct arvBin TipoABP;

TipoABP *insere_ABP(TipoABP **raiz, int chave);
TipoABP *aloca_no(int chave);
void mixed_tranversal(TipoABP *raiz);

int main(int argc, char const *argv[]) {
  TipoABP *raiz = NULL;
  int i = 0, chave = 0;
  printf("=>Inserção na árvore:\n");
  for (i = 0; i < 6; i++) {
    chave = rand () % 50;
    printf("=>Insere o valor %d na árvore.\n", chave);
    insere_ABP(&raiz, chave);
  }
  printf("\n=>Printa a árvore em pré-ordem caso a raíz for par, caso contrário printa em pós-ordem:\n");
  if (raiz->chave % 2 == 0) {
    printf("=>Pré-ordem:\n");
  }
  else {
    printf("=>Pós-ordem:\n");
  }
  mixed_tranversal(raiz);
  return 0;
}

TipoABP *aloca_no(int chave) {
  TipoABP *aux = NULL;
  aux = (TipoABP*)malloc(sizeof(TipoABP));
  if (aux == NULL) {
    return NULL;
  }
  else {
    aux->chave = chave;
    aux->esq = NULL;
    aux->dir = NULL;
    return aux;
  }
}

void printa_pre_ordem(TipoABP *raiz) {//Visita, percorre pela esquerda e depois pela direita
  if (raiz == NULL) {
    return;
  }
  else {
    printf("=>Chave: %d\n", raiz->chave);
    printa_pre_ordem(raiz->esq);
    printa_pre_ordem(raiz->dir);
  }
}

void printa_pos_ordem(TipoABP *raiz) {//Percorre pela esquerda, depois pela direita e por fim visita
  if (raiz == NULL) {
    return;
  }
  else {
    printa_pos_ordem(raiz->esq);
    printa_pos_ordem(raiz->dir);
    printf("=>Chave: %d\n", raiz->chave);
  }
}

TipoABP *insere_ABP(TipoABP **raiz, int chave) {
  if (*raiz == NULL) {
    *raiz = aloca_no(chave);
    if (*raiz == NULL) {
      return NULL;
    }
  }
  else {
    if ((*raiz)->chave == chave) {
      printf("=>Chave já inserida na árvore! Retornando o endereço desta:\n");
    }
    else if ((*raiz)->chave > chave) {
      insere_ABP(&(*raiz)->esq, chave);
    }
    else {
      insere_ABP(&(*raiz)->dir, chave);
    }
  }
  return *raiz;
}

void mixed_tranversal(TipoABP *raiz) {
  if (raiz == NULL) {//Se a árvore for vazia, encerra a função
    return;
  }
  else {
    if (raiz->chave % 2 == 0) {//Caso o nó raiz tenha a chave par, printa em pré-ordem
      printa_pre_ordem(raiz);
    }
    else {//Caso contrário, printa em pós-ordem
      printa_pos_ordem(raiz);
    }
  }
}
