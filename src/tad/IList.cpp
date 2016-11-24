
#include "Node.h"
#include "ITree.cpp"

#ifndef xIList
#define xIList

struct IList
{
   Node* lst;
   IList()
   {
      lst=NULL;
   }

   Node* removeFirstNode()
   {
      Node* ret = lst; //guardo el primer nodo
      lst = lst->sig; //elimino el primer nodo
      return ret; // retorno el primer nodo
   }

   void insertNode(Node* n)
   {
      Node* nuevo = n;
      nuevo->sig = NULL;
      Node* aux = lst;
      Node* ant = NULL;
      while(aux->sig!=NULL and (aux->n < nuevo->n))
      {
        ant = aux;
        aux = aux->sig;
      }
      if(ant == NULL)
      {
         lst = nuevo;
      }
      else
      {
         ant->sig = nuevo;
      }
      nuevo->sig = aux;
   }

   ITree* toTree()
   {
      Node* a;
      Node* b;
      Node* nuevo=NULL;
      a = removeFirstNode();
      b = removeFirstNode();
      while(b != NULL)
      {
         nuevo->izq = a;
         nuevo->der = b;
         insertNode(nuevo);
         a = removeFirstNode();
         b = removeFirstNode();
      }
      ITree* itree=new ITree();
      itree->setRoot(nuevo);
      return itree;
   }
};

#endif
