#include<stdio.h>
#include<limits.h>

int main(){
    int n,m = 0;
    int max = INT_MIN;
    printf("Enter the size of digits : ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Horizontal Histogram\n");
    for (int i = 0; i < n; i++)
    {
        int count = arr[i];
        for (int i = 0; i < count; i++){
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("Vertical Histogram\n\n");
    for (int i = max; i > 0; i--)
    {
        for (int j = 0;j < n; j++)
        {
            if (arr[j] >= i) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}
