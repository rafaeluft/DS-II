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
    if(!BinTree_insert_r(&(tree->root), TNo_createNFill(V[i])))
      printf("Nao consegui inserir o V[%d]=%d\n", i, V[i]);
  PrintTree(tree);
  int key = 11;
  TNo* result = BinTree_search_r(tree->root, key);
  if(result != NULL){
    printf("Found %d\n", result->key);
    if(!BinTree_delete(tree, result))
      printf("Não consegui deletar\n");
  }
  else
    printf("Key: %d not found!\n", key);
  PrintTree(tree);
  return 0;
}
//PRE: 10, 1, 2, 14, 13, 16, 