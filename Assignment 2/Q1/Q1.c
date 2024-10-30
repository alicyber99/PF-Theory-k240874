#include<stdio.h>
#include<limits.h>

int main(){
    int min = INT_MAX; 
    int smin = INT_MAX;
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Element-%d: ",i);
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < 5; i++){
        if (min > arr[i]){ 
            smin = min;
            min = arr[i];
        }else if (min < arr[i] && smin > arr[i])
        {
            smin = arr[i];
        }
              
    }
    if (smin == INT_MAX){
        printf(" No second smallest element exist\n");
    }else
        printf("The second smallest element in the array : %d",smin);    
    return 0;
}
