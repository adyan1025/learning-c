#include <stdio.h>

int dayNumber(int month, int day, int year);
int withinXPercent(double reference, double data, int x);
void boilingPoint();

int main() {
    //Coding Problem 1
    int month;
    int day;
    int year;
    printf("Enter the date (month day year): ");
    scanf("%d %d %d", &month, &day, &year);
    int total_days = dayNumber(month, day, year);
    printf("%d/%d/%d is day number %d of the year %d.", month, day, year, total_days, year);

    //Coding Problem 2
    boilingPoint();

    return 0;
}

int dayNumber(int month, int day, int year) {
    int total_days = 0;
    int days_per_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
        days_per_month[1] = 29;
    }
    
    for (int i = 0; i < (month - 1); i++) {
        total_days = total_days + days_per_month[i];
    }
    total_days = total_days + day;

    return total_days;

}

int withinXPercent(double ref, double data, int x) {
    double lowerBound = ref - (x/100.0) * ref;
    double upperBound = ref + (x/100.0) * ref;
    if (lowerBound <= data && data <= upperBound) {
        return 1;
    }
    return 0;
}

void boilingPoint() {
    double temperature;
    int x = 5;
    double reference[] = {100.0, 357.0, 1187.0, 2193.0, 2660.0};
    printf("\nEnter a temperature: ");
    scanf("%lf", &temperature);

    if (withinXPercent(reference[0], temperature, x) == 1) {
        printf("The substance is Water.");
    }
    else if (withinXPercent(reference[1], temperature, x) == 1) {
        printf("The substance is Mercury.");
    }
    else if (withinXPercent(reference[2], temperature, x) == 1) {
        printf("The substance is Copper.");
    }
    else if (withinXPercent(reference[3], temperature, x) == 1) {
        printf("The substance is Silver.");
    }
    else if (withinXPercent(reference[4], temperature, x) == 1) {
        printf("The substance is Gold.");
    }
    else {
        printf("The substance is unknown.");
    }

}