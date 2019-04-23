#include <stdio.h>
#include <stdlib.h>

//1. Apresente um algoritmo para pesquisar uma dada chave em uma lista.

typedef struct Lista {
    int chave;
    struct Lista *prox;
}TipoLista;

TipoLista *aloca_no(int chave);
void cria_lista(TipoLista **lista, int chave);
void printa_lista(TipoLista *lista);
int busca_elemento_rec(TipoLista *lista, int chave);

int main() {
    TipoLista *lista = NULL;
    int i =0, chave = 0, resp = 0;
    for (i = 0; i < 10; i++) {
        chave = rand () % 50;
        printf("=>Insere:%d\n", chave);
        cria_lista(&lista, chave);
    } 
    printf("\n=>Printa Lista:\n");
    printa_lista(lista);
    printf("\n=>Busca o elemento: ");
    scanf("%d", &chave);
    resp = busca_elemento_rec(lista, chave);
    if (resp == 1) {
        printf("\nChave encontrada!\n");
    }
    else {
        printf("\nChave não encontrada!\n");
    }
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

void printa_lista(TipoLista *lista) {
    if (lista == NULL) {
        printf("\nLista vazia!\n");
    }
    else {
        do {
            printf("=>Chave: %d\n", lista->chave);
            lista = lista->prox;
        } while (lista != NULL);
    }
}

int busca_elemento_rec(TipoLista *lista, int chave) {
    if (lista == NULL) {//Caso base 1: Retorna 0 caso a lista esteja vazia ou o elemento não seja encontrado
        return 0;
    }
    else if (lista->chave == chave) {//Caso base 2: Retorna 1 quando o elemento for encontrado na lista
        return 1;
    }
    else {
        busca_elemento_rec(lista->prox, chave);//Caso recursivo: Chama a própria função, passando o ponteiro para o próximo nó
    }
}
