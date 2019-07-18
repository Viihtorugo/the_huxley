 #include<stdio.h>
 
 int main(void){
 
 int n, i;
 
 scanf("%d", &n);
 
 int vetor[n];
 
 for(i=0; i<n; i++){
 scanf("%d", &vetor[i]);
 }
 
 for(i = n-1; i>=0; i--){
 if(i==n-1){
 printf("%d", vetor[i]);
 }else{
 if(i!=0){
 printf(" %d", vetor[i]);
 }
 if(i==0){
 printf(" %d\n", vetor[i]);
 }
 }
 }
 
 }
