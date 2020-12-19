//==============================================
// Name:           
// Student Number: 
// Email:          
// Section:        
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#define NUMS 4
#include <stdio.h>
// Put your code below:

int main(void) {

	int i, high, low, highest = -40, lowest = 40, highestday = 0, lowestday = 0;
	double avg, sum_high = 0.0, sum_low = 0.0, avg_high, avg_low ;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 1; i <= NUMS; i++) {

		printf("Enter the high value for day %d: ", i);
		scanf("%d", &high);
		printf("\n");

		printf("Enter the low value for day %d: ", i);
		scanf("%d", &low);
		printf("\n");

		
		while (high > 40 || low <-40 || low > high) {

			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");

			printf("Enter the high value for day %d: ", i);
			scanf("%d", &high);
			printf("\n");

			printf("Enter the low value for day %d: ", i);
			scanf("%d", &low);
			printf("\n");

		}

		if (high > highest) {

			highest = high;
			highestday = i;

		}

		if (low < lowest) {

			lowest = low;
			lowestday = i;
		}

		sum_high += (double)high;
		sum_low += (double)low;

	}
	avg_low = sum_low / (double)NUMS;
	avg_high = sum_high / (double)NUMS;
	avg = (sum_high + sum_low) / ((double)NUMS * 2.0);
	printf("The average (mean) LOW temperature was: %.2lf\n", avg_low);
	printf("The average (mean) HIGH temperature was: %.2lf\n", avg_high);
	printf("The average (mean) temperature was: %.2lf\n", avg);
	printf("The highest temperature was: %d, on day %d\n", highest, highestday);
	printf("The lowest temperature was: %d, on day %d\n", lowest, lowestday);

	return 0;
}

