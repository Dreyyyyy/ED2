/*3) Com base na caracterização da questão 2, apresente um procedimento recursivo que imprime todos os elementos de uma lista encadeada simples, do primeiro ao último.*/

typedef struct no {
  int chave;
  char dado;
  struct no *prox;
}ListaE;

/*Baseado na struct acima, o procedimento ficaria assim:*/
void imprime_lista_rec(ListaE *p) {
  if (p == NULL) return;
  else {
    printf("Chave: %d || Dado: %c\n", p->chave, p->dado);
    imprime_lista_rec(p->prox);
  }
}
