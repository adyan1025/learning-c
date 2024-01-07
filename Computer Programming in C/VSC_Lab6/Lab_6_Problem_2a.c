//Lab 6, Program by Adyan Chowdhury
/* This program solves takes inputs a, b, and c to solve the quadratic equation. It first determines whether or not the result
would be a complex root or not by checking if the discriminant (b^2-4ac) is less than 0. If it is a complex root, the program 
directs it to another function where a series of print statements are printed in order to concatenate the equation together 
with the imaginary number i. If it is not a complex root, the program simply evaluates the problem and returns the result. I 
opted to split the quadratic equation into "First Half and "Second Half." The First Half is the (-b/2a) and the Second Half is 
the sqrt((b^2)-4ac)/2a. The majority of the main function is under a while loop so when the program asks if the user wants to
play again (after typing y when prompted), then the function can loop again.*/

#include <stdio.h>
#include <math.h>

int checkComplex(double a, double b, double c);
void complex(double a, double b, double c);
void complexFirstHalf(double a, double b);
void complexSecondHalf(double a, double b, double c);
double posQuad(double a, double b, double c);
double negQuad(double a, double b, double c);
double firstHalf(double a, double b);
double secondHalf(double a, double b, double c);

int main() {
    int program_end = 1;
    do {
        char y, n;
        char response;
        double a, b, c;
        printf("Enter a:\n");
        scanf("%lf", &a);
        printf("Enter b:\n");
        scanf("%lf", &b);
        printf("Enter c:\n");
        scanf("%lf", &c);
        printf("%lf %lf %lf\n", a, b, c);

        int check_complex = checkComplex(a, b , c);
        if (check_complex == 1) {
            complex(a, b, c);
        }
        else {
            double positive_solution = posQuad(a, b, c);
            double negative_solution = negQuad(a, b, c);
            printf("The solutions are %lf and %lf.", positive_solution, negative_solution);
        }
        printf("\nWould you like to solve another equation? (y/n): ");
        scanf(" %c", &response);
        if (response == 'y') {
            program_end = 1;
            
        }
        else if (response == 'n') {
            break;
            program_end = 0;
            break;
        }
        
    } while (program_end == 1);
    

    return 0;
}

int checkComplex(double a, double b, double c) {
    double inside_root = (pow(b, 2)) - (4*a*c);
    if (inside_root < 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void complex(double a, double b, double c) {
    printf("The solutions are (");
    complexFirstHalf(a, b);
    printf(" + ");
    complexSecondHalf(a, b, c);
    printf(") and (");
    complexFirstHalf(a, b);
    printf(" - ");
    complexSecondHalf(a, b, c);
    printf(").");
}

//Complex second and first half

void complexFirstHalf(double a, double b) {
    double result = -b / (2*a);
    printf("%lf", result);
}

void complexSecondHalf(double a, double b, double c) {
    double inside_root = (pow(b, 2)) - (4*a*c);
    double division = sqrt(-1 * inside_root)/(2*a);
    printf("%lfi", division);
}

double posQuad(double a, double b, double c) {
    double first_half = firstHalf(a, b);
    double second_half = secondHalf(a, b, c);
    double result = first_half + second_half;
    return result;
}
double negQuad(double a, double b, double c) {
    double first_half = firstHalf(a, b);
    double second_half = secondHalf(a, b, c);
    double result = first_half - second_half;
    return result;
}
double firstHalf(double a, double b) {
    double result = -b / (2*a);
    return result;
}
double secondHalf(double a, double b, double c) {
    double inside_root = (pow(b, 2)) - (4*a*c);
    double division = sqrt(inside_root)/(2*a);
    return division;
}

