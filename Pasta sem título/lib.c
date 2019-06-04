#include "lib.h"

void rotacao_simples_dir(TAVL *raiz) {
    TAVL *aux = NULL;//Ponteiro temporário para auxiliar na rotação
    aux = *raiz;//Auxiliar recebe o endereço do nó raiz
    TAVL *novaRaiz = NULL;//Ponteiro que será o novo nó raiz após a rotação
    novaRaiz = aux->esq;//O novo nó raiz será o filho do filho da raiz atual, logo, o ponteiro "novaRaiz" recebe o endereço do filho do filho da raiz
    aux->esq = novaRaiz->dir;//Organiza o nó raiz atual no seu lugar, ou seja, compondo o lado direito da tree com a nova raiz sendo seu filho menor
    novaRaiz->dir = aux;//Continuando a organização, o novo nó raiz se torna pai de seu pai, organizando assim o lado direito da árvore
    novaRaiz->alt = 0;//Ajusta as novas alturas de cada nó
    aux->alt = 0;//Ajusta as novas alturas de cada nó
    *raiz = novaRaiz;//O ponteiro que aponta para o nó raíz anterior recebe o endereço do novo raíz
}

void rotacao_simples_esq(TAVL *raiz) {
    TAVL aux = NULL;//Ponteiro temporário para auxiliar na rotação
    aux = *raiz;//Auxiliar recebe o endereço do nó raiz
    TAVL *novaRaiz = NULL;//Ponteiro que será o novo nó raiz após a rotação
    novaRaiz = aux->dir;//O novo nó raiz será o filho do filho da raiz atual, logo, o ponteiro "novaRaiz" recebe o endereço do filho do filho da raiz
    aux->dir = novaRaiz->esq;//Organiza o nó raiz atual no seu lugar, ou seja, compondo o lado esquerdo da tree com a nova raiz sendo seu filho maior
    novaRaiz->esq = aux;//Continuando a organização, o novo nó raiz se torna pai de seu pai, organizando assim o lado esquerdo da árvore
    novaRaiz->alt = 0;//Ajusta as novas alturas de cada nó
    aux->alt = 0;//Ajusta as novas alturas de cada nó
    *raiz = novaRaiz;//O ponteiro que aponta para o nó raíz anterior recebe o endereço do novo raíz
}
