#include "lib.h"

NoArvBinaria *aloca_no(int k) {//Aloca um novo nó
  NoArvBinaria *novoNo = NULL;
  novoNo = (NoArvBinaria*)malloc(sizeof(NoArvBinaria));
  if (novoNo == NULL) {
    return NULL;
  }
  else {//Aloca os campos da struct
    novoNo->chave = k;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
  }
}

void imprime_pre_ordem(NoArvBinaria *raiz) {//Visita o raiz, o filho da direita e o filho da esquerda, nessa exata ordem
  if (raiz == NULL) {//Caso base: Encerra a função quando a raiz não tiver mais valores
    return;
  }
  else {
    printf("\n%d\n", raiz->chave);
    imprime_pre_ordem(raiz->esq);//Caso recursivo: Percorre a esquerda
    imprime_pre_ordem(raiz->dir);//Caso recursivo: Percorre a direita
  }
}

/*
 * PROCEDIMENTOS DE BUSCA CLASSICOS
 * devolve o endereco do no cujo valor chave eh k
 * ou NULL caso tal no nao exista na arvore enraizada
 * por raiz.
 */
NoArvBinaria *buscaArvBinRec(NoArvBinaria *raiz, int k) {
  if (raiz == NULL) {//Caso base: Se a árvore estiver vazia, retorna nulo
    return NULL;
  }
  else {
    if (raiz->chave == k) {//Retorna o endereço da chave quando essa for encontrada
      return raiz;
    }
    else if (raiz->chave < k) {//Caso recursivo: Busca pelo lado direito da árvore caso o k buscado seja maior que a chave do raiz
      buscaArvBinRec(raiz->dir, k);
    }
    else {//Caso recursivo: Busca pelo lado esquerdo da árvore caso o k buscado seja menor que a chave do raiz
      buscaArvBinRec(raiz->esq, k);
    }
  }
}

NoArvBinaria *buscaArvBinIterativa(NoArvBinaria *raiz, int k) {
  if (raiz == NULL) {//Caso a árvore esteja vazia, encerra a função
    return NULL;
  }
  else {
    while (raiz != NULL) {//Percorre toda a arvore
      if (raiz->chave == k) {//Caso encontrar a chave, retorna o endereço dessa
        return raiz;
      }
      else if (raiz->chave < k) {//Caso contrário, percorre a árvore pela direita se k for maior que a raíz
        raiz = raiz->dir;
      }
      else {//Ou percorre pela direita se k for menor que a raíz
        raiz = raiz->esq;
      }
    }
  }
}

/*
 *  Para a fun��o de busca abaixo atente para o fato de que
 *  a �rvore indicada N�O � de pesquisa!
 */
NoArvBinaria *buscaAB(NoArvBinaria *raiz, int k) {
  if (raiz == NULL) {//Caso base: Encerra a função quando a árvore for vazia
    return NULL;
  }
  else {//Retorna o endereço do nó onde o valor da chave for igual ao buscado
    if (raiz->chave == k) {
      return raiz;
    }
    else {//Percorre usando o algorítmo de pré-ordem pela árvore
      buscaAB(raiz->esq, k);
      buscaAB(raiz->dir, k);
    }
  }
}


/*
 * PROCEDIMENTOS DE BUSCA DO MENOR/MAIOR
 * 1) devolve o endereco do no cujo valor chave eh o
 *    menor da arvore dada ou NULL caso a arvore seja vazia.
 * 2) devolve o endereco do no cujo valor chave eh o
 *    maior da arvore dada ou NULL caso a arvore seja vazia.
 */
NoArvBinaria *buscaEnderecoDoMenor(NoArvBinaria *raiz) {
  if (raiz == NULL) {//Caso a árvore for vazia, encerra a função
    return NULL;
  }
  NoArvBinaria *noPai = NULL;
  while (raiz != NULL) {//Busca o filho do nó que buscamos, (no caso o último nó menor, seu filho será nulo)
    noPai = raiz;
    raiz = raiz->esq;
  }
  return noPai;//Retorna o nó encontrado
} /*1*/
NoArvBinaria *buscaEnderecoDoMaior(NoArvBinaria *raiz) {
  if (raiz == NULL) {//Caso a árvore for vazia, encerra a função
    return NULL;
  }
  NoArvBinaria *noPai = NULL;//Busca o filho do nó que buscamos, (no caso o último nó maior, seu filho será nulo)
  while (raiz != NULL) {
    noPai = raiz;
    raiz = raiz->dir;
  }
  return noPai;//Caso a árvore for vazia, encerra a função
} /*2*/


/*
 * PROCEDIMENTO DE BUSCA DO ENDERECO DO PONTEIRO DO NO k
 * devolve o endereco onde est� armazenado o endereco do no
 * cujo valor chave eh k ou NULL caso tal no nao exista. O
 * no raiz da arvore dada esta armazenado no endereco *raiz.
 * Assuma que a arvore pode estar vazia, nesse caso *raiz==NULL.
 * i.e.: Para arvores nao vazias, a funcao deve devolver um
 * ponteiro x tal que a seguinte  condicao seja satisfeita:
 * (*x)->chave == k
 */
NoArvBinaria **buscaEnderecoDoPonteiro(NoArvBinaria **raiz, int k) {
  if (*raiz == NULL) {//Caso base: Encerra a função quando a árvore for vazia
    return NULL;
  }
  else {
      if ((*raiz)->chave == k) {//Caso a chave seja encontrada, retorna o endereço do ponteiro local (**raiz) que contém o endereço do ponteiro da main (*raiz) no qual está armazenado o valor
        return &(*raiz);
      }
      else if ((*raiz)->chave < k) {//Caso recursivo:Percorre a árvore pela direita
        buscaEnderecoDoPonteiro(&(*raiz)->dir, k);
      }
      else {//Caso recursivo:Percorre a árvore pela esquerda
        buscaEnderecoDoPonteiro(&(*raiz)->esq, k);
      }
  }
}


