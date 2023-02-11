/*
 * Program1.c
 *
 *  Created on: Feb 10, 2023
 *      Author: Michelle Chen
 */

#include <stdio.h>

// Function that prints the sales for each month/six-month average
int print_arr(float sales[], char months[][20], int size) {

	if (size == 12) { // Print the sales for each month
		for (int i = 0; i < size; i++) {
			printf("%-8s\t$%0.2f\n", months[i], sales[i]);
		}
	} else if (size == 7) { // Print the six-month moving average sales
		char org_months[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
		for (int i = 0; i < size; i++) {
			printf("%-8s\t- %-8s\t$%0.2f\n", org_months[i], org_months[i+5], sales[i]);
		}
	}

	return 0;
}

// Function that returns an array containing six-month moving average sales
float * six_month(float sales[]) {
	static float six_nums[7];
	float temp;

	for (int i = 0; i < 7; i++) {
		temp = 0;
		for (int j = i; j < i + 6; j++) {
			temp += sales[j];
		}
		six_nums[i] = temp / 6;
	}

	return six_nums;
}

// Function that sorts the sales array, and its corresponding months, in descending order
int sort_arr(float sales[], char months[][20]) {

	float temp_float;
	char temp_char[20];

	for (int i = 0; i < 12; i++) {
		for (int j = i + 1; j < 12; j++) {
			if (sales[i] < sales[j]) { // Sort the sales array
				temp_float = sales[i];
				sales[i] = sales[j];
				sales[j] = temp_float;

				for (int k = 0; k < 20; k++) { // Sort the months array
					temp_char[k] = months[i][k];
					months[i][k] = months[j][k];
					months[j][k] = temp_char[k];
				}
			}
		}
	}

	return 0;
}

// Function that returns the average of the sales array
float avg(float sales[]) {
	float temp = 0;

	for (int i = 0; i < 12; i++) {
		temp += sales[i];
	}

	return (temp / 12);
}

int main() {

	FILE *fptr;
	char file_name[100], months[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	float sales[12], *six_ptr;

	// Open and read in the input file
	printf("Enter the name of the input file: ");
	scanf("%s", file_name);
	fptr = fopen(file_name, "r");

	if (fptr == NULL) { // Catch potential error
		printf("failed to open file\n");
		return 1;
	} else { // Read in the input file, store in the sales array
		for (int i = 0; i < 12; i++) {
			fscanf(fptr, "%f\n", &sales[i]);
		}
	}

	printf("\n------------------------------------------\n\nMonthly sales report for 2022:\n\nMonth\t\tSales\n\n");
	print_arr(sales, months, 12); // Print the monthly sales report
	six_ptr = six_month(sales); // Use six_ptr to point to the six-month moving average array
	sort_arr(sales, months); // Sort the sales and months array in descending order

	printf("\n------------------------------------------\n\nSales summary:\n\n");
	printf("Minimum sales:\t$%0.2f\t(%s)\n", sales[11], months[11]);
	printf("Maximum sales:\t$%0.2f\t(%s)\n", sales[0], months[0]);
	printf("Average sales:\t$%0.2f\n", avg(sales));

	printf("\n------------------------------------------\n\nSix-Month Moving Average Report:\n\n");
	print_arr(six_ptr, months, 7); // Print the six-month moving average report

	printf("\n------------------------------------------\n\nSales Report (Highest to Lowest):\n\nMonth\t\tSales\n\n");
	print_arr(sales, months, 12); // Print the sorted sales report

	fclose(fptr); // Close the input file
	return 0;
}
