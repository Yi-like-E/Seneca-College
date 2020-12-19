//==============================================
// Name:           
// Student Number: 
// Email:          
// Section:        
// Workshop:       2 (in-lab)
//==============================================

# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>

int main(void)
{
	float input, balance1, balance2, balance3, balance4, balance5, GST, total;
	int loonies, quarters, dimes, nickels, pennies;
	

	printf("Please enter the amount to be paid: $");
	scanf("%f", &input);

	
	loonies = input / 1;
	balance1 = input - loonies;
	quarters = balance1 / 0.25;
	balance2 = balance1 - quarters * 0.25;
	dimes = balance2 / 0.10 ;
	balance3 = balance2 - dimes * 0.1;
	nickels = balance3 / 0.05;
	balance4 = balance3 - nickels * 0.05;
	pennies = balance4 / 0.01;
	balance5 = balance4 - pennies * 0.01;


	printf("Loonies required: %d, balance owing $%.2f\n", loonies, balance1);
	printf("Quarters required: %d, balance owing $%.2f\n", quarters, balance2);
	

	return 0;
}
