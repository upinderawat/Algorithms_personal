//recurrsive 01 knapsack without DP 
#include <stdio.h>
int max(int a,int b)
{
 return (a > b) ? a : b;
}
int ks01(int price[],int wt[],int C,int items){
	if(C == 0 || items == 0)
		return 0;
	if(wt[items-1] <= C){
		return max(ks01(price,wt,C-wt[items-1],items-1)+ price[items-1],ks01(price,wt,C,items-1));
	}
	else if(wt[items-1] > C)
		return ks01(price,wt,C,items-1);
}




int main(){

	int C= 50;
	int price[] = {10,20,30};
	int wt[] = {30,10,20};
	printf("%d",ks01(price,wt,C,3));
	return 0;
}