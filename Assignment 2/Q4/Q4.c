#include <stdio.h>
int main(){
int n;
int point = 0;
int x = 0, y = 0;
printf("Enter the number of words: ");
scanf("%d",&n);
char arr[n][100];
int i,j,k,l,z = 0;
for(i=0;i<n;i++){
	printf("Enter the %d word: ",i+1);
	scanf("%s",arr[i]);
}
for(i=n-1;i>=0;i--){
if(arr[i][0]!=' '){
	x=0;
	while(arr[i][x]!='\0') x++;
	printf("[%s",arr[i]);
	for(j=i-1;j>=0;j--){
		y=0;
	  while(arr[j][y]!='\0') y++;
		for(k=0;arr[i][k]!='\0';k++){
			for(l=0;arr[j][l]!='\0';l++) {
        if(arr[i][k]==arr[j][l]) break;
      }
			if(arr[j][l]=='\0')  break;
		  }    
	      if(arr[i][k]=='\0' && x == y)	{
	            printf(",%s",arr[j]);
		        while(arr[j][z]!='\0'){
            		arr[j][z]=' ';
	            	z++;
				}
				z=0;
            }						             
    	}
            printf("],");
        }
    }
