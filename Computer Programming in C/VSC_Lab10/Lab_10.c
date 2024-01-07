/*
1)  double ar1[30];
    char ar2[30];
    int ar3[20];
    for (int i = 0; i < 20; i++) {
        scanf("%d", &ar3[i]);  
    }
    for (int j = 0; j < 30; j++) {
        scanf("%lf", &ar1[j]);
        scanf(" %c", &ar2[j])
    }

2)  a) add_arrays(ar1, ar2, c, 6);
       Invalid because ar1 and ar2 were never defined as anything. 

    b) add_arrays(c[6], d[6], e[6], 6);
       Invalid because the the values of an indexed array is passed and not the array itself. 

    c) add_arrays(c, d, e, 6);
       Valid, Adds the elements of c and d and stores the sum into array e. 

    d) add_arrays(c, d, e, 7);
       Valid, Adds the elements of c and d and stores the sum into array e. 

    e) add_arrays(c, d, e, 3);
       Valid, Adds the elements of c and d and stores the sum into array e. 

    f) add_arrays(e, d, c, 6);
       Valid, Adds the elements of c and d and stores the sum into array e. 

    g) add_arrays(c, c, c, 6);
       Valid, Adds the elements of c and d and stores the sum into array e. 

    h) add_arrays(c, d, 6, 3);
       Valid, Adds the elements of c and d and stores the sum into array e.

    i) add_arrays(c, d, e, 7);
       Valid, Adds the elements of c and d and stores the sum into array e.

    j) add_arrays(c, d, e, c[1]); i) if c[1] = 4.3; and ii) if c[1] = 91.7?
       Both are invalid because both are floats when the array asked for an integer. 
*/

#include <stdio.h>
#include <stdlib.h>

void get_poly(int degree, const int coefficient[][2]);
double eval_poly(int degree, const int coefficient[][2], double x);

int main() {
    int degree;
    double x;

    printf("\n\tPOLYNOMIAL PROGRAM\n");
    printf("\nEnter the polynomial degree: ");
    scanf("%d", &degree);

    int coefficient[degree+1][2];

    for (int i = 0; i <= degree; i++) {
        printf("\nEnter a coefficient (a[%d]): ", i);
        scanf("%d", &coefficient[i][0]);
        coefficient[i][1] = degree - i;
    }

    get_poly(degree, coefficient);

    while (1) {
        printf("\n\n_____________________");
        printf("\n\nEnter x (0 to stop): ");
        scanf("%lf", &x);
        if (x == 0) {
            printf("\n\n\tEND OF PROGRAM\n\n");
            return 0;
        }
        double result = eval_poly(degree, coefficient, x);
        printf("\np(%.1lf) = %.1lf", x, result);
    }
    
}

void get_poly(int degree, const int coefficient[][2]) {
    int flag = 0;

    printf("\n\nThe Polynomial Function");
    printf("\n\np(x)= ");

    for (int i = 0; i <= degree; i++) {
        if (coefficient[i][0] != 0) {
            if (flag == 0) {
                flag = 1;
                if (coefficient[i][0] == 0) {}
                else if (coefficient[i][1] == 0) {
                    printf("%d", coefficient[i][0]);
                }
                else if (coefficient[i][0] == 1) {
                    if (coefficient[i][1] == 1) {
                        printf("x");
                    }
                    else {
                        printf("x^%d", coefficient[i][1]);
                    }
                }
                else if (coefficient[i][1] == 1) {
                    printf("%dx", coefficient[i][0]);
                }
                else {
                    printf("%dx^%d", coefficient[i][0], coefficient[i][1]);
                }
            }
            else if (coefficient[i][0] > 0) {
                printf(" + ");
                if (coefficient[i][1] == 0) {
                    printf("%d", coefficient[i][0]);
                }
                else if (coefficient[i][0] == 1) {
                    if (coefficient[i][1] == 1) {
                        printf("x");
                    }
                    else {
                        printf("x^%d", coefficient[i][1]);
                    }
                }
                else if (coefficient[i][1] == 1) {
                    printf("%dx", coefficient[i][0]);
                }
                else {
                    printf("%dx^%d", coefficient[i][0], coefficient[i][1]);
                }
            }
            else if (coefficient[i][0] < 0){
                printf(" - ");
                if (coefficient[i][1] == 0) {
                    printf("%d", -1 * coefficient[i][0]);
                }
                else if (coefficient[i][0] == -1) {
                    if (coefficient[i][1] == 1) {
                        printf("x");
                    }
                    else {
                        printf("x^%d", coefficient[i][1]);
                    }
                }
                else if (coefficient[i][1] == 1) {
                    printf("%dx", -1 * coefficient[i][0]);
                }
                else {
                    printf("%dx^%d", -1 * coefficient[i][0], coefficient[i][1]);
                }
            }
        }
    }
}

double eval_poly(int degree, const int coefficient[][2], double x) {
    //Horner's Rule
    double result;
    result = (double) coefficient[0][0];
    for (int i = 1; i <= degree; i++) {
        result *= x;
        result = coefficient[i][0] + result;
    }
    return result;
}