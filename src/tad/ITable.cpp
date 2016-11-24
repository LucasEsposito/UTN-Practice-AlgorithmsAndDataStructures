#include "IList.cpp"
#include "ICode.cpp"
#include "ITree.cpp"

#ifndef xITable
#define xITable

/*void insertarNode(Node*& p, Node* n)
{
   if(p==NULL)
   {
      p==n;
   }
   else
   {
      Node* aux = p;
      while(aux->sig!=NULL)
      {
         aux = aux->sig;
      }
      aux->sig = n;
   }
}*/

struct ITable
{
   char caracter[256];
   ICode* cH[256]; //codigo
   int nlen[256]; // long del codigo
   int n[256]; // apariciones
   // 256 = tamaño maximo en ascii.

   ITable()
   {
      for(int i=0;i<256;i++)
      {
         n[i]=0;
         nlen[i]=0;
         cH[i]=new ICode();
         caracter[i]=i;
      }
   }

   // Increment el contador asociado al caracter c
   void addCount(int c)
   {
      n[c]++;
   }

   long getCount(int c)
   {
      return n[c];
   }

   IList* createSortedList()
   {
      int nu=0;
      IList* ilist= new IList();
      ilist->lst = NULL;
      Node* nuevo = new Node();
      for(int i=0;i<256;i++)
      {
         nuevo->n = nlen[i];
         for(int j=0;j<cH[i]->len;j++)
         {
           nu=nu*10+cH[i]->arr[j];
         }
         nuevo->c = nu;
         ilist->insertNode(nuevo);
      }
      return ilist;
   }

   void loadHuffmanCodes(ITree* t)
   {
      ICode* cod= new ICode();
      Node* hoja=t->next(cod);
      while(hoja!=NULL)
      {
         cH[hoja->c]=cod;
         hoja=t->next(cod);
      }
   }

   ICode* getCode(int c)
   {
      return cH[c];
   }
};

#endif
