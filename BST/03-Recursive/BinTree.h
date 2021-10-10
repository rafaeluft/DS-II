#ifndef BINTREE_H
#define BINTREE_H
#include<stdbool.h>

typedef struct no{
  int key;
  struct no *left;
  struct no *right;
  struct no *p;
}TNo;

typedef struct{
  TNo* root;
}BinTree;

BinTree* BinTree_create();
TNo* TNo_createNFill(int);
_Bool BinTree_insert(BinTree*, int);
_Bool BinTree_insert_r(TNo**, TNo*);
_Bool BinTree_delete(BinTree*, TNo*);

TNo* BinTree_search_i(BinTree*, int);
TNo* BinTree_search_r(TNo*, int);
TNo* BinTree_minimum(TNo*);

void BinTree_preorder(TNo*);
void BinTree_inorder(TNo*);
void BinTree_posorder(TNo*);

#endif
