#include "bib.h"

int main(void) {
    TAVL *raiz = NULL;
    int chave = 0, op = 0;
    do {
        printf("=>Insere: ");
        scanf("%d", &chave);
        insereAVL(chave, &raiz);
        imprime_pre_ordem(raiz);
        printf("=>Novamente? Tecle 1: ");
        scanf("%d", &op);
    }while(op == 1);
    return 0;
}
