#include <stdio.h>
#include <string.h>

#define NAME_SIZE 30
#define GRADE_SIZE 20
#define CLASS_SIZE 30

typedef struct Students{
    char name[NAME_SIZE];
    int score; 
    char grade[GRADE_SIZE];
} student_t;


void grades(student_t *student, float average);
void printTable(student_t student);


int main() {
    student_t student[CLASS_SIZE];
    int class;
    int sum = 0;
    float average;

    printf("How many students will you enter? (Must be less than %d)", CLASS_SIZE);
    scanf("%d", &class);
    if (class > CLASS_SIZE) {
        printf("Class size must be less than %d.\n", CLASS_SIZE);
        main();
    }
    printf("\n");

    for (int i = 0; i < class; i++) {
        printf("What is the student's name?(%d) ", i+1);
        scanf("%s", &student[i].name);
        printf("\n");
        printf("What is the student's score?(%d) ", i+1);
        scanf("%d", &student[i].score);
        printf("\n");
        sum += student[i].score;
    }
    average = (float) sum /class;

    for (int i = 0; i < class; i++) {
        grades(&student[i], average);
        printTable(student[i]);
    }

    return 0;
}

void grades(student_t *student, float average) {
    if (student->score > (10 + average)) {
        strcpy(student->grade, "OUTSTANDING");
    }
    else if (student->score < (10 + average)) {
        strcpy(student->grade, "UNSATISFACTORY");
    }
    else {
        strcpy(student->grade, "SATISFACTORY");
    }
}

void printTable(student_t student) {
    printf("%s\t", student.name);
    printf("%d\t", student.score);
    printf("%s", student.grade);
    printf("\n");
}