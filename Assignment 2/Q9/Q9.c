#include <stdio.h>

#define SIZE 5

void displayGrid(char grid[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("|'%c' ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };
    int playerX = 4, playerY = 4;
    char move;
    int count = 0;
    printf("\nWelcome to the Maze Game!\n");
    while (1) {
        displayGrid(grid);
        printf("1.Press W : up\t\t");
        printf("2.Press S : down\t\t");
        printf("3.Press A : left\n");
        printf("4.Press D : right\t");
        printf("5.Press Q : Quit the game\n");
        printf("Enter your move : ");
        scanf(" %c", &move);
        if (move == 'Q' || move == 'q') {
            break;
        }
        int newX = playerX, newY = playerY;
        switch (move) {
            case 'W': case 'w': newX--; break;
            case 'S': case 's': newX++; break;
            case 'A': case 'a': newY--; break;
            case 'D': case 'd': newY++; break;
            default:
                printf("Invalid move! Please try again.\n");
                continue;
        }
        if (newX >= 0 && newX < SIZE && newY >= 0 && newY < SIZE) {
            if (grid[newX][newY] != 'X') {
                if (grid[newX][newY] == 'I') {
                    printf("Item collected!\n");
                    count++;
                }
                grid[playerX][playerY] = ' ';
                playerX = newX;
                playerY = newY;
                grid[playerX][playerY] = 'P';
            } else {
                printf("You cannot move into an obstacle!\n");
            }
        } else {
            printf("Move out of bounds! Please try again.\n");
        }
    }
    printf("Item collects is : %d",count);
    return 0;
}
