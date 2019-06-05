 #include<stdio.h>
 #define PI 3.14159
 
 int main(void){
	
	double r;
	
	scanf("%lf", &r);
	printf("Area = %.4lf\n", (PI*(r*r))/10000.0);
	
	return 0;
 }
