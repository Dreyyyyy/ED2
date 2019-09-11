/*0) Proponha uma struct auto-referenciada com três campos quaisquer. Após isso apresente um procedimento que recebe um ponteiro p
para essa struct e imprime na tela o endereço do segundo campo da struct acessível a partir de p.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int chave;
  char dado;
  struct no *prox;
} No;

void imprime_endereco(No *p);

int main(int argc, char const *argv[]) {
  No *p = NULL;
  p = (No*)malloc(sizeof(No));
  if (p == NULL) return -1;
  else {
    imprime_endereco(p);
  }
  return 0;
}

void imprime_endereco(No *p) {
  printf("Endereço do 1ª campo da struct: %p\n", &(p)->chave);
  printf("Endereço do 2ª campo da struct: %p\n", &(p)->dado);
  printf("Endereço do 3ª campo da struct: %p\n", &(p)->prox);
}
