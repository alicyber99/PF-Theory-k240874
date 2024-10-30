#include<stdio.h>

int match(int x){
    if(x % 5) return -1;
    else return x % 5;
}

int main(){
   int x;
   printf("Enter the number of sticks: ");
   scanf("%d",&x);
   int result = match(x);
   if(result == -1) printf("Return -1");
   else printf("you should pick %d matchsticks.",result);
   return 0;
}
