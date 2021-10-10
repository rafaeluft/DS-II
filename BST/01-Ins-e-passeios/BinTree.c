#include "BinTree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree* BinTree_create(){
  BinTree* tree = malloc(sizeof(BinTree));
  if(tree != NULL){
    tree->root = NULL;
  }return tree;
}
TNo* TNo_createNFill(int key){
  TNo* node = malloc(sizeof(TNo));
  if(node != NULL){
    node->p = NULL;
    node->left = NULL;
    node->right = NULL;
    node->key = key;
  } return node;
}
_Bool BinTree_insert(BinTree* T, int key){
  TNo* z = TNo_createNFill(key);
  if(z==NULL) return false;
  TNo* y = NULL;
  TNo* x = T->root;
  while( x != NULL){
    y = x;
    if (z->key < x->key)
      x = x->left;
    else x = x->right;
  }
  z->p = y;
  if (y == NULL)
    T->root = z;
  else
    if (z->key < y->key)
      y->left = z;
    else y->right = z;

  return true;
}

void BinTree_preorder(TNo* root){
  if(root != NULL){
    printf("%d, ", root->key);
    BinTree_preorder(root->left);
    BinTree_preorder(root->right);
  }
}
void BinTree_inorder(TNo* root){
  if(root != NULL){
    BinTree_inorder(root->left);
    printf("%d, ", root->key);
    BinTree_inorder(root->right);
  }
}