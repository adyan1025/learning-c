/*
1) Data Structure are a group of related data items stored under the same name.

2) No, arrays only store values of the same type. For example int nums[] can only store
integers and not anything else, such as characters.

3) The first prototype may or may not alter the contents of array b, such as by adding or
changing a value in the array. The second prototype cannot alter the array b because of
'const.' This means that perhaps the function will only read the array, but won't make any
changes to it.

4) The following loop works by incrementing 'i' from 0 to 12 and complete what is in the body.
The loop reads in an input from the user and then puts that input into the array at the position
number of the number of loops.

5)  a) 8 elements
    b) m[i][j] (i references the row and j references the column)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int reviewQuestions(char *path_to_inputfile);
void writeReport(int number_of_questions, char *answer_key, int *id, char *answers, float *score, int number_of_students);
float calculateScore(float number_of_questions, float correct_answer);

int main() {
    char path_to_inputfile[] = "examdata.txt";
    reviewQuestions(path_to_inputfile);


    return 0;
}

int reviewQuestions(char *path_to_inputfile) {
    FILE* ptr;
    char ch[50];
    char answer_key[50];
    int current_id, number_of_questions;
    int id[1000];
    int id_counter = 0;
    int starting_flag = 0;
    int correct_answer;
    float score[100];
    int id_student_flag = 0;
 
    ptr = fopen(path_to_inputfile, "r");
 
    if (NULL == ptr) {
        printf("ERROR: File can't be opened.\n");
    }

    while (fscanf(ptr, "%d %s", &current_id, ch) == 2) {
        id_student_flag = 1;
        correct_answer = 0;

        if (starting_flag == 0) {
            number_of_questions = current_id;
            if (number_of_questions != strlen(ch)) {
                printf("ERROR: Number of questions provided doesn't match the number of answers in the answer key.");
                return -1;
            }
            strcpy(answer_key, ch);
            starting_flag = 1;
            continue;
        }
        else {
            if (number_of_questions != strlen(ch)) {
                printf("ERROR: Number of questions provided doesn't match the actual number of questions.");
                return -1;
            }
            id[id_counter] = current_id;
            for (int i = 0; i < strlen(answer_key); i++) {
                if (answer_key[i] == ch[i]) {
                    correct_answer++;
                }
            }
            
            score[id_counter] = calculateScore((float)number_of_questions, (float)correct_answer);
            id_counter++;
        }
    }

    if (id_student_flag == 0) {
        printf("ERROR: Empty file.");
        return -1;
    }
    else {
        writeReport(number_of_questions, answer_key, id, ch, score, id_counter);
        fclose(ptr);
        printf("Success!");
    }
}

float calculateScore(float number_of_questions, float correct_answer) {
    float score = (correct_answer/number_of_questions) * 100.0;
    return score;
}

void writeReport(int number_of_questions, char *answer_key, int *id, char *answers, float *score, int number_of_students) {
    FILE *pF = fopen("report.txt", "w");
    fprintf(pF, "\tExam Report\n\nQuestion   ");
    for (int i = 0; i < number_of_questions; i++) {
        fprintf(pF, "%d ", i+1);
    }
    fprintf(pF, "\nAnswer     ");
    for (int j = 0; j < number_of_questions; j++) {
        fprintf(pF, "%c ", answer_key[j]);
    }
    fprintf(pF, "\n\nID\t\tScore");
    for (int k = 0; k < number_of_students; k++) {
        fprintf(pF, "\n%d\t\t%.f", id[k], score[k]);
    }
    fclose(pF);
}
