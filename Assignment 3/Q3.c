#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void validateEmail(char *email){
    int i, symbol = 0, dotCount = 0;
    int length = strlen(email);
    for (int i = 0; i < length; i++){
        if(email[i] == '@'){
            symbol = 1;
            if(symbol > 1) break;
        }
        if(email[i] == '.'){
            dotCount++;
            if(dotCount > 1) break;
        }
        if(email[i] == ' ' || email[i] == '-' || email[i] == '_'){
            printf("Invalid Email");
            free(email);
            return;
        }
    }
    int flag = 1;
    if(symbol == 1 && dotCount == 1){
    for (int i = 0; i < length; i++){
        if(email[i] == '@'){
            for(int j = i+1; i < length; j++){
                if(email[j] == '.'){
                   printf("Valid email");
                   break;
                }   
            }
        }
    }
    if(!flag) printf("Valid Email");
    else printf("Invalid Email");
    }else printf("Invalid Email");
    return;
}
int main(){
    char *email;
    email = (char*)malloc(100 * sizeof(char));
    printf("Enter your email: ");
    scanf("%s", email);
    if (email == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    validateEmail(email);
    free(email);
    return 0;
}