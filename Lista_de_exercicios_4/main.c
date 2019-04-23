#include "lib.h"

int main(int argc, char const *argv[]) {
  NoArvBinaria *raizRec = NULL, *end = NULL, *raizIt = NULL, **endDOend = NULL;
  int i = 0, k = 0;
  printf("\n=>Insere valores aleatórios recursivos na árvore:\n");
  for (i = 0; i < 5; i++) {
    k = rand () % 50;
    printf("\n%dº valor: %d\n", i+1, k);
    insereArvBinRec(&raizRec, k);
  }
  printf("\n=>Árvore imprimida usando pré-ordem:\n");
  imprime_pre_ordem(raizRec);
  printf("\n=>Insere valores aleatórios iterativos na árvore:\n");
  for (i = 0; i < 5; i++) {
    k = rand () % 50;
    printf("\n%dº valor: %d\n", i+1, k);
    insereArvBinIterativa(&raizIt, k);
  }
  printf("\n=>Árvore imprimida usando pré-ordem:\n");
  imprime_pre_ordem(raizIt);
  printf("\n=>Busca pela chave iterativo, na árvore iterativa: ");
  scanf("%d", &k);
  end = buscaArvBinIterativa(raizIt, k);
  if (end != NULL) {
      printf("\nChave encontrada!\n");
  }
  else {
    printf("\nChave não encontrada.\n");
  }
  printf("\n=>Busca pela chave recursivo, na árvore recursiva: ");
  scanf("%d", &k);
  end = buscaArvBinRec(raizRec, k);
  if (end != NULL) {
      printf("\nChave encontrada!\n");
  }
  else {
    printf("\nChave não encontrada.\n");
  }
  printf("\n=>Busca em uma árvore que não é de pesquisa(Estou usando uma de pesquisa(ABP recursiva), mas o algorítmo serviria em uma que não é)\n");
  printf("\nBusque pelo nó: ");
  scanf("%d", &k);
  end = buscaAB(raizRec, k);
  if (end != NULL) {
      printf("\nChave encontrada!\n");
  }
  else {
    printf("\nChave não encontrada.\n");
  }
  printf("\n=>Busca o menor valor de uma árvore binária de pesquisa(Nesse caso, ABP iterativa):\n");//O enunciado não específica em qual árvore deve ser, então escolhi essa pois foi a mais fácil de pensar :")
  end = buscaEnderecoDoMenor(raizIt);
  if (end != NULL) {
      printf("\nO valor da menor chave é %d\n", end->chave);
  }
  else {
    printf("\nÁrvore vazia!\n");
  }
  printf("\n=>Busca o maior valor de uma árvore binária de pesquisa(Nesse caso, ABP iterativa):\n");//Mesma coisa do procedimento acima... k
  end = buscaEnderecoDoMaior(raizIt);
  if (end != NULL) {
      printf("\nO valor da maior chave é %d\n", end->chave);
  }
  else {
    printf("\nÁrvore vazia!\n");
  }
  printf("\n=>(ABP iterativa)Busca pela chave: ");
  scanf("%d", &k);
  printf("\nRetorna o endereço do ponteiro que contém o endereço da chave:\n");
  endDOend = buscaEnderecoDoPonteiro(&raizIt, k);
  if (endDOend != NULL) {
      printf("\nChave %d encontrada!\n", (*endDOend)->chave);
  }
  else {
    printf("\nChave não encontrada.\n");
  }
  printf("\n=>(ABP iterativa)Encontra a menor chave:\n");
  printf("\nRetorna o endereço do ponteiro que contém o endereço da chave:\n");
  endDOend = buscaEnderecoDoPonteiroDoMenor(&raizIt);
  if (endDOend != NULL) {
      printf("\nO valor da menor chave é %d\n", (*endDOend)->chave);
  }
  else {
    printf("\nÁrvore vazia!\n");
  }
  printf("\n=>(ABP iterativa)Encontra a maior chave:\n");
  printf("\nRetorna o endereço do ponteiro que contém o endereço da chave:\n");
  endDOend = buscaEnderecoDoPonteiroDoMaior(&raizIt);
  if (endDOend != NULL) {
      printf("\nO valor da maior chave é %d\n", (*endDOend)->chave);
  }
  else {
    printf("\nÁrvore vazia!\n");
  }
  return 0;
}
