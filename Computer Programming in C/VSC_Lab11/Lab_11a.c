/*
1)  The error is the equal <= sign. It should be a < sign because the index starts at zero. The program would
    have had a runtime error.

2)  No because arrays only accept the data type of the one that was used to initialize the array itself.

3)  void reverse(int x[], int y[], int n) {
        for (int i = 0; i < n; i++) {
            y[(n-1) - i] = x[i];
        }
    }

4)  for (int i = 0; i < 10; i++) {
        int sum = 0;
        for (int j = 0; j < 3; j++) {
            sum+=tables[i][j];
        }
        printf("row %d: sum = %d", i+1, sum);
        printf("\n");
    }
*/

#include<stdio.h>

#define MAX_NUM 25

void printArray(int arr[], int arr_size);
void enterArray(int arr[], int arr_size);
int mergeArray(int merge[], int arr_1[], int arr_2[], int arr_size_1, int arr_size_2);
void sort(int arr[], int arr_size);

int main() {
    int array_1[MAX_NUM], array_2[MAX_NUM], merged_array[MAX_NUM * 2];
    int array_size_1, array_size_2;
    int flag = 0;

    do {
        printf("Enter how many numbers to be inputted into array 1: ");
        scanf("%d", &array_size_1);
        if ((array_size_1 <= 25) && (array_size_1 > 0)) {
            printf("\n");
            enterArray(array_1, array_size_1);
            flag = 1;
        }
    } while (flag == 0);
    flag = 0;

    do {
        printf("Enter how many numbers to be inputted into array 2: ");
        scanf("%d", &array_size_2);
        if ((array_size_2 <= 25) && (array_size_2 > 0)) {
            printf("\n");
            enterArray(array_2, array_size_2);
            flag = 1;
        }
    } while (flag == 0);

    printf("Original Array 1: ");
    printArray(array_1, array_size_1);
    printf("\n");
    printf("Original Array 2: ");
    printArray(array_2, array_size_2);
    printf("\n");

    sort(array_1, array_size_1);
    sort(array_2, array_size_2);

    printf("Sorted Array 1: ");
    printArray(array_1, array_size_1);
    printf("\n");
    printf("Sorted Array 2: ");
    printArray(array_2, array_size_2);
    printf("\n");

    int merged_array_size = mergeArray(merged_array, array_1, array_2, array_size_1, array_size_2);
    printf("Merged Array: ");
    printArray(merged_array, merged_array_size);
    printf("\n");
    
    return 0;
}

void printArray(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
}

void enterArray(int arr[], int arr_size) {
    int counter = 0;
    while (counter < arr_size) {
        printf("Enter numbers for first array (%d): ", counter+1);
        scanf("%d", &arr[counter]);
        printf("\n");
        counter++;
    }
}

int mergeArray(int merge[], int arr_1[], int arr_2[], int arr_size_1, int arr_size_2) {
    int merge_size = arr_size_1 + arr_size_2;
    for (int i = 0; i < arr_size_1; i++) {
        merge[i] = arr_1[i];
    }
    for (int i = 0; i < arr_size_2; i++) {
        merge[i + arr_size_1] = arr_2[i];
    }
    sort(merge, merge_size);
    return merge_size;
}

void sort(int arr[], int arr_size) {
    int temp, j;
    
    for (int i = 1; i < arr_size; i++) {          
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}
