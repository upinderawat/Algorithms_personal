/*Power of m^n in theta(logn) using D&C */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long power(long m,long n){
	long b;
	long c;
	if(n == 0){
		return 1;
	}
	if(n == 1)
		return m;
	else{
		if(n %2 == 0){
			b = power(m,n/2);
			c = b*b;
		}
		else{
			b = m*power(m,n-1);
			c = b;
		}
		return c;
	}
}
void main(){
	int m,n;
	scanf("%d",&m);
	scanf("%d",&n);
	printf("%ld\n",power(m,n));
	
}
