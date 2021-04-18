/*
 Section:    NII
 Date:       2021/01/28
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {

   bool openFile(const char filename[]);
   void closeFile();
   // Calculate number of records in the file 
   int noOfRecords();
   // Check if reading one postal code data at a time from the file is successful
   bool read(char* postalCode);
   // Check if reading one population data at a time from the file is successful
   bool read(int& pop);
}
#endif // !SDDS_FILE_H_
