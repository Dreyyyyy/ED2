typedef struct tree {
	int key;
	struct tree *left;
	struct tree *right;
}nodeABP;

/*
-Entrada: Vetor ordenado, primeiro elemento do array [start], último [end] e ponteiro de ponteiro para o root;
-Saída(efeito): Árvore balanceada enraizada em *root contendo todos os elementos do vetor v.
*/
nodeABP *create_node(int key);

void doisB(int *array, int start, int end, nodeABP **root);

nodeABP *insert_ABP(nodeABP **root, int key);