/*
 * PROCEDIMENTOS DE BUSCA DO ENDERECO DO PONTEIRO DO MENOR/MAIOR
 * 1) devolve o endereco do ponteiro para o no cujo valor chave eh o
 *    menor da arvore dada ou NULL caso a arvore seja vazia.
 *    i.e.: Para arvores nao nulas a funcao deve devolver um ponteiro x
            tal que (*x)->chave eh o menor valor chave de toda a arvore dada
 * 2) devolve o endereco do ponteiro para o no cujo valor chave eh o
 *    maior da arvore dada ou NULL caso a arvore seja vazia.
 *    i.e.: Para arvores nao nulas a funcao deve devolver um ponteiro x
 *          tal que (*x)->chave eh o maior valor chave de toda a arvore dada
 * O parametro de entrada raiz eh o endereco do ponteiro para o raiz
 * da arvore.
 */
NoArvBinaria **buscaEnderecoDoPonteiroDoMenor(NoArvBinaria **raiz) {
    if (*raiz == NULL) {//Caso a árvore for vazia, retorna nulo
      return NULL;
    }
    if ((*raiz)->esq == NULL) {//Caso base: Retornará o menor nó de uma árvore(se for ABP)
      return &(*raiz);
    }
    else {
      buscaEnderecoDoPonteiroDoMenor(&(*raiz)->esq);//Caso recursivo: Percorre a árvore pela esquerda até encontrar o menor valor(se for ABP)
    }
} /*1*/

NoArvBinaria **buscaEnderecoDoPonteiroDoMaior(NoArvBinaria **raiz) {
  if (*raiz == NULL) {//Caso a árvore for vazia, retorna nulo
    return NULL;
  }
  if ((*raiz)->dir == NULL) {//Caso base: Retornará o maior nó de uma árvore(se for ABP)
    return &(*raiz);
  }
  else {
    buscaEnderecoDoPonteiroDoMaior(&(*raiz)->dir);//Caso recursivo: Percorre a árvore pela direita até encontrar o maiorr valor(se for ABP)
  }
} /*2*/

/*
 * Assume que *folha aponta para um no folha
 * de uma arvore binaria de pesquisa qualquer.
 * O procedimento deve remover tal no.
 */
void removeFolha(NoArvBinaria **folha);

/*
 * Assume que *raiz != NULL
 * O no armazenado no endereco *raiz TEM NECESSARIAMENTE
 * UM FILHO ARMAZENADO EM (*raiz)->esq OU (exclusivo) (*raiz)->dir.
 * O procedimento deve remover o no armazenado em *raiz e
 * fazer com que *raiz passe a apontar pelo filho do no a
 * ser removido
 */
void removeNoComSomenteUmFilho(NoArvBinaria **raiz);

/*
 * PROCEDIMENTOS DE INSERCAO
 * insere um no com chave igual a k numa arvore binaria
 * de pesquisa dada. O no raiz da arvore dada esta armazenado
 * no endereco *raiz. Assuma que a arvore pode estar vazia
 * nesse caso *raiz==NULL.
 * Devolve o endereco do no recem criado ou o endereco do no
 * que ja contenha chave igual a k.
 */
NoArvBinaria *insereArvBinRec(NoArvBinaria **raiz, int k) {
  if (*raiz == NULL) {//Caso base:Quando a arvore estiver vazia, aloca um novo nó
    *raiz = aloca_no(k);
    return *raiz;
  }
  else {
    if ((*raiz)->chave == k) {//Se já existir um nó com o valor de k, retorna a função
      printf("\nJá existe um nó com o valor de k!\n");
      return *raiz;
    }
    if ((*raiz)->chave < k) {//Caso recursivo: Se o valor k a ser inserido for maior que a raiz, envia o endereço da direita para o ponteiro raiz local
      return insereArvBinRec(&(*raiz)->dir, k);
    }
    else {//Caso recursivo: Se o valor k a ser inserido for menor que a raiz, envia o endereço da esquerda para o ponteiro raiz local
      return insereArvBinRec(&(*raiz)->esq, k);
    }
  }
}

NoArvBinaria *insereArvBinIterativa(NoArvBinaria **raiz, int k) {
  if (*raiz == NULL) {//Caso a árvore esteja vazia, aloca o primeiro nó
    *raiz = aloca_no(k);
    return *raiz;
  }
  else {
    NoArvBinaria *arvAux = NULL, *noPai = NULL;
    arvAux = *raiz;//auxiliar para não alterar o ponteiro principal
    while (arvAux != NULL) {//Percorre toda a árvore até encontrar o local correto para alocar o novo nó
      noPai = arvAux;//Ponteiro para indicar o nó pai do novo nó que será inserido
      if (arvAux->chave == k) {
        printf("\nJá existe um nó com o valor de k!\n");
        return arvAux;
      }
      if (arvAux->chave < k) {//Percorre pela direita
        arvAux = arvAux->dir;
      }
      else {//Percorre pela esquerda
        arvAux = arvAux->esq;
      }
    }
    if (noPai->chave < k) {//Se o nó pai for menor do que o seu filho, o novo nó será colocado na direita
      noPai->dir = aloca_no(k);
      return noPai->dir;
    }
    else {//Caso contrário, o novo nó será colocado na esquerda
      noPai->esq = aloca_no(k);
      return noPai->esq;
    }
  }
}

void removeArvBinRec(NoArvBinaria **raiz, int k);
