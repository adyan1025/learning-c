/*
----------------------------------------------------------------------------
Problem 1

void letter_grade(int points, char *letter, bool *justmissed) {
    *justmissed = false;
    if ((points >= 90 ) && (points <= 100)) {
        *letter = 'A';
    }
    else if ((points >= 80 ) && (points <= 89)) {
        *letter = 'B';
        if (points == 89) {
            *justmissed = true;
        }
    }
    else if ((points >= 70 ) && (points <= 79)) {
        *letter = 'C';
        if (points == 79) {
            *justmissed = true;
        }
    }
    else if ((points >= 60 ) && (points <= 69)) {
        *letter = 'D';
        if (points == 69) {
            *justmissed = true;
        }
    }
    else if ((points >= 0 ) && (points <= 59)) {
        *letter = 'F';
        if (points == 59) {
            *justmissed = true;
        }
    }
    else {
        printf("Invalid number.");
    }
}
----------------------------------------------------------------------------
Problem 2

You might want to return a value with 'return' statement instead of returning with the output parameter because 
you want to keep the original value of the variable because the value being returned is a copy of what was passed 
into the function.

You would use an output parameter if you want to actually change the variable itself. You can also change multiple
variables at once where as you can only return one value with the return statement (as of now).

----------------------------------------------------------------------------
Problem 3

All the functions have the ability to call the grumpy function.

----------------------------------------------------------------------------
*/

#include <stdio.h>

void instructions();
void decideForm(char method);
double optionA();
void calculateSlope(double *x1, double *x2, double *y1, double *y2);
double optionB();
double y_intercept(double *x_value, double *y_value, double *slope);
double optionC();
void slopeIntercept(double slope, double y_intercept);

int main() {
    instructions();
    return 0;
}

void instructions() { //Initial instructions for user input
    char method;
    printf("This program will give you the slope-intercept form.");
    printf("\nThe following are three different methods to create a line equation.");
    printf("\nA = Enter two points.");
    printf("\nB = Enter one point and a slope.");
    printf("\nC = Enter a slope and y-intercept.");
    printf("\nWhich method do you want to choose (Enter letter): ");
    scanf(" %c", &method);
    decideForm(method);
}

void decideForm(char method) {
    switch (method)
    {
    case 'A': //Makes sure both capital and lower case are counted
    case 'a':
        optionA();
        break;
    case 'B':
    case 'b':
        optionB();
        break;
    case 'C':
    case 'c':
        optionC();
        break;
    default: //Error statement if user enters something other than a, b, or c
        printf("\nError. Invalid answer.");
        break;
    }
}

double optionA() { //Function that takes the two points
    double x1, y1, x2, y2;
    printf("\nEnter the first x-value: ");
    scanf("%lf", &x1);
    printf("\nEnter the first y-value: ");
    scanf("%lf", &y1);
    printf("\nEnter the second x-value: ");
    scanf("%lf", &x2);
    printf("\nEnter the second y-value: ");
    scanf("%lf", &y2);
    if ((x1 == x2) && (y1 == y2)) { //Checks if the user entered the same points
        printf("Error. You entered the same points.");
        return 1;
    }
    else if (x1 == x2) { //Checks if the x values are the same
        printf("Error. No slope because of a vertical asymptote.");
        return 1;
    }
    calculateSlope(&x1, &x2, &y1, &y2); //Takes those points and calculates the slope here
}

void calculateSlope(double *x1, double *x2, double *y1, double *y2) {
    double slope = (*y2 - *y1) / (*x2 - *x1);
    y_intercept(x1, y1, &slope); 
    //Uses the slope and some point to get y intercept
}

double optionB() {
    double x, y, slope;
    printf("\nEnter the x-value: ");
    scanf("%lf", &x);
    printf("\nEnter the y-value: ");
    scanf("%lf", &y);
    printf("\nEnter a slope: ");
    scanf("%lf", &slope);
    y_intercept(&x, &y, &slope);
    //Passes the entered point and slope to get y intercept
}

//Option A and B both use this function
//Some point and the slop calculate the y-intercept
double y_intercept(double *x_value, double *y_value, double *slope) {
    double b = *y_value - (*slope * *x_value);
    slopeIntercept(*slope, b);
    //After you get the y intercept now you have everything you need to get the slope intercept equation
}

//Takes the values of slope and y-intercept to get slope intercept expression
double optionC() {
    double slope, y_intercept;
    printf("Enter a slope: ");
    scanf("%lf", &slope);
    printf("Enter a y-intercept: ");
    scanf("%lf", &y_intercept);
    /*Option C skips calculating the slope and y intercept obviously and passes the values straight to 
    printing the slope intercept.*/
    slopeIntercept(slope, y_intercept);
}

//Prints the slope intercept form
//Option A, B, and C both use this function
void slopeIntercept(double slope, double y_intercept) {
    printf("The slope intercept form is y = %.lfx + %.lf", slope, y_intercept);
}

