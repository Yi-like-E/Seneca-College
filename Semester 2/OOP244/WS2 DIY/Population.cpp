/*
 Section:    NII
 Date:       2021/01/28
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"


using namespace std;

namespace sdds {

	int noOfReport;
	Report* reports;

    void sort() {
        int i, j;
        Report temp;
        for (i = noOfReport - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (reports[j].population > reports[j + 1].population) {
                    temp = reports[j];
                    reports[j] = reports[j + 1];
                    reports[j + 1] = temp;
                }
            }
        }
    }

    bool load(Report& reports) {
        bool ok = false;
        char postalCode[4];
        int size;

        if (read(postalCode)) {
            if (read(reports.population)) {
                    size = strlen(postalCode);
                    reports.postalCode = new char[size + 1];
                    strcpy(reports.postalCode, postalCode);
                    ok = true;
                }
            
        }
        return ok;
    }

    bool load(const char file[]) {
        bool ok = false;
        int i = 0;
        if (openFile("PCpopulationsComplete.csv")) {
            noOfReport = noOfRecords();
            reports = new Report[noOfReport];
            for (i = 0; i < noOfReport; i++) {
                load(reports[i]);
            }
            if (i != noOfReport) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            else {
                ok = true;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    void display(const Report& reports) {
        cout << reports.postalCode << ":  " << reports.population;
    }
    void display() {
        int i, row = 1, total = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (i = 0; i < noOfReport; i++) {
            cout << row << "- ";
            display(reports[i]);
            cout << endl;
            row++;
            total += reports[i].population; // to calculate the total population
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << total << endl;
    }
    void deallocateMemory() {
        int i;
        for (i = 0; i < noOfReport; i++) {
            delete[] reports[i].postalCode;
        }
        delete[] reports;
    }
}
