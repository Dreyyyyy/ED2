#ifndef ARVBINARIA_H
#define ARVBINARIA_H

/*
 * A menos que falado de forma diferente, considere que todas as �rvores s�o de pesquisa.
 */

#include <stdio.h>
#include <stdlib.h>

struct NoArvBinaria
{
  int chave;
  struct NoArvBinaria * esq;
  struct NoArvBinaria * dir;
};

typedef struct NoArvBinaria NoArvBinaria;

NoArvBinaria *aloca_no(int k);

void imprime_pre_ordem(NoArvBinaria *raiz);

NoArvBinaria *buscaArvBinRec(NoArvBinaria *raiz, int k);

NoArvBinaria *buscaArvBinIterativa(NoArvBinaria *raiz, int k);

NoArvBinaria *buscaAB(NoArvBinaria *raiz, int k);

NoArvBinaria *buscaEnderecoDoMenor(NoArvBinaria *raiz); /*1*/

NoArvBinaria *buscaEnderecoDoMaior(NoArvBinaria *raiz); /*2*/

NoArvBinaria **buscaEnderecoDoPonteiro(NoArvBinaria **raiz, int k);

NoArvBinaria **buscaEnderecoDoPonteiroDoMenor(NoArvBinaria **raiz); /*1*/

NoArvBinaria **buscaEnderecoDoPonteiroDoMaior(NoArvBinaria **raiz); /*2*/

void removeFolha(NoArvBinaria **folha);

void removeNoComSomenteUmFilho(NoArvBinaria **raiz);

NoArvBinaria *insereArvBinRec(NoArvBinaria **raiz, int k);

NoArvBinaria *insereArvBinIterativa(NoArvBinaria **raiz, int k);

void removeArvBinRec(NoArvBinaria **raiz, int k);

#endif
