
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>

using namespace std;

#ifndef xUFile
#define xUFile

struct UFile
{
   FILE* file;
   string sBuffer;
   int bitNo;

   UFile(FILE* f)
   {
      file=f;
      bitNo=0;
      sBuffer="";
   }

   int readBit()
   {
      if( sBuffer.length()==0 || bitNo==8 )
      {
         int b;
         fread(&b,sizeof(char),1,file);

         if( b>=0 && !feof(file))
         {
            sBuffer = std::bitset<8>(b).to_string();
            bitNo=0;
         }
         else
         {
            return -1;
         }
      }

      return sBuffer[bitNo++]-'0';
   }

   void writeBit(int b)
   {
      // concateno el bit
      sBuffer+=(b==1)?'1':'0';

      if( sBuffer.length()==8 )
      {
         char* dummy;
         int x = strtol(sBuffer.c_str(), &dummy, 2);
         fwrite(&x,sizeof(char),1,file);
         sBuffer="";
      }
   }

   void reset()
   {
      bitNo=0;
      sBuffer="";
   }

   void _rpad(string& s,char c, int n)
   {
      for(unsigned int i=0; i<s.length()-n; i++)
      {
         s+=c;
      }
   }

   void flush()
   {
      // completo con ceros
      if( sBuffer.length()>0 )
      {
         _rpad(sBuffer,'0',8);
      }

      // grabo los bits que no completaron 1 byte
      if( sBuffer.length()>0 )
      {
         char* dummy;
         int x = strtol(sBuffer.c_str(), &dummy, 2);
         fwrite(&x,sizeof(char),1,file);
      }

      bitNo=0;
      sBuffer="";
   }

   void writeLength(unsigned long n)
   {
      fwrite(&n,sizeof(long),1,file);
   }

   unsigned long readLength()
   {
      unsigned long n;
      fread(&n,sizeof(long),1,file);
      return n;
   }
};

#endif
