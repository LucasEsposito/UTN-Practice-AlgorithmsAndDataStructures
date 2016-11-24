#include "ITable.cpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#ifndef xIFileInput
#define xIFileInput

//r



struct IFileInput
{
   string nom;//nombre del archivo
   long l;     //longitud del archivo
   char c[20]; //array donde se encuentra el nombre del archivo
   FILE* f;  //archivo a comprimir


   // no hay constructor.


   ITable* createTable() //bum!!
   {
      l=0;
      ITable* tabla = new ITable();
      for(int i=0;i<256;i++)
      {
         tabla->n[i]=0;
      }
      //char car=read<char>(f);  //leo un caracter del archivo
      char car;
      fread(&car,1,1,f);
      while(!feof(f))//tiene que ser el archivo que nos pasan para comprimir
      {
        // tabla->caracter[car]=car;//es al pedo, pero bue por si las moscas
         tabla->n[(int)car]++;
         l+=sizeof(car);         //incremento la longitud del archivo mientras leo

         //char car=read<char>(f);  //leo un caracter del archivo
         fread(&car,1,1,f);
      }
    return tabla;
   }

   void setFilename(string filename)
   {
      strcpy(c,filename.c_str());
      f= fopen(c,"r+b");
      nom=filename;
   }

   string getFilename()
   {
      return nom;
   }

   long getLength()
   {
     return l;
   }
};

#endif
