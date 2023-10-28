#include <stdio.h>

double gradeLetter(double grade);
double gradePoint(int grade_letter);
double qualityPoints(double grade_point, int course_hour);

int main() {
    char restart = 'y';
    while (restart == 'y') {
        int flag = 0;
        int number_of_classes;
        int course_hour;
        double grade;
        double grade_value;
        double quality_point = 0;
        int total_course_hour = 0;
        double gpa;

        printf("GPA CALCULATOR\n\n");
        printf("Enter how many classes taken: ");
        scanf("%d", &number_of_classes);
        
        for (int i = 1; i <= number_of_classes; i++) {
            printf("________________________\n\n");
            if (i == 1) {
                printf("Enter the %dst grade: ", i);
            }
            else if (i == 2) {
                printf("Enter the %dnd grade: ", i);
            }
            else if (i == 3) {
                printf("Enter the %drd grade: ", i);
            }
            else {
                printf("Enter the %dth grade: ", i);
            }
            scanf("%lf", &grade);
            grade_value = gradeLetter(grade);

            printf("Enter the course hour for that class: ");
            scanf("%d", &course_hour);
            total_course_hour += course_hour;
            quality_point += qualityPoints(grade_value, course_hour);
            gpa = quality_point/total_course_hour;
        }
        printf("GPA is %.2lf.\n", gpa);
        while (1) {
            printf("Restart? (y/n): ");
            scanf(" %c", &restart);
            if (restart == 'n') {
                restart = 'n';
                flag = 1;
                break;
            }
            else if (restart == 'y') {
                break;
            }
            else {
                printf("Type y or n next time.\n");
            }
        }
        if (flag == 1) {
            break;
        }
    }
    return 0;
}

double gradeLetter(double grade) {
    int grade_letter;
    if ((grade >= 93) && (grade <= 100)) {
        grade_letter = 12; //A
        gradePoint(grade_letter);
    }
    else if ((grade >= 90) && (grade <= 92)) {
        grade_letter = 11; //A-
        gradePoint(grade_letter);
    }
    else if ((grade >= 87) && (grade <= 89)) {
        grade_letter = 10; //B+
        gradePoint(grade_letter);
    }
    else if ((grade >= 83) && (grade <= 86)) {
        grade_letter = 9; //B
        gradePoint(grade_letter);
    }
    else if ((grade >= 80) && (grade <= 82)) {
        grade_letter = 8; //B-
        gradePoint(grade_letter);
    }
    else if ((grade >= 77) && (grade <= 79)) {
        grade_letter = 7; //C+
        gradePoint(grade_letter);
    }
    else if ((grade >= 73) && (grade <= 76)) {
        grade_letter = 6; //C
        gradePoint(grade_letter);
    }
    else if ((grade >= 70) && (grade <= 72)) {
        grade_letter = 5; //C-
        gradePoint(grade_letter);
    }
    else if ((grade >= 67) && (grade <= 69)) {
        grade_letter = 4; //D+
        gradePoint(grade_letter);
    }
    else if ((grade >= 63) && (grade <= 66)) {
        grade_letter = 3; //D
        gradePoint(grade_letter);
    }
    else if ((grade >= 60) && (grade <= 62)) {
        grade_letter = 2; //D-
        gradePoint(grade_letter);
    }
    else {
        grade_letter = 1; //F
        gradePoint(grade_letter);
    }
}

double gradePoint(int grade_letter) {
    double gp;
    switch (grade_letter)
    {
    case 12:
        gp = 4.00;
        return gp;
        break;
    case 11:
        gp = 3.67;
        return gp;
        break;
    case 10:
        gp = 3.33;
        return gp;
        break;
    case 9:
        gp = 3.00;
        return gp;
        break;
    case 8:
        gp = 2.67;
        return gp;
        break;
    case 7:
        gp = 2.33;
        return gp;
        break;
    case 6:
        gp = 2.00;
        return gp;
        break;
    case 5:
        gp = 1.67;
        return gp;
        break;
    case 4:
        gp = 1.33;
        return gp;
        break;
    case 3:
        gp = 1.00;
        return gp;
        break;
    case 2:
        gp = 0.67;
        return gp;
        break;
    case 1:
        gp = 0.00;
        return gp;
        break;
    default:
        printf("Enter a valid number");
    }
}

double qualityPoints(double grade_point, int course_hour) {
    double quality_points = grade_point * course_hour;
    return quality_points;
}