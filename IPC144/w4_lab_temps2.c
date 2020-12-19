//==============================================
// Name:           YiHsun Lee
// Student Number: 129713202
// Email:          ylee212@myseneca.ca
// Section:        NTT
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Put your code below:

int main(void) {

	int i, num;
	int high[10], low[10]; //assign the size of 10 since the number of days can go up to 10

	printf("---=== IPC Temperature Calculator V2.0 ===---");
	printf("\n");

	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &num);
	printf("\n");

	if (num < 3 || num >10) {
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &num);
		printf("\n");
	}

	

	for (i = 1; i <= num; i++) {

		printf("Day %d - High: ", i);
		scanf("%d", &high[i]);

		printf("Day %d - Low: ", i);
		scanf("%d", &low[i]);
							
	}
	
	printf("\n");
	printf("Day  Hi  Low\n");
	for (i = 1; i <= num; i++) {

		printf("%d    %d    %d\n", i, high[i], low[i]);

	}


	return 0;
}