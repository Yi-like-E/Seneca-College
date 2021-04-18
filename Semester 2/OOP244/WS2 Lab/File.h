/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/01/26
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char* name);
   bool read(int& empNo);
   bool read(double& salary);
 
}
#endif // !SDDS_FILE_H_
