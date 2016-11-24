#include "ICode.cpp"
#include "Node.h"

#include "../util/UTree.cpp"


#ifndef xITree
#define xITree

struct ITree
{
   UTree* utree;
   Node* raiz;

   //asigna el nodo raiz del arbol
   void setRoot(Node* root)
   {
      utree = new UTree(root);
      raiz=root;
   }

   Node* getRoot()
   {
      return raiz;
   }

   Node* next(ICode* cod)
   {
      string s;
      Node* x = utree->next(s);
      cod->fromString(s);
      return x;
   }
};

#endif
