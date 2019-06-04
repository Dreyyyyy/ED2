#include "bib.h"

//Biblioteca com funções de uma das aulas do site wiki da USP, editei-as e comentei para entendimento sobre o assunto

void rotacao_simples_dir(TAVL **raiz) {
    TAVL *aux = NULL;//Ponteiro temporário para auxiliar na rotação
    aux = *raiz;//Auxiliar recebe o endereço do nó raiz
    TAVL *novaRaiz = NULL;//Ponteiro que será o novo nó raiz após a rotação
    novaRaiz = aux->esq;//O novo nó raiz será o filho do filho da raiz atual, logo, o ponteiro "novaRaiz" recebe o endereço do filho do filho da raiz
    aux->esq = novaRaiz->dir;//Organiza o nó raiz atual no seu lugar, ou seja, compondo o lado direito da tree com a nova raiz sendo seu filho menor
    novaRaiz->dir = aux;//Continuando a organização, o novo nó raiz se torna pai de seu pai, organizando assim o lado direito da árvore
    novaRaiz->bal = 0;//Ajusta as novas alturas de cada nó
    aux->bal = 0;//Ajusta as novas alturas de cada nó
    *raiz = novaRaiz;//O ponteiro que aponta para o nó raíz anterior recebe o endereço do novo raíz
}

void rotacao_simples_esq(TAVL **raiz) {
    TAVL *aux = NULL;//Ponteiro temporário para auxiliar na rotação
    aux = *raiz;//Auxiliar recebe o endereço do nó raiz
    TAVL *novaRaiz = NULL;//Ponteiro que será o novo nó raiz após a rotação
    novaRaiz = aux->dir;//O novo nó raiz será o filho do filho da raiz atual, logo, o ponteiro "novaRaiz" recebe o endereço do filho do filho da raiz
    aux->dir = novaRaiz->esq;//Organiza o nó raiz atual no seu lugar, ou seja, compondo o lado esquerdo da tree com a nova raiz sendo seu filho maior
    novaRaiz->esq = aux;//Continuando a organização, o novo nó raiz se torna pai de seu pai, organizando assim o lado esquerdo da árvore
    novaRaiz->bal = 0;//Ajusta as novas alturas de cada nó
    aux->bal = 0;//Ajusta as novas alturas de cada nó
    *raiz = novaRaiz;//O ponteiro que aponta para o nó raíz anterior recebe o endereço do novo raíz
}

void  rot_esq_dir (TAVL **raiz) {
    TAVL *aux1 = NULL;//Ponteiro temporário para auxiliar na rotação
    aux1 = *raiz;//Auxiliar recebe o endereço do nó raiz
    TAVL *aux2 = NULL;//Ponteiro temporário para auxiliar na rotação
    aux2 = aux1->esq;//Auxiliar recebe o ponteiro para o esquerdo da raiz atual
    TAVL *novaRaiz = NULL;//Ponteiro que será o novo nó raiz após a rotação
    novaRaiz = aux2->dir;//Recebe o nó cujo este será o novo raiz
    aux1->esq = novaRaiz->dir;//Separa o raiz atual da árvore, junto com sua sub árvore caso exista, e o posiciona a direita
    aux2->dir = novaRaiz->esq;//Separa o lado esquerdo da árvore do novo nó raiz
    novaRaiz->esq = aux2;//A árvore é reconstruída, juntando o lado esquerdo
    novaRaiz->dir = aux1;//E em sequência o direito ao novo nó raiz
    switch (novaRaiz->bal) {//Quando se aplica uma rotação, mudamos de posição apenas três nós, logo, os dois movidos que não são a nova raiz terão seu fb ajustados
        case -1:
            aux2->bal = 0; 
            aux1->bal = 1;
            break;
        case 0:
            aux2->bal = 0;
            aux1->bal = 0;
            break;
        case 1:
            aux2->bal = -1;
            aux1->bal = 0;
            break;
    }
    novaRaiz->bal = 0;//Como a rotação balanceou a árvore, a altura da raiz será 0
    *raiz = novaRaiz;//Ponteiro recebe o novo raiz
}

void rot_dir_esq(TAVL **raiz) {
    TAVL *aux2 = NULL;//Ponteiro temporário para auxiliar na rotação
    aux2 = *raiz;//Auxiliar recebe o endereço do nó raiz
    TAVL *aux1 = NULL;//Ponteiro temporário para auxiliar na rotação
    aux1 = aux2->dir;//Auxiliar recebe o ponteiro para o direito da raiz atual
    TAVL *novoRaiz = NULL;//Ponteiro que será o novo nó raiz após a rotação
    novoRaiz = aux1->esq;//Recebe o nó cujo este será o novo raiz
    aux1->esq = novoRaiz->dir;//Separa o raiz atual da árvore, junto com sua sub árvore caso exista, e o posiciona a esquerda
    aux2->dir = novoRaiz->esq;//Separa o lado direito da árvore do novo nó raiz
    novoRaiz->esq = aux2;//A árvore é reconstruída, juntando o lado esquerdo
    novoRaiz->dir = aux1;//E em sequência o direito ao novo nó raiz
    switch (novoRaiz->bal) {//Quando se aplica uma rotação, mudamos de posição apenas três nós, logo, os dois movidos que não são a nova raiz terão seu fb ajustados
        case -1:
            aux2->bal = 0;
            aux1->bal = 1; 
            break;
        case 0:
            aux2->bal = 0;
            aux1->bal = 0;
            break;
        case 1:
            aux2->bal = -1;
            aux1->bal = 0;
            break;
    }
    novoRaiz->bal = 0;//Como a rotação balanceou a árvore, a altura da raiz será 0
    *raiz = novoRaiz;//Ponteiro para raiz recebe o novo raiz
}

