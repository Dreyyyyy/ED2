#include <stdio.h>
#include <stdlib.h>
/*fb = Fator de balanceamento:
*1 se direita maior que esquerda
*0 se balanceado
*-1 se esquerda maior que direita
*/
struct no {
    int chave;
    int bal;
    struct no *esq;
    struct no *dir;
};
typedef struct no TAVL;

void rotacao_simples_dir(TAVL **raiz);

void rotacao_simples_esq(TAVL **raiz);

void  rot_esq_dir (TAVL **raiz);

void rot_dir_esq(TAVL **raiz);

int insereAVL(int x, TAVL **p);

void imprime_pre_ordem(TAVL *raiz);
