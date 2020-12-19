#define _CRT_SECURE_NO_WARNINGS
#define MIN 3
#define MAX 10
#define MINNUM 1
#include <stdio.h>

// Put your code below:

int main(void) {


	int i, num_day, num, highest = -100, lowest = 100, highestday = 0, lowestday = 0, sum = 0;
	int high[MAX], low[MAX];
	double avg_temp;

	printf("---=== IPC Temperature Calculator V2.0 ===---");
	printf("\n");

	printf("Please enter the number of days, between %d and %d, inclusive: ", MIN, MAX);
	scanf("%d", &num_day);
	printf("\n");

	if (num_day < MIN || num_day > MAX) {
		printf("Invalid entry, please enter a number between %d and %d, inclusive: ", MIN, MAX);
		scanf("%d", &num_day);
		printf("\n");
	}


	for (i = 0; i < num_day; i++) {

		printf("Day %d - High: ", i+1);
		scanf("%d", &high[i]);

		printf("Day %d - Low: ", i+1);
		scanf("%d", &low[i]);

		if (high[i] > highest) {

			highest = high[i];
			highestday = i;
		}

		if (low[i] < lowest) {

			lowest = low[i];
			lowestday = i;
		}
	}

	printf("\n");
	printf("Day  Hi  Low\n");
	for (i = 0; i < num_day; i++) {
		printf("%d    %d    %d\n", i+1, high[i], low[i]);
	}

	printf("\n");
	printf("The highest temperature was %d, on day %d\n", highest, highestday);
	printf("The lowest temperature was %d, on day %d\n", lowest, lowestday);
	printf("\n");

	printf("Enter a number between %d and %d to see the average temperature for the entered number of days,"
		"enter a negative number to exit: ", MINNUM, num_day);
	scanf("%d", &num);
	printf("\n");

	if (num < 0) {
		printf("Goodbye!");
		//return 0;
	}

	while (num > num_day || num < MINNUM) {
		printf("Invalid entry, please enter a number between %d and %d, inclusive: ", MINNUM, num_day);
		scanf("%d", &num);
		printf("\n");
	}

	while (num >= MINNUM && num <= num_day) {
		for (i = 0; i < num; i++) {
			sum += high[i];
			sum += low[i];
		}
		printf("The average temperature up to day %d is %.2lf\n", num, (double)sum / (num * 2));
		printf("\n");
		printf("Enter a number between %d and %d to see the average temperature for the entered number of days,"
			"enter a negative number to exit: ", MINNUM, num_day);
		scanf("%d", &num);
		printf("\n");

		sum = 0;

		if (num < 0) {
			printf("Goodbye!");
			return 0;
		}
		while (num > num_day || num < MINNUM) {
			printf("Invalid entry, please enter a number between %d and %d, inclusive: ", MINNUM, num_day);
			scanf("%d", &num);
			printf("\n");
			if (num < 0) {
				printf("Goodbye!");
				return 0;
			}
		}
	}

	return 0;
}


