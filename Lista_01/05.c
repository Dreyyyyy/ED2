/*5) Apresente dois procedimentos recursivos que descobrem o índice do menor elemento de um vetor dado.
O índice deve ser guardado em uma variável local de outro procedimento (ex. main),
logo você deve adicionar uma passagem por referência no protótipo da função. Embora os procedimentos façam a mesma coisa,
 eles devem ser baseados em definições recursivas distintas para o vetor: uma definição deve definir o vetor a partir
 de dois subvetores distintos a outra deve definí-lo apenas  a partir de 1 subvetor.*/

#include <stdio.h>
#include <stdlib.h>

void busca1(int *v, int ini, int fim, int *menor);
void busca2(int *v, int ini, int fim, int *menor);

 int main(int argc, char const *argv[]) {
   int v[6] = {10, 4, 8, 2, 6, 12}, menor = v[0], i = 0;
   for (i = 0; i < 6; i++) {
    printf("%d ", v[i]);
   }
   busca1(v, 0, 5, &menor);
   printf("\n(Busca1)Índice do menor elemento é: %d\n", menor);
   busca2(v, 0, 5, &menor);
   printf("\n(Busca2)Índice do menor elemento é: %d\n", menor);
   return 0;
 }

 void busca1(int *v, int ini, int fim, int *menor) {
   if (fim < ini) return;
   else {
     int meio = 0;
     meio = (fim + ini)/2;
     if (v[meio] <= *menor) {
       *menor = v[meio];
     }
     busca1(v, ini, meio-1, menor);
     busca1(v, meio+1, fim, menor);
   }
 }

void busca2(int *v, int ini, int fim, int *menor) {
  if (fim < ini) return;
  else {
    if (v[ini] <= *menor) {
      *menor = v[ini];
    }
    else {
      busca2(v, ini+1, fim, menor);
    }
  }
}
