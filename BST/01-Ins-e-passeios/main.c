#include "BinTree.h"
#include <stdio.h>

void PrintTree(BinTree* tree){
  printf("Preorder:");
  BinTree_preorder(tree->root);
  printf("\nInorder:");
  BinTree_inorder(tree->root);
  putchar('\n');
}

int main(){
  int V[] = {10, 1, 2, 14, 16, 13};
  BinTree* tree = BinTree_create();
  for(int i=0; i<6; i++)
    if(!BinTree_insert(tree, V[i]))
      printf("Nao consegui inserir o V[%d]=%d\n", i, V[i]);
  PrintTree(tree);
  return 0;
}
//PRE: 10, 1, 2, 14, 13, 16, 