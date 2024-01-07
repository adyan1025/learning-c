//Lab 6, Program by Adyan Chowdhury
/* This program repeatedly asks for an integer input until the user types -1. I keep track how many times the user types a valid number (number that is 0 or positive).
The sum of all numbers typed is kept track of in order to calculate the average once terminated. To find the largest number, 
I initialized a variable (largest_number) set to the smallest possible allowed (zero since we don't want a negative number). 
From there the program checks if that number is greater than what it is. Of course any positive number would be greater than 0, 
so the program sets that number to the variable "largest_number". And if there is a number that is larger than the current
largest number, then that number becomes the new largest number. I used the same logic to find the smallest number except I
initialized the variable "smallest_number" to 2147483647 which is the highest value an integer variable type can be. Then I
would check if there is a number smaller than "smallest_number" and so on.*/

#include <stdio.h>

int getNum();
double avg(int sums, int iterations); 
void programTerminated (int iterations, double total_average, int largest_number, int smallest_number);

int main() {
    int sentinel = -1;
    int number;
    int largest_number = 0;
    int smallest_number = 2147483647;
    int iterations = 0;
    int sums = 0;
    double total_average;
    while (1) {
        number = getNum();
        if (number >= 0) {
            iterations++;
            sums += number;

            if (number > largest_number) {
                largest_number = number;
            }

            if (number < smallest_number) { 
                smallest_number = number;
            }
        }
        else if (number == sentinel) { 
            total_average = avg(sums, iterations);
            programTerminated(iterations, total_average, largest_number, smallest_number);
            break;
        }
        else {
            printf("Please enter a positive number.\n");
        }
    }
    return 0;
}

int getNum() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    return number;
}

double avg(int sums, int iterations) {
    double average = (double) sums/iterations;
    return average;
}

void programTerminated (int iterations, double total_average, int largest_number, int smallest_number) {
    if (iterations == 1) {
        printf("You typed %d integer.", iterations);
    }
    else {
        printf("You typed %d integers.", iterations);
    }
    printf("\nThe average of all numbers is %lf.", total_average);
    printf("\nThe largest number is %d.", largest_number);
    printf("\nThe smallest number is %d.", smallest_number);
}