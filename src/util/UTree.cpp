
#include "../tad/Node.h"
#include <iostream>
using namespace std;


#ifndef XUTREE
#define XUTREE

template <typename T> struct StackNode
{
   T info;       // valor que contiene el nodo
   StackNode<T>* sig; // puntero al siguiente nodo
};


template <typename T>
struct Stack
{
   StackNode<T>* p;

   Stack()
   {
      p = NULL;
   }

   bool isEmpty()
   {
      return p==NULL;
   }

   T eliminarPrimerNodo()
   {
      T ret = p->info;
      StackNode<T>* aux = p->sig;

      delete p;
      p = aux;

      return ret;
   }

   void insertarPrimerNodo(T v)
   {
      StackNode<T>* nuevo = new StackNode<T>();
      nuevo->info = v;
      nuevo->sig = p;
      p = nuevo;
   }

   void push(T v)
   {
      insertarPrimerNodo(v);
   }

   T pop()
   {
      return eliminarPrimerNodo();
   }

};

struct UTree
{
   Stack<Node*> pila;
   Stack<string> pilaCod;

   UTree(Node* root)
   {
      pila.push(root);
      pilaCod.push("");
   }

   Node* next(string& cod)
   {
      bool hoja=false;
      Node* p = NULL;
      Node* aux = NULL;
      string zz;

      while( !pila.isEmpty() && !hoja )
      {
         p=pila.pop();
         zz=pilaCod.pop();

         if( p->der!=NULL )
         {
            pila.push(p->der);
            aux=new Node();
            aux->n=1;
            aux->sig=NULL;
            pilaCod.push(zz+"1");
         }

         if( p->izq!=NULL )
         {
            pila.push(p->izq);
            aux=new Node();
            aux->n=0;
            aux->sig=NULL;
            pilaCod.push(zz+"0");
         }

         if( p->izq==NULL && p->der==NULL)
         {
            hoja=true;
            cod.clear();
            cod.append(zz);
         }
         else
         {
            p=NULL;
         }
      }

      return p;
   }
};

#endif
