#include <stdio.h>
#include <stdlib.h>

//2. Apresente um algoritmo para imprimir todos os elementos de uma lista, do primeiro ao último.

typedef struct Lista {
    int chave;
    struct Lista *prox;
}TipoLista;

TipoLista *aloca_no(int chave);
void cria_lista(TipoLista **lista, int chave);
void printa_lista_rec(TipoLista *lista);

int main() {
    TipoLista *lista = NULL;
    int i =0, chave = 0, resp = 0;
    for (i = 0; i < 10; i++) {
        chave = rand () % 50;
        printf("=>Insere:%d\n", chave);
        cria_lista(&lista, chave);
    } 
    printf("\n=>Printa Lista:\n");
    printa_lista_rec(lista);
    return 0;
}

TipoLista *aloca_no(int chave) {
    TipoLista *novoNo = NULL;
    novoNo = (TipoLista*)malloc(sizeof(TipoLista));
    if (novoNo == NULL) {
        printf("\nO S.O não alocou memória!\n");
    }
    else {
        novoNo->chave = chave;
        novoNo->prox = NULL;
        return novoNo;
    }
}

void cria_lista(TipoLista **lista, int chave) {
    if (*lista == NULL) {
        *lista = aloca_no(chave);
    }
    else {
        TipoLista *novoNo = NULL;
        novoNo = aloca_no(chave);
        novoNo->prox = *lista;
        *lista = novoNo;
    }
}

void printa_lista_rec(TipoLista *lista) {
    if (lista == NULL) {//Caso base: Encerra a função caso a lista esteja vazia ou caso chegar ao fim da lista
        return;
    }
    else {
        printf("=>Chave: %d\n", lista->chave);//Printa a chave do nó atual
        printa_lista_rec(lista->prox);//Caso recursivo: Chama a própria função com o próximo nó, porém após printar o valor do campo atual anterior
    }
}
