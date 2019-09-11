/*1)  Apresente um procedimento que recebe um ponteiro de ponteiro para um nó de uma struct  (a mesma da questão anterior).
Sua função deve criar 3 variáveis ponteiros e fazer com que cada uma delas aponte para um campo da struct dada.
 Apresente um diagrama ilustrando o mapa de memória constanto todas as variáveis envolvidas.*/

 #include <stdio.h>
 #include <stdlib.h>

 typedef struct no {
   int chave;
   char dado;
   float flutuante;
 } No;

void aponta_pp(No **p);

int main(int argc, char const *argv[]) {
  No *p = NULL;
  p = (No*)malloc(sizeof(No));
  if (p == NULL) return -1;
  else {
    aponta_pp(&p);
  }
  return 0;
}

void aponta_pp(No **p) {
  int *pc = NULL;
  char *pdado = NULL;
  float *pflut = NULL;
  pc = &(*p)->chave;
  pdado = &(*p)->dado;
  pflut = &(*p)->flutuante;
  printf("Endereço do ponteiro para o int: %p\n", &pc);
  printf("Endereço do ponteiro para o char: %p\n", &pdado);
  printf("Endereço do ponteiro para o float: %p\n", &pflut);
  printf("Endereço do campo int: %p\n", pc);
  printf("Endereço do campo char: %p\n", pdado);
  printf("Endereço do campo float: %p\n", pflut);
}
