/*7. Apresente um procedimento que calcula a altura de uma arvore binária. Assuma que
uma árvore vazia tem altura −1. DICA: Se desejar, adicione ao prototipo de sua função
uma variavel para contagem de níveis e outra para registrar o maior nível conhecido até
o momento.*/

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
void printa_ordem_crescente(TipoABP *raiz);
int calcula_altura(TipoABP *raiz);

int main(int argc, char const *argv[]) {
  TipoABP *raiz = NULL;
  int i = 0, chave = 0, altura = -1;
  printf("=>Inserção na árvore:\n");
  for (i = 0; i < 8; i++) {
    chave = rand () % 50;
    printf("=>Insere o valor %d na árvore.\n", chave);
    insere_ABP(&raiz, chave);
  }
  printf("\n=>Árvore printada em pré-ordem:\n");
  printa_pre_ordem(raiz);
  altura = calcula_altura(raiz);
  printf("=>A altura da árvore é de: %d\n", altura);
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

int calcula_altura(TipoABP *raiz) {
  if (raiz == NULL) {//Caso base: se a árvore for vazia, retorna -1 como sua altura
    return -1;
  }
  else {
    int alt_esq = 0, alt_dir = 0;
    alt_esq = calcula_altura(raiz->esq);//Caso recursivo: Calcula a altura dos nós esquerdos da árvore, e vai empilhando tudo
    alt_dir = calcula_altura(raiz->dir);//Caso recursivo: Calcula a altura dos nós direitos da árvore. e vai empilhando tudo
    if (alt_esq > alt_dir) {//Quando for desempilhando os resultado, compara a altura do nó da esquerda com o da direita, caso o nó esquerdo tenha a altura maior, retorna a altura+1 (No caso, +1 para contar o nó em que a função está)
      return (alt_esq + 1);
    }
    else {//Caso contrário, retorna a altura da direita+1(Novamente, para contar o nó em que a função está)
      return (alt_dir + 1);
    }
  }
}
