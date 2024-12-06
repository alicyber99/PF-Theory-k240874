#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *title;
    float rating;
    int runtime;
    char *encodingFormat;
} ContentMetadata;
typedef struct {
    int *engagementScores;
} UserProfile;
int main() {
    int userCount = 100; 
    int categoryCount = 3;
    int deviceCount = 3; 
    double **engagementMatrix = malloc(userCount * sizeof(double *));
    for (int i = 0; i < userCount; i++) {
        engagementMatrix[i] = malloc(categoryCount * sizeof(double));
    }
    int **deviceMatrix = malloc(userCount * sizeof(int *));
    for (int i = 0; i < userCount; i++) {
        deviceMatrix[i] = malloc(deviceCount * sizeof(int));
    }
    ContentMetadata ***contentMatrix = malloc(categoryCount * sizeof(ContentMetadata **));
    for (int i = 0; i < categoryCount; i++) {
        contentMatrix[i] = malloc(10 * sizeof(ContentMetadata *)); // Example: 10 contents per category
        for (int j = 0; j < 10; j++) {
            contentMatrix[i][j] = malloc(sizeof(ContentMetadata));
            contentMatrix[i][j]->title = "Example Title";
            contentMatrix[i][j]->rating = 4.5;
            contentMatrix[i][j]->runtime = 120;
            contentMatrix[i][j]->encodingFormat = "H.264";
        }
    }
    for (int i = 0; i < userCount; i++) {
        free(engagementMatrix[i]);
        free(deviceMatrix[i]);
    }
    free(engagementMatrix);
    free(deviceMatrix);
    for (int i = 0; i < categoryCount; i++) {
        for (int j = 0; j < 10; j++) {
            free(contentMatrix[i][j]);
        }
        free(contentMatrix[i]);
    }
    free(contentMatrix);
    return 0;
}
