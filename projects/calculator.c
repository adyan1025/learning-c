//Simple Calculator Program 9/10/2023

#include <stdio.h>

int main() {
    char op;
    int x;
    int y;
    int result;
    
    printf("Choose the operator:\n");
    scanf("%c", &op);
    
    if (op == '+') {
        printf("Choose the first number:\n");
        scanf("%d", &x);
    
        printf("Choose the second number: \n");
        scanf("%d", &y);

        result = x + y;
        printf("%d", result);
    }
    else if (op == '-') {
        printf("Choose the first number:\n");
        scanf("%d", &x);
        
        printf("Choose the second number: \n");
        scanf("%d", &y);

        result = x - y;
        printf("%d", result);
    }
    else if (op == '*') {
        printf("Choose the first number:\n");
        scanf("%d", &x);
        
        printf("Choose the second number: \n");
        scanf("%d", &y);

        result = x * y;
        printf("%d", result);
    }
    else if (op == '/') {
        printf("Choose the first number:\n");
        scanf("%d", &x);
        
        printf("Choose the second number: \n");
        scanf("%d", &y);

        result = x/y;
        printf("%d", result);
    }
    else {
        printf("Please choose a valid operation.");
    }
    
    return 0;
}
