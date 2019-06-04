#include <stdio.h>
#include <stdlib.h>

struct no {
    int chave;
    int alt;
    struct no *esq;
    struct no *dir;
};
typedef struct no TAVL;

void rotacao_simples_dir(TAVL *raiz);

void rotacao_simples_esq(TAVL *raiz);

