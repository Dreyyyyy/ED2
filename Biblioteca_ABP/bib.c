#include "bib.h"

void printa_pre_ordem(NoArvBinaria *raiz) {
  if (raiz == NULL) return;
  else {
    printf("Chave: %d\n", raiz->chave);
    printa_pre_ordem(raiz->esq);
    printa_pre_ordem(raiz->dir);
  }
}

NoArvBinaria *buscaArvBinRec(NoArvBinaria *raiz, int k) {
  if (raiz == NULL) return NULL;
  else {
    if (raiz->chave == k) return raiz;
    else if (raiz->chave > k) buscaArvBinRec(&(*raiz->esq), k);
    else buscaArvBinRec(&(*raiz->dir), k);
  }
}

NoArvBinaria *insereArvBinRec(NoArvBinaria **raiz, int k) {
  if (*raiz == NULL) {
    *raiz = (NoArvBinaria*)malloc(sizeof(NoArvBinaria));
    if (*raiz == NULL) printf("=>O S.O não alocou memória!\n");
    else {
      (*raiz)->chave = k;
      (*raiz)->esq = NULL;
      (*raiz)->dir = NULL;
      return *raiz;
    }
  }
  else if ((*raiz)->chave > k) {
    insereArvBinRec(&(*raiz)->esq, k);
  }
  else insereArvBinRec(&(*raiz)->dir, k);
}

NoArvBinaria *buscaAB(NoArvBinaria *raiz, int k) {
  if (raiz == NULL) return NULL;
  else {
    if (raiz->chave == k) return raiz;
    else {
      buscaAB(&(*raiz->esq), k);
      buscaAB(&(*raiz->dir), k);
    }
  }
}

NoArvBinaria **buscaEnderecoDoPonteiro(NoArvBinaria **raiz, int k) {
  if (*raiz == NULL) return NULL;
  else {
    if ((*raiz)->chave == k) return raiz;
    else if ((*raiz)->chave > k) buscaEnderecoDoPonteiro(&(*raiz)->esq, k);
    else buscaEnderecoDoPonteiro(&(*raiz)->dir, k);
  }
}

NoArvBinaria **buscafolha(NoArvBinaria **raiz) {
  if (*raiz == NULL) return NULL;
  else if ((*raiz)->esq == NULL && (*raiz)->dir == NULL) return raiz;
  else {
    buscafolha(&(*raiz)->esq);
    buscafolha(&(*raiz)->dir);
  }
}

void removeFolha(NoArvBinaria **folha) {
  free(*folha);
  *folha = NULL;
  return;
}

NoArvBinaria **buscaumfilho(NoArvBinaria **raiz) {
  if (*raiz == NULL) return NULL;
  if ((*raiz)->dir == NULL && (*raiz)->esq != NULL) return raiz;
  if ((*raiz)->dir != NULL && (*raiz)->esq == NULL) return raiz;
  buscaumfilho(&(*raiz)->esq);
  buscaumfilho(&(*raiz)->dir);
}

void removeNoComSomenteUmFilho(NoArvBinaria **raiz) {
  NoArvBinaria *filho = NULL;
  if ((*raiz)->esq == NULL) filho = (*raiz)->dir;
  if ((*raiz)->dir == NULL) filho = (*raiz)->esq;
  free(*raiz);
  *raiz = filho;
}
