//==============================================
// Name:           YiHsun Lee
// Student Number: 129713202
// Email:          ylee212@myseneca.ca
// Section:        NTT
// Date:           11/26/2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents here...                         |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void);

// pause: Empty function definition goes here:
void pause(void);

// getInt: Empty function definition goes here:
int getInt(void);

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max);

// yes: Empty function definition goes here:
int yes(void);

// menu: Empty function definition goes here:
int menu(void);

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void);


// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);


// displayContactHeader
// put function prototype here:
void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int count);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact* contact);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact contacts[], int size);

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact contacts[], int size);

// addContact:
// put function prototype here:
void addContact(struct Contact contacts[], int size);

// updateContact:
// put function prototype here:
void updateContact(struct Contact contacts[], int size);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact contacts[], int size);

// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contacts[], int size);
