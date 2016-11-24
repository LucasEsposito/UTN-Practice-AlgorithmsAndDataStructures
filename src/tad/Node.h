#include <stdio.h>

#ifndef xNode
#define xNode

struct Node
{
   int c;
   long n;

   Node* sig;
   Node* izq;
   Node* der;
   Node()
   {
      c=0;
      n=0;
      sig=NULL;
      izq=NULL;
      der=NULL;
   }
};

#endif
