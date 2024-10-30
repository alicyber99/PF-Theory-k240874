#include <stdio.h>

int my_strlen(char str[]) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}
int main() {
    int n;
    printf("Enter the number of words: ");
    scanf("%d", &n);
    char str[n][50];
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the word without spaces[%d]: ", i);
        scanf("%s", str[i]);
    }
    for (i = 0; i < n; i++) {
        int m = my_strlen(str[i]);
        for (int j = 0; j < m; j++) {
            if(j==0) printf("{");
            printf("'%c': 1,", str[i][j]);
        }
        printf("}\n");
    }

    return 0;
}
