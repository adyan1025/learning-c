#include <stdio.h>

//Preprocessors for Problem 1
int nineDivisible(int n);
int expressRightDigit(int n);
int removeRightDigit(int n);

//Preprocessors for Problem 2
double repetition(int iterations);

int main() {
    //Problem 1
    int n;
    printf("IS IT DIVISIBLE BY 9");
    printf("\nEnter an integer: ");
    scanf("%d", &n);
    int original = n;
    int result = nineDivisible(n);
    if (result == 1) {
        printf("%d is divisible by 9.", original);
    }
    else {
        printf("%d is NOT divisible by 9.", original);
    }

    //Problem 2
    int iterations;
    printf("\nESTIMATE PI");
    printf("\nEnter number of iterations: ");
    scanf("%d", &iterations);
    double PI = repetition(iterations);
    printf("Estimated PI is %lf", PI);

    return 0;
}

//Functions for Problem 1
int nineDivisible(int n) {
    int digitsSum = 0;
    int digit;
    do {
        digit = expressRightDigit(n);
        digitsSum = digit + digitsSum;
        n = removeRightDigit(n);
    } while (expressRightDigit(n) != 0);

    if (digitsSum % 9 == 0) {
        return 1;
    }
    return 0;
}
int expressRightDigit(int n) {
    return n % 10;
}
int removeRightDigit(int n) {
    return n / 10;
}

//Functions for Problem 2
double repetition(int iterations) {
    double fraction = 0.0;
    double negative = -1.0;
    double double_iteration = (double) iterations;
    for (int i = 1; i <= double_iteration; i+=2) {
        negative = -1.0 * negative;
        fraction = (1.0 / (i * negative)) + fraction;
    }
    double PI = 4.0 * fraction;
    return PI;
}

/* 
PI Accuracy
99 Iterations: Accurate up to 2 digits
999 Iterations: Accurate up to 2 digits
9999 Iterations: Accurate up to 4 digits
*/