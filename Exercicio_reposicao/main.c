#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

int main(void) {
    int array[5] = {0,1,2,3,4};
    nodeABP *root = NULL;
    doisB(array, 0, 4, &root);   
    return 0;
}
