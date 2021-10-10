#include "BinTree.h"
#include <stdlib.h>
#include <stdio.h>
//Headers auxiliares
void Transplant(BinTree*, TNo*, TNo*);

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

_Bool BinTree_insert_r(TNo** root, TNo* z){
  int k = z->key;
  if((*root) == NULL){
    *root = z;
    return true;
  }
  z->p = *root; 
  if (k < (*root)->key)
    return BinTree_insert_r(&(*root)->left, z);
  else
    return BinTree_insert_r(&(*root)->right, z);
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

void BinTree_posorder(TNo* root){
  if(root != NULL){
    BinTree_posorder(root->left);
    BinTree_posorder(root->right);
    printf("%d, ", root->key);
  }
}

TNo* BinTree_search_i(BinTree* T, int k){
  TNo* x = T->root;
  while(x != NULL && k != x->key)
    x = (k < x->key) ? x->left:x->right;
  return x;
}

/*
TNo* BinTree_search_r(TNo* x, int k){
  if ( x == NULL || k == x->key)
    return x;
  //return BinTree_search_r((k < x->key) ? x->left : x->right, k);
}
*/

TNo* BinTree_search_r(TNo* x, int k){
  if ( x == NULL || k == x->key)
    return x;
  if (k < x->key)
    return BinTree_search_r(x->left, k);
  else
    return BinTree_search_r(x->right, k);
}

TNo* BinTree_minimum(TNo* x){
  while(x->left != NULL)
    x = x->left;
  return x;
}

void Transplant(BinTree* T, TNo* u, TNo* v){
  if(u->p == NULL)
    T->root = v;
  else
    if(u == u->p->left)
      u->p->left = v;
    else 
      u->p->right = v;
  
  if(v != NULL)
    v->p = u->p;
}

_Bool BinTree_delete(BinTree* T, TNo* z){
  if(T==NULL || T->root == NULL) return false;
  if(z->left == NULL)
    Transplant(T, z, z->right);
  else if(z->right == NULL)
    Transplant(T, z, z->left);
  else{
    TNo* y = BinTree_minimum(z->right);
    if(y->p != z){
      Transplant(T, y, y->right);
      y->right = z->right;
      y->right->p = y;
    }
    Transplant(T, z, y);
    y->left = z->left;
    y->left->p = y;
  }
  free(z);
  return true;
}