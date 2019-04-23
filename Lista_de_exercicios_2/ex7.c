#include <stdio.h>
#include <stdlib.h>

/*7. Apresente um algoritmo que devolve a soma de todos os números pares do intervalo de
zero a um dado n.*/

int soma_invervalo(int n);

int main() {
    int n = 0, soma = 0;
    printf("Digite um n qualquer: ");
    scanf("%d", &n);
    soma = soma_invervalo(n);
    printf("A soma entre o n informado e 0 será de:%d\n", soma);
    return 0;
}

int soma_invervalo(int n) {
    if (n == 0) {//Caso base: Retorna 0 quando n chegar a 0
        return 0;
    }
    else {
        return n + soma_invervalo(n-1);//Caso recursivo: Empilha o valor do n atual mais o retorno da função com n-1
    }
}
