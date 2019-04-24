/*4. Apresente um procedimento em C para imprimir os elementos de uma arvore binaria de ´
pesquisa em ordem decrescente.*/

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
void printa_pre_ordem(TipoABP *raiz);
void printa_ordem_decrescente(TipoABP *raiz);

int main(int argc, char const *argv[]) {
  TipoABP *raiz = NULL;
  int i = 0, chave = 0;
  printf("=>Inserção na árvore:\n");
  for (i = 0; i < 6; i++) {
    chave = rand () % 50;
    printf("=>Insere o valor %d na árvore.\n", chave);
    insere_ABP(&raiz, chave);
  }
  printf("\n=>Árvore printada em pré-ordem:\n");
  printa_pre_ordem(raiz);
  printf("\n=>Árvore imprimida em ordem decrescente(baseando-se nos valores das chaves):\n");
  printa_ordem_decrescente(raiz);
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

void printa_pre_ordem(TipoABP *raiz) {
  if (raiz == NULL) {
    return;
  }
  else {
    printf("=>Chave: %d\n", raiz->chave);
    printa_pre_ordem(raiz->esq);
    printa_pre_ordem(raiz->dir);
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

void printa_ordem_decrescente(TipoABP *raiz) {
  if (raiz == NULL) {
    return;
  }
  else {//Uma travessia "em-ordem", porém ao invés do mais comum, que é percorre primeiro pela esquerda, percorre pela direita, visita e depois percorre pela esquerda 
    printa_ordem_decrescente(raiz->dir);
    printf("=>Chave: %d\n", raiz->chave);
    printa_ordem_decrescente(raiz->esq);
  }
}
