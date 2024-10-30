#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define rows 6
#define cols 5
void populateArray(char arr[rows][cols], int studentID) {
    srand(time(0));
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 'A' + (rand() % 26);
        }
    }
    for (int j = cols - 1; j >= 0; j--) {
        if (j >= cols - 4) {
            arr[rows - 1][j] = '0' + (studentID % 10);
            studentID /= 10;
        } else {
            arr[rows - 1][j] = 'A' + (rand() % 26); 
        }
    }
}
void printArray(char arr[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}
int searchString(char arr[rows][cols], const char *str) {
    int len = strlen(str);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= cols - len; j++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (arr[i][j + k] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1;
        }
    }
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i <= rows - len; i++) {
            int found = 1;
            for (int k = 0; k < len; k++) {
                if (arr[i + k][j] != str[k]) {
                    found = 0;
                    break;
                }
            }
            if (found) return 1;
        }
    }
    return 0;
}
int main() {
    int studentID;
    printf("Enter the last four digits of your student ID: ");
    scanf("%d", &studentID);
    char arr[rows][cols];
    char input[100];
    int score = 0;
    srand(time(NULL));
    while (1) {
        populateArray(arr,studentID);
        printArray(arr);
        printf("Enter string to search (or 'END' to exit): ");
        scanf("%s", input);
        if (strcmp(input, "END") == 0) {
            break;
        }
        if (searchString(arr, input)) {
            score++;
            printf("%s is present Score %d\n", input, score);
        } else {
            score--;
            printf("%s is not present Score %d\n", input, score);
        }
    }
    return 0;
}