int insereAVL(int x, TAVL **p) {
    int cresceu;
    /* Se a arvore esta vazia insere. */
    if (*p == NULL) {
        *p = (TAVL *) malloc(sizeof(TAVL));
        (*p)->chave = x;
    /* Caso houvesse outros dados eles deveriam ser copiados aqui. */
        (*p)->dir = (*p)->esq = NULL;
    /* Balanceamento de uma folha e sempre perfeito */
        (*p)->bal = 0;
    /* Esta sub arvore cresceu */
        cresceu = 1;
    }
    /* Senao verifica se tem que inserir a esquerda */
    else if ((*p)->chave > x) {
    /* Tenta inserir a esquerda e ve se a sub-arvore cresceu */
        cresceu = insereAVL(x, &(*p)->esq);
        if (cresceu) {
        /* Verifica o estado atual de balanceamento */
            switch((*p)->bal) {/* Se a arvore dir. era maior nao ha crescimento*/
                case 1:
                    (*p)->bal = 0;
                    cresceu = 0;
                    break;
                /* Se a arvore dir. tinha tamanho igual, houve crescimento*/
                case 0:
                    (*p)->bal = -1;
                    cresceu = 1;
                    break;
                /* Se a sub-arvore da esq. ja era maior, deve-se re-balancear.*/
                case -1:
                /* Verifica qual o caso de re-balanceamento*/
                /* Se a arvore da esquerda do filho da esquerda esta mais*/
                /* alta basta uma rotacao para direita.*/
                    if ((*p)->esq->bal == -1) {/* Rotacao para direita.*/
                        rotacao_simples_dir(p);/* Acerta os balanceamentos. */
                        (*p)->bal = (*p)->dir->bal = 0;
                    }
                    else {/* Rotacao dupla.*/
                        /* Primeiro a esquerda.*/
                        rotacao_simples_esq(&(*p)->esq);
                        /* Depois a direita.*/
                        rotacao_simples_dir(p);
                        /* Acerta balanceamentos. */
                        if ((*p)->bal == -1) {
                            (*p)->esq->bal = 0;
                            (*p)->dir->bal = 1;
                        }
                        else {
                            (*p)->dir->bal = 0;
                            (*p)->esq->bal = -(*p)->bal;
                        }
                        (*p)->bal = 0;
                    }
                    cresceu = 0;
            }
        }
    }
        /* Verifica se tem que inserir a direita. */
        else if ((*p)->chave < x) {
        /* Tenta inserir a direita e ve se a sub-arvore cresceu */
            cresceu = insereAVL(x, &(*p)->dir);
            if (cresceu) {
                /* Verifica o estado atual de balanceamento */
                switch((*p)->bal) {
                /* Se a arvore esq. era maior nao ha crescimento*/
                    case -1:
                        (*p)->bal = 0;
                        cresceu = 0;
                        break;
                        /* Se a arvore esq. tinha tamanho igual, houve crescimento*/
                    case 0:      
                        (*p)->bal = 1;
                        cresceu = 1;
                        break;
                        /* Se a arvore da dir. ja era maior, deve-se re-balancear.*/
                    case 1:
                        /* Verifica qual o caso de re-balanceamento.*/
                        /* Se a arvore da direita do filho da direita esta mais*/
                        /* alta basta uma rotacao para esquerda.*/
                        if ((*p)->dir->bal == 1) {
                            /* Rotacao para esquerda.*/
                            rotacao_simples_esq(p);
                            /* Acerta os balanceamentos.*/
                            (*p)->bal = (*p)->esq->bal = 0;
                        }
                        else {
                            /* Rotacao dupla.*/
                            /* Primeiro a direita.*/
                            rotacao_simples_dir(&(*p)->dir);
                            /* Depois a esquerda.*/
                            rotacao_simples_esq(p);
                            /* Acerta balanceamentos.*/
                            if ((*p)->bal == -1) {
                                (*p)->esq->bal = 0;
                                (*p)->dir->bal = 1;
                            }
                            else {
                                (*p)->dir->bal = 0;
                                (*p)->esq->bal = -(*p)->bal;
                            }
                            (*p)->bal = 0;
                        }
                        cresceu = 0;
                }
            }
        }
    else {
        cresceu = 0;
    }
    return cresceu;
}          

void imprime_pre_ordem(TAVL *raiz) {//Visita o raiz, o filho da direita e o filho da esquerda, nessa exata ordem
  if (raiz == NULL) {//Caso base: Encerra a função quando a raiz não tiver mais valores
    return;
  }
  else {
    printf("\n%d\n", raiz->chave);
    imprime_pre_ordem(raiz->esq);//Caso recursivo: Percorre a esquerda
    imprime_pre_ordem(raiz->dir);//Caso recursivo: Percorre a direita
  }
}
