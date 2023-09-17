//Quiz Game Program 9/17/2023

#include <stdio.h>
#include <string.h>

//Question function pertaining to string responses
int strQuestion(char res[], char ans[], char ans2[]) 
{
    fgets(res, 50, stdin);
    res[strlen(res) - 1] = '\0';
    int i = 0;
    while (strcmp(res, ans) != 0 && strcmp(res, ans2) != 0) {
        printf("Sorry! %s is not the right answer... Try Again!\n", res);
        i = i + 1;
        fgets(res, 50, stdin);
        res[strlen(res) - 1] = '\0';
    }

    printf("%s is right!\n", res);
    return i;
}

int main() 
{
    int wrongCounter = 0;

    //Introduction
    printf("\nWelcome to the game show! Let's get started.\n");

    //Question 1
    printf("\nQUESTION 1/5: What does the 'www' mean in a url?\n");
    char response1[50];
    char answer1[] = "World Wide Web";
    wrongCounter = wrongCounter + strQuestion(response1, answer1, answer1);
    

    //Question 2
    printf("\nQUESTION 2/5: How many countries are there in the world?\n");
    char response2[50];
    char answer2[] = "195";
    wrongCounter = wrongCounter + strQuestion(response2, answer2, answer2);
    
    //Question 3
    printf("\nQUESTION 3/5: Who wrote Hamlet?\n");
    char response3[50];
    char answer3[] = "William Shakespeare";
    char answer3A[] = "Shakespeare";
    wrongCounter = wrongCounter + strQuestion(response3, answer3, answer3A);

    //Question 4
    printf("\nQUESTION 4/5: What is the largest land animal?\n");
    char response4[50];
    char answer4[] = "Elephant";
    wrongCounter = wrongCounter +  strQuestion(response4, answer4, answer4);

    //Question 5
    printf("\nQUESTION 5/5: Who made this quiz?\n");
    char response5[50];
    char answer5[] = "Adyan";
    wrongCounter = wrongCounter + strQuestion(response5, answer5, answer5);

    //Completion
    printf("\nCongrats! You got %d questions wrong.", wrongCounter);

    return 0;
}