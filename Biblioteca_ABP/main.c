#include "bib.h"

int main(int argc, char const *argv[]) {
  NoArvBinaria *raiz = NULL, *aux = NULL, **aux2 = NULL, **aux3 = NULL;
  int op = 0, k = 0;
  do {
    printf("\n=>Digite o número que deseja inserir na ABP: ");
    scanf("%d", &k);
    printf("\n=>Inserindo dado...\n");
    aux = insereArvBinRec(&raiz, k);
    printf("=>Número %d inserido com sucesso!\n", aux->chave);
    printf("\n=>Tecle 1 para inserir um novo valor: ");
    scanf("%d", &op);
  } while (op == 1);
  printf("\n=>Arvore atual:\n");
  printa_pre_ordem(raiz);

  printf("\n=>Busca com algoritmo de ABP:\n");
  printf("=>Digite o número a ser buscado: ");
  scanf("%d", &k);
  printf("\n=>Buscando número...\n");
  aux = buscaArvBinRec(raiz, k);
  printf("=>Número %d encontrado!\n", aux->chave);

  printf("\n=>Busca com algoritmo de AB:\n");
  printf("=>Digite o número a ser buscado: ");
  scanf("%d", &k);
  printf("\n=>Buscando número...\n");
  aux = buscaAB(raiz, k);
  printf("=>Número %d encontrado!\n", aux->chave);

  printf("\n=>Busca, com retorno do endereço do ponteiro de ponteiro para o nó encontrado:\n");
  printf("=>Digite o número a ser buscado: ");
  scanf("%d", &k);
  printf("\n=>Buscando número...\n");
  aux2 = buscaEnderecoDoPonteiro(&raiz, k);
  printf("=>Número %d encontrado!\n", (*aux2)->chave);

  printf("\n=>Remove o primeiro nó folha encontrado, em pré-ordem:\n");
  printf("\n=>Buscando nó folha...\n");
  aux3 = buscafolha(&raiz);
  printf("=>Nó folha encontrado!\n");
  printf("=>Removendo nó folha...\n");
  removeFolha(aux3);
  printf("=>Nó removido com sucesso! Arvore atual printada logo abaixo:\n");
  printa_pre_ordem(raiz);

  printf("\n=>Remove o primeiro nó com um encontrado, em pré-ordem:\n");
  printf("\n=>Buscando nó com um filho...\n");
  aux3 = buscaumfilho(&raiz);
  printf("=>Nó com um filho encontrado!\n");
  printf("=>Removendo nó com um filho...\n");
  removeNoComSomenteUmFilho(aux3);
  printf("=>Nó removido com sucesso! Arvore atual printada logo abaixo:\n");
  printa_pre_ordem(raiz);
  return 0;
}
