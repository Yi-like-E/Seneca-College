//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "contactHelpers.h"
#include "contacts.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

void getName(struct Name* name)
{

    char yesNo;
    int num;

    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    //scanf("%s%*c", &yesNo); //<--- Incorrect, not a c string, must be a char
    //scanf("%c%*c", &yesNo);
    num = yes();

    if (num == 1) //(yesNo == 'y' || yesNo == 'Y')
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %6[^\n]", name->middleInitial);
        clearKeyboard();
    }
    else
    {
        for (int i = 0; i < 6; i++)
        {
            name->middleInitial[i] = '\0';
        }
    }
        
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    int num, yn;

    printf("Please enter the contact's street number: ");
    address->streetNumber = getInt();
    if (address->streetNumber < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        address->streetNumber = getInt();
    }

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    yn = yes();

    if (yn == 1)
    {
        printf("Please enter the contact's apartment number: ");
        address->apartmentNumber = getInt();
        if (address->apartmentNumber < 0)
        {
            printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            address->apartmentNumber = getInt();
        }
    }
    else
    {
        address->apartmentNumber = '\0';
    }

    printf("Please enter the contact's postal code: ");
    scanf(" %7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    int yn;

    printf("Please enter the contact's cell phone number: ");
    //scanf("%10[^\n]%*c", numbers->cell);
    getTenDigitPhone(numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    yn = yes();

    if (yn == 1)
    {
        printf("Please enter the contact's home phone number: ");
        //scanf("%10[^\n]%*c", numbers->home);
        getTenDigitPhone(numbers->home);
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            numbers->home[i] = '\0';
        }
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    yn = yes();

    if (yn == 1)
    {
        printf("Please enter the contact's business phone number: ");
        //scanf("%10[^\n]%*c", numbers->business);
        getTenDigitPhone(numbers->business);
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            numbers->business[i] = '\0';
        }
    }

}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:

void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
