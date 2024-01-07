/* Your #include directives go here */
#include <stdio.h>

 

/* Your # define directives, if any, go here */

#define SENTINEL -1  //input sentinel value; end of input, exit program when entered

/* function prototype */

int ComputeBMI (float HeightInches, float WeightPounds);

void main(){

    float Height, Weight;  //Height in inches, weight in pounds

    printf("Enter height in inches or %d to exit?  ", SENTINEL);

    scanf("%f", &Height);

    while (Height != SENTINEL )

    {    printf("Enter Weight in pounds: ");

         scanf("%f", &Weight );

         ComputeBMI (Height, Weight);

         printf("Enter height in inches or %d to exit?  ", SENTINEL);

         scanf("%f", &Height ); 

         ComputeBMI(Height, Weight);

    } //end while     

} //end main

//your ComputeBMI() function goes here:
int ComputeBMI (float HeightInches, float WeightPounds) {
    float BMI = (703 * WeightPounds) / (HeightInches * HeightInches);
    if (BMI < 18.5) {
        printf("BMI = %.1f Weight Class = Underweight\n", BMI);
    }
    else if ((BMI >= 18.5) && (BMI <= 24.9)) {
        printf("BMI = %.1f Weight Class = Normal\n", BMI);
    }
    else if ((BMI >= 25.0) && (BMI <= 29.9)) {
        printf("BMI = %.1f Weight Class = Overweight\n", BMI);
    }
    else if (BMI >= 30.0) {
        printf("BMI = %.1f Weight Class = Obese\n", BMI);
    }
    return BMI;
}