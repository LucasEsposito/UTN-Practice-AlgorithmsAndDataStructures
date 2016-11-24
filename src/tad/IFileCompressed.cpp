#include "../util/UFile.cpp"
#include "ITable.cpp"
#include "IFileInput.cpp"
#include "ITable.cpp"
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#ifndef xIFileCompressed
#define xIFileCompressed


//rw
struct IFileCompressed
{
   char ca[256];
   string ff;
   FILE* arch;
   //UFile* ufile = new UFile(arch);
   UFile* ufile;
   string nom;

   //no hay constructor >.<

   void setFilename(string filename)
   {
      nom = filename;
      ff = filename+".szdat";
      strcpy(ca,ff.c_str());
      arch = fopen(ca,"w+b");
      ufile = new UFile(arch);
   }

   void save(IFileInput* fi, ITable* table)
   {
      char caracter;
      int k;
      //caracter = read<char>(fi->f);
      fread(&caracter,1,1,fi->f);
      for(int i = 0; !feof(fi->f); i++)
      {
         ICode* icode = table->getCode((int)caracter);
         k = icode->getLength();
         for(int n = 0; n<k; n++)
         {
            ufile->writeBit(icode->getBitAt(n));
         }
         //caracter = read<char>(fi->f);
         fread(&caracter,1,1,fi->f);
      }
      ufile->flush();
   }

   string getFilename()
   {
      return nom;
   }

   void restore(IFileInput* fi, ITree* tree)
   {
      int b;
      Node* hoja=NULL;
      string cod = "";
      ICode* codigo=new ICode();
      b = ufile->readBit();
      while(!feof(ufile->file))
      {
         cod += (b==1)?'1':'0';
         codigo->fromString(cod);
         hoja = tree->next(codigo);
         while(hoja!=NULL)
         {
            b = ufile->readBit();
            cod += (b==1)?'1':'0';
            codigo->fromString(cod);
            hoja = tree->next(codigo);
         }
         //write<char>(fi->f,hoja->c);
         fwrite(&hoja->c,1,1,fi->f);
         b = ufile->readBit();
      }
   }
};

#endif
