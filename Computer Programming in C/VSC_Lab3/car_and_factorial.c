#include <stdio.h>
#include <math.h>

double payment(double car_cost, double down_payment, double annual_interest, double number_of_payments);
double answer(double integer);

int main(void) {
    //Function for Coding Problem 1
    double car_cost;
    double down_payment;
    double annual_interest;
    double number_of_payments;
    printf("CALCULATE LOAN PAYMENT: \n");
    printf("Enter cost of car: ");
    scanf("%lf", &car_cost);
    printf("\nEnter down payment: ");
    scanf("%lf", &down_payment);
    printf("\nEnter annual interest rate: ");
    scanf("%lf", &annual_interest);
    printf("\nEnter number of payments: ");
    scanf("%lf", &number_of_payments);
    double monthly_payment = payment(car_cost, down_payment, annual_interest, number_of_payments);
    printf("\nYour monthly payment is: $%.2lf.\n", monthly_payment);

    //Function for Coding Problem 2
    double integer;
    printf("\nEnter an integer: ");
    scanf("%lf", &integer);
    double solution = answer(integer);
    printf("\n%1.0lf! equals aproximately %.4lf.", integer, solution);
    return 0;
}

//Coding Problem 1
double payment(double car_cost, double down_payment, double annual_interest, double number_of_payments) {
    double principle = car_cost - down_payment;
    double monthly_interest = annual_interest * (1.0/12.0);
    double monthly_payment = -1 * (principle * (monthly_interest * ((pow((1 + monthly_interest), number_of_payments)))/(1 - pow((1 + monthly_interest), number_of_payments))));
    return monthly_payment;
}

//Coding Problem 2
double answer(double integer) {
    const double e = 2.718281827;
    const double PI = 3.14159265;
    double solution = (pow((integer/e), integer)) * (sqrt(PI * ((2 * integer) + 1.0/3.0)));
    return solution;
}

/*
Tested Values/Outputs

Problem 1 (Usingn Test Values on Chart (Last One uses Annual Interest Rate of 6))
Your monthly payment is: $539.06.
Your monthly payment is: $559.29.
Your monthly payment is: $579.98.
Your monthly payment is: $601.14.
Your monthly payment is: $622.75.
Your monthly payment is: $15000.00.

Problem 2 (Using Test Values on Chart)
1! equals aproximately 0.9960.
2! equals aproximately 1.9974.
3! equals aproximately 5.9961.
4! equals aproximately 23.9909.
5! equals aproximately 119.9700.
6! equals aproximately 719.8728.
7! equals aproximately 5039.3375.
8! equals aproximately 40315.9030.
*/
