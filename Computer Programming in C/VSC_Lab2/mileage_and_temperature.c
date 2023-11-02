/*
Adyan Chowdhury
Section 005
Mileage Reimbursement & Farenheit to Celcius Converter Program 
*/

#include <stdio.h>

int main() {
    
    //Coding Problem 1
    double first_odometer;
    double last_odometer;
    printf("Enter beginning odometer reading: ");
    scanf("%lf", &first_odometer);
    printf("Enter ending odometer reading: ");
    scanf("%lf", &last_odometer);
    double mileage = last_odometer - first_odometer;
    double reimbursement = mileage * 0.655;
    printf("You traveled %.2lf miles. At $0.655 per mile, your reimbursement $%.2lf.\n", mileage, reimbursement);

    //Coding Problem 2
    double fahrenheit;
    printf("Enter temperature Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    double celsius = (fahrenheit - 32) * (5.0/9.0);
    printf("%.2lf degrees Fahrenheit is %.2lf degrees Celcius.", fahrenheit, celsius);

    return 0;
}

/*Output

Enter beginning odometer reading: 0
Enter ending odometer reading: 0
You traveled 0.00 miles. At $0.655 per mile, your reimbursement $0.00.
Enter temperature Farenheit: 212
212.00 degrees Farenheit is 100.00 degrees Celcius.

Enter beginning odometer reading: 100
Enter ending odometer reading: 200
You traveled 100.00 miles. At $0.655 per mile, your reimbursement $65.50.
Enter temperature Farenheit: 32

Enter beginning odometer reading: 1
Enter ending odometer reading: 430
You traveled 429.00 miles. At $0.655 per mile, your reimbursement $281.00.
Enter temperature Farenheit: -459.67
-459.67 degrees Farenheit is -273.15 degrees Celcius.

Enter beginning odometer reading: 1234 
Enter ending odometer reading: 6000
You traveled 4766.00 miles. At $0.655 per mile, your reimbursement $3121.73.
Enter temperature Farenheit: 10000
10000.00 degrees Farenheit is 5537.78 degrees Celcius.

*/
