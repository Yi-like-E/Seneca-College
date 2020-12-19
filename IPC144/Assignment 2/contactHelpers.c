//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"
#include "contacts.h"
#define MAXCONTACTS 5
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
	char NL = 'x';
	int Value;
	while (NL != '\n')
	{
		scanf("%d%c", &Value, &NL);
		if (NL != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	}
	return Value;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int num;
	num = getInt();
	while (num < min || num > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		num = getInt();
	}
	return num;
}

// yes function definition goes here:
int yes(void)
{
	char NL = 'x';
	char yn = 'x';
	int i;

	scanf(" %c%c", &yn, &NL);

	while ((NL != '\n') || (yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n'))
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &yn, &NL);
	}
	if (yn == 'Y' || yn == 'y')
	{
		i = 1;
	}
	else if (yn == 'N' || yn == 'n')
	{
		i = 0;
	}

	return i;
}

// menu function definition goes here:
int menu(void)
{
	int option;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	option = getIntInRange(0, 6);
	printf("\n");

	return option;
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
	int flag = 0;
	int choice;
	struct Contact contacts[MAXCONTACTS] = 
	{ { { "Rick", {'\0'}, "Grimes" }, { 11, "Trailer Park", 0, "A7A 2J2", "King City" }, { "4161112222", "4162223333", "4163334444" } },
	  { { "Maggie", "R.", "Greene" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9051112222", "9052223333", "9053334444" } },
	  { { "Morgan", "A.", "Jones" }, { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" }, { "7051112222", "7052223333", "7053334444" } },
      { { "Sasha", {'\0'}, "Williams" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, { "9052223333", "9052223333", "9054445555" } },
	};

	while (flag != 1)
	{
		choice = menu();
		if (choice == 1)
		{
			displayContacts(contacts, MAXCONTACTS);
			//printf("\n");
			pause();
			printf("\n");
		}
		else if (choice == 2)
		{
			addContact(contacts,MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
		}
		else if (choice == 3)
		{
			updateContact(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
		}
		else if (choice == 4)
		{
			deleteContact(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
		}
		else if (choice == 5)
		{
			searchContacts(contacts, MAXCONTACTS);
			pause();
			printf("\n");
		}
		else if (choice == 6)
		{
			sortContacts(contacts, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
		}
		else
		{
			printf("Exit the program? (Y)es/(N)o: ");
			choice = yes();
			if (choice == 1)
			{
				printf("\nContact Management System: terminated");
				printf("\n");
				flag = 1;
			}
			else
			{
				printf("\n");
				flag = 0;
			}
		}
	}
}






// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;

	while (needInput == 1)
	{
		scanf("%[^\n]", phoneNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		for (int i = 0; i < 10; i++)
		{
			if (isdigit(phoneNum[i]) == 0 || strlen(phoneNum) != 10)
			{
				printf("Enter a 10-digit phone number: ");
				scanf("%[^\n]", phoneNum);
				clearKeyboard();
				i = 0;
			}
			else
			{
				needInput = 0;
			}
		}
		
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int index = -1;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			index = i;
		}
	}

	return index;
}


// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}


// displayContact:
void displayContact(const struct Contact* contact)
{
	if (contact->name.middleInitial[0] == '\0')
	{
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
	}
	else
	{
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	printf("    C: %-10s H: %-10s B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	
	if (contact->address.apartmentNumber > 0)
	{
		printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	}
	else
	{
		printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
	}
}


// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int valid = 0;

	displayContactHeader();

	for (int i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) > 0)
		{
			displayContact(&contacts[i]);
			valid += 1;
		}
	}

	displayContactFooter(valid);
}


// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char cellNum[11] = {0};
	int result;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);
	result = findContactIndex(contacts, size, cellNum);

	if ( result > 0)
	{
		printf("\n");
		displayContact(&contacts[result]);
		printf("\n");
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
}


// addContact:
void addContact(struct Contact contacts[], int size)
{
	char cellNum[11] = { 0 };
	int index = -1;

	for (int i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0)
		{
			index = i;
		}
	}

	if (index == -1)
	{
		printf("*** ERROR: The contact list is full! ***\n");
	}
	else
	{
		getContact(&contacts[index]);
		printf("--- New contact added! ---\n");
	}
	
}


// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	char cellNum[11] = { 0 };
	int result;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	result = findContactIndex(contacts, size, cellNum);

	if (result > -1)
	{
		printf("\nContact found:\n");
		displayContact(&contacts[result]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		if (yes() != 0)
		{
			getName(contacts[result]->name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() != 0)
		{
			getAddress(&contacts[result].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() != 0)
		{
			getNumbers(&contacts[result].numbers);
		}
		printf("--- Contact Updated! ---\n"); 
	}
	else
	{
		printf("*** Contact NOT FOUND ***\n");
	}
}


// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	char cellNum[11] = { 0 };
	int result;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cellNum);

	result = findContactIndex(contacts, size, cellNum);

	if (result == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\nContact found:\n");
		displayContact(&contacts[result]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes() != 0)
		{
			*contacts[result].numbers.cell = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
}


// sortContacts:
void sortContacts(struct Contact contacts[], int size)
{
	//printf("<<< Feature to sort is unavailable >>>\n");
	int i, j;
	struct Contact temp = {0};

	for (i = size-1; i> 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0)
			{
				temp = contacts[j];
				contacts[j] = contacts[j + 1];
				contacts[j + 1] = temp;
			}
		}
	}
	printf("--- Contacts Sorted! ---\n");
}
