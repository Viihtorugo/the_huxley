 #include<stdio.h>

 main()
 {

 int i, n, figurinhas, aux=0;
 int impares=0, pares=0, somaS2=0, somaS3=0;

 scanf("%d", &figurinhas);
 
 int series[figurinhas];
 
 for(i=0; i<figurinhas; i++){
 
 scanf("%d", &series[i]);
 
 if(series[i]%2==0){
 pares += 1;
 somaS2+=series[i];
 }else{
 impares += 1;
 somaS3+=series[i];
 }
 
 }
 
 for(i=0; i<figurinhas; i++){
 if(series[i]%2==0){
 for(n=1+i; n<figurinhas; n++){
 if(series[i]==series[n]){
 somaS2-=series[i];
 n=figurinhas;
 }
 }
 }else{
 for(n=1+i; n<figurinhas; n++){
 if(series[i]==series[n]){
 somaS3-=series[i];
 n=figurinhas;
 }
 }
 }
 }
 
 
 printf("%d\n%d\n", pares, impares);

 if(somaS2>somaS3){
 printf("%d\n", somaS2);
 }else{
 printf("%d\n", somaS3);
 }
 
 system("pause");

 }

