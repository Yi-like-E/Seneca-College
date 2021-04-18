/*
 Section:    NII
 Date:       2021/01/26
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */
#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& employees) {
      bool ok = false;
      char name[128];
      int size;
     
      if(read(employees.m_empNo)){
          if (read(employees.m_salary)) {
              if (read(name)) {
                  size = strLen(name);
                  employees.m_name = new char[size + 1];
                  strCpy(employees.m_name, name);
                  ok = true;
              }
          }
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];
          for (i = 0; i < noOfEmployees; i++) {
              load(employees[i]);
          }
          if (i != noOfEmployees) {
              cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
          }
          else {
              ok = true;
          }
          closeFile();
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& emp) {
       cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary;
   }

   void display() {
       int i, row = 1;
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();
       for (i = 0; i < noOfEmployees; i++) {
           cout << row << "- ";
           display(employees[i]);
           cout << endl;
           row++;
       }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory() {
       int i;
       for (i = 0; i < noOfEmployees; i++) {
           delete[] employees[i].m_name;
       }
       delete[] employees;
   }


}
