//==============================================
// Name:           
// Student Number: 
// Email:          
// Section:        
// Workshop:       2 (at-home)
//==============================================

// Paste your in-lab code below and upgrade it to the at-home specifications

# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main(void)
{
	float input, GST, total;
	int moneyowed, balance1, balance2, balance3, balance4, balance5, loonies, quarters, dimes, nickels, pennies;


	printf("Please enter the amount to be paid: $");
	scanf("%f", &input);

	GST = input * 0.13 + 0.005;
	total = input + GST;

	printf("GST: %.2f\n", GST);
	printf("Balance owing: %.2f\n", total);

	moneyowed = total * 100;

	balance1 = (moneyowed % 100);
	balance2 = (balance1 % 25);
	balance3 = (balance2 % 10);
	balance4 = (balance3 % 5);
	balance5 = (balance4 % 1);

	loonies = (moneyowed - balance1) / 100;
	quarters = (balance1 - balance2) / 25;	
	dimes = (balance2 - balance3) / 10;		
	nickels = (balance3 - balance4) / 5;		
	pennies = (balance4 - balance5) / 1;	
	
	printf("Loonies required: %d, balance owing $%1.2f\n", loonies, (float)balance1/100);
	printf("Quarters required: %d, balance owing $%1.2f\n", quarters, (float)balance2 / 100);
	printf("Dimes required: %d, balance owing $%1.2f\n", dimes, (float)balance3 / 100);
	printf("Nickels required: %d, balance owing $%1.2f\n", nickels, (float)balance4 / 100);
	printf("Pennies required: %d, balance owing $%1.2f\n", pennies, (float)balance5 / 100);

	return 0;
}
