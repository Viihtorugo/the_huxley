 #include<stdio.h>
 
 int main(void){
 
 int i=0, j;
 char palavra[255], c;
 gets(palavra);
 
 while(palavra[i]!='\0'){
 i++;
 }
 
 for(j=i-1; j>=0; j--){
 printf("%c", palavra[j]);
 }
 printf("\n");
 
 return 0;
 }

