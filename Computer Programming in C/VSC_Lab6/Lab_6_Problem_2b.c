//Lab 6, Program by Adyan Chowdhury
/* This program takes the number of months, foxes, and rabbits and then calculates how many foxes and rabbits there
are each month until the month limit is reached or until the rabbits or foxes die. I have two extra functions that simply
calculate the rabbit and fox populations. After the population is calculated, it is set to another variable called
future_rabbits and future_foxes since what is being calculated is the new animal population for the start of the new month.
I then set them to another variable called current_rabbits and current_foxes respectively since after entering the current
month, the future animals become the current ones. I did this so it would not pass the wrong argument to a function and alter 
the calculations. This is all under a loop that itterates until the entered month from the user is reached or breaks out of 
the loop if the program sees that the fox or rabbit population is 0 or under.*/

#include <stdio.h>

#define RABBIT_BIRTHRATE 0.2
#define FOOD_AMOUNT 0.3
#define FOX_DEATHRATE 0.1
#define FOX_RATE_OF_INCREASE 0.1

float rabbitPopulation(float F, float R);
float foxPopulation(float F, float R);

int main() {
    int months;
    float current_foxes;
    float current_rabbits;
    float future_foxes;
    float future_rabbits;
    printf("Select how many months: ");
    scanf("%d", &months);
    printf("Select how many foxes: ");
    scanf("%f", &current_foxes);
    printf("Select how many rabbits: ");
    scanf("%f", &current_rabbits);

    for (int i = 0; i < months; i++) {
        printf("Month %d: %.f foxes and %.f rabbits\n", i + 1, current_foxes, current_rabbits);

        future_rabbits = rabbitPopulation(current_foxes, current_rabbits);
        future_foxes = foxPopulation(current_foxes, current_rabbits);

        current_rabbits = future_rabbits;
        current_foxes = future_foxes;
        if ((future_foxes <= 0)) {
            printf("The foxes have died! %.f rabbits remain.", current_rabbits);
            break;
        }
        if ((future_rabbits <= 0)) {
            printf("The rabbits have died! %.f foxes remain.", current_foxes);
            break;
        }
    }
    return 0;
}

float rabbitPopulation(float F, float R) {
    R = R + (RABBIT_BIRTHRATE * R) - (FOOD_AMOUNT * F);
    return R;
}

float foxPopulation(float F, float R) {
    F = F - (FOX_DEATHRATE * F) + (FOX_RATE_OF_INCREASE * R);
    return F;
}
