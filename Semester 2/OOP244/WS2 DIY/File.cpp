/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/01/28
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {

   FILE* fptr;

   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(char* postalCode) {
       bool result = false;
       if (fscanf(fptr, "%3s,", postalCode) == 1) {
           result = true;
       }
       return result;
   }

   bool read(int& pop) {
       bool result = false;
       if (fscanf(fptr, "%d\n", &pop) == 1) {
           result = true;
       }
       return result;
   }

}