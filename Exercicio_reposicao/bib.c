#include "bib.h"

nodeABP *create_node(int key) {
    nodeABP *newNode = NULL;    
    newNode = (nodeABP*)malloc(sizeof(nodeABP));
    if (newNode == NULL) {
        printf("\nThe S.O not alocate memory.\n");
    }
    else {
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
}

nodeABP *insert_ABP(nodeABP **root, int key) {
    if (*root == NULL) {
        *root = create_node(key);
    }
    else if ((*root)->key < key) {
        return insert_ABP(&(*root)->right, key);
    }
    else if ((*root)->key > key) {
        return insert_ABP(&(*root)->left, key);
    }
} 

void doisB(int *array, int start, int end, nodeABP **root) {
    if (start <= end) {
        int mid = (start+end)/2;
        insert_ABP(root, array[mid]);
        doisB(array, start, mid-1, root);
        doisB(array, mid+1, end, root);
    }
}
