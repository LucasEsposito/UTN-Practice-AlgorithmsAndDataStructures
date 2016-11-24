
#include <iostream>
using namespace std;

#ifndef xIcode
#define xIcode

struct ICode
{
   int arr[128];
   int len;
   ICode()
   {
      for(int i=0;i<128;i++)
      {
         arr[i]=0;
      }
      len=0;
   }
   /*
    * Retorna el i-esimo bit (1 o 0) de este codigo Huffman.
    * @param i Es el i-esimo bit del codigo, contando de izquierda a derecha entre 0 y 127
    * @return El i-esimo bit (1 o 0) de este codigo Huffman (contando desde la izquierda)
    */
   int getBitAt(int i)
   {
      return arr[i];
   }

   /*
    * Retorna la longitud de este codigo Huffman (la cantidad de digitos binarios).
    * @return La longitud del codigo Huffman
    */
   int getLength()
   {
      return len;
   }

   /**
    * Inicializa codigo Huffman tomando los caracteres de la cadena sCod
    * que deben ser "ceros" o "unos".
    * @param sCod Es la cadena compuesta de "ceros" y "unos" con los que se debe inicializar este codigo
    */
   void fromString(string sCod)
   {
      for(int i=0;sCod[i]!='\0';i++)
      {
         arr[i]=sCod[i];
         len++;
      }
   }
};

#endif




