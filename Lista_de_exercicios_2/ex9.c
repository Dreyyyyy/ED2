#include <stdio.h>
#include <stdlib.h>

//9. Apresente um algoritmo que devolve o fatorial de um inteiro n dado.

int calc_fatorial(int n);

int main() {
    int n = 0, res = 0;
    printf("Digite um valor para ser calculado seu fatorial: ");
    scanf("%d", &n);
    res = calc_fatorial(n);
    printf("O fatorial será:%d\n", res);
    return 0;
}

int calc_fatorial(int n) {
    if (n == 0 || n ==1) {//Caso base: Quando n for 1 ou 0, o fatorial será 1
        return 1;
    }
    else {
        return n * calc_fatorial(n-1);//Caso recursivo: Empilha o n atual * o retorno da função com o n-1
    }
}
