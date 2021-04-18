/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/01/28
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define DATAFILE "PCpopulationsComplete.csv"

namespace sdds {

	struct Report {
		char* postalCode;
		int population;
	};

	// Sort the dynamic array of reports based on population
	void sort();
	// Load one report structure with the data from the file
	bool load(Report& reports);
	// Loads all the file into an allocated dynamic array of reports and record into the array
	bool load(const char file[]);
	// Displays one PCpopulation record at a time
	void display(const Report& reports);
	// Display all the PCpopulation sorted by population in ascending order with total population at the end
	void display();
	// Deallocate all the postal codes in the report elements then deallocate the report array
	void deallocateMemory();
}
#endif // SDDS_POPULATION_H_