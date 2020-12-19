#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3
#include <stdio.h>
// Put your code below:
int main(void) {

	int i, high, low;
	double avg, sum, sum_high=0.0, sum_low=0.0;
		
	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 1; i <= NUMS; i++) {

		printf("Enter the high value for day %d:", i);
		scanf("%d", &high);
		printf("\n");
		
		printf("Enter the low value for day %d:", i);
		scanf("%d", &low);
		printf("\n");


		while (high > 40 || low <-40 || low > high) {				//  || high < -40 || low > 40

			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");

			printf("Enter the high value for day %d:", i);
			scanf("%d", &high);
			printf("\n");

			printf("Enter the low value for day %d:", i);
			scanf("%d", &low);
			printf("\n");	
				
		}
		sum_high += (double)high;
		sum_low += (double)low;		
	} 
	avg = (sum_high + sum_low) / ((double)NUMS * 2.0);
	printf("The average (mean) temperature was: %.2lf", avg);	

	return 0;
}

