#include <iostream>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "ITable.cpp"
using namespace std;

#ifndef xIFileCode
#define xIFileCode

//rw

struct IFileCode
{
   char ca[256];
   string filename;
   FILE* arch;
   IFileCode()
   {
      arch=NULL;
   };
   void setFilename(string f)
   {
      filename=f+".szcod";
      strcpy(ca,filename.c_str());
      arch= fopen(ca,"w+b");
   }

   void save(ITable* table)
   {
      unsigned long m;
       for(int i=0;i<256;i++)
       {
          //write<char>(arch,table->caracter[i]);
          //write<int>(arch,table->nlen[i]); //grabo longitud del codigo
          fwrite(&table->caracter[i],1,1,arch);
          fwrite(&table->nlen[i],1,1,arch);

          m=table->nlen[i]/8 + (table->nlen[i]%8!=0?1:0);
          fwrite(&table->n[i],m,1,arch);
       }
   }

   ITree* load()
   {
      ITree* tree=new ITree();
      char caracter;
      int n, nlen;
      unsigned long m;
      ITable* table=new ITable();
      IList* ilist=new IList();
      for (int i=0; !feof(arch) ; i++)
      {
         //caracter=read<char>(arch);
         fread(&caracter,1,1,arch);
         //nlen=read<int>(arch); //leo longitud del codigo
         fread(&nlen,sizeof(int),1,arch);

         m=nlen/8 + (nlen%8!=0?1:0);
         fread(&n,m,1,arch);
         table->n[i]=n;
         table->caracter[i]=caracter;
         table->nlen[i]=nlen;
      }
      ilist=table->createSortedList();
      tree = ilist->toTree();
      return tree;
   }
};

#endif
