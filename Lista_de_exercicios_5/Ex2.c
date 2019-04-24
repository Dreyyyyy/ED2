/*2. Apresente um procedimento que conta o total de nos folhas de uma dada arvore binária dada*/

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
void conta_folhas(TipoABP *raiz, int *folhas);

int main(int argc, char const *argv[]) {
  TipoABP *raiz = NULL;
  int i = 0, chave = 0, folhas = 0;
  printf("=>Inserção na árvore:\n");
  for (i = 0; i < 6; i++) {
    chave = rand () % 50;
    printf("=>Insere o valor %d na árvore.\n", chave);
    insere_ABP(&raiz, chave);
  }
  printf("\n=>Árvore printada em pré-ordem:\n");
  printa_pre_ordem(raiz);
  conta_folhas(raiz, &folhas);
  printf("=>Total de nós folhas dessa árvore:%d\n", folhas);
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

void conta_folhas(TipoABP *raiz, int *folhas) {//Passei o folha da main por praticidade
  if (raiz == NULL) {//Caso base: Se a árvore for vazia encerra a função
    return;
  }
  else {
    if (raiz->esq == NULL && raiz->dir == NULL) {//Quando o nó em questão não tiver filhos, este é uma folha, então incrementa 1 na variável de contagem
      *folhas += 1;
    }
    conta_folhas(raiz->esq, folhas);//Caso recursivo 1:Percorre pela esquerda
    conta_folhas(raiz->dir, folhas);//Caso recursivo 2:Percorre pela direita
  }
}
