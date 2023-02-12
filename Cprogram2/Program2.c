/*
 * Program2.c
 *
 *  Created on: Feb 11, 2023
 *      Author: micchen
 */

#include <stdio.h>

/* Function that prints all possible combinations of scoring plays for a given total score.
 * Use nested for loops (non-recursive approach) for each possible scoring play to iteratively find all combinations.
 */
int NFL_scores(int score) {
	for (int TD_conversion = 0; TD_conversion <= score; TD_conversion++) {
		for (int TD_field = 0; TD_field <= score; TD_field++) {
			for (int touchdown = 0; touchdown <= score; touchdown++) {
				for (int field_goal = 0; field_goal <= score; field_goal++) {
					for (int safety = 0; safety <= score; safety++) {
						if ((TD_conversion * 8 + TD_field * 7 + touchdown * 6 + field_goal * 3 + safety * 2) == score) { // Print the combination, if it adds up to the total score
							printf("%d TD + 2pt, %d TD+FG, %d TD, %d 3pt FG, %d Safety\n", TD_conversion, TD_field, touchdown, field_goal, safety);
						}
					}
				}
			}
		}
	}

	return 0;
}

int main() {

	int score;

	printf("Enter 0 or 1 to STOP\n");

	// Prompt user for score, until value less than or equal to 1 is entered
	while (1) {
		printf("\nEnter the NFL score: ");
		scanf("%d", &score);

		if (score <= 1) {
			printf("Exiting...");
			break;
		}

		printf("\nPossible combinations of scoring plays:\n");
		NFL_scores(score); // If valid score, call function to find combinations
	}

	return 0;
}
