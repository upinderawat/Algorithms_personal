//Knapsack01 using DP
#include<iostream>
using namespace std;

int memo[3]={0};
int MAX(int a,int b)
{
 return (a > b) ? a : b;
}
int knapsack(int W,int wt[],int val[],int n)// returns the max value of the knapsack contraint to W. 
{
	//BASE CASE
	if(n==0 || W==0)
	return 0;
	
	if(wt[n-1]<=W)
	{
		memo[n-1] = MAX(val[n-1]+knapsack(W-wt[n-1],wt,val,n-1),knapsack(W,wt,val,n-1));
	}
	else//if wt[n-1]> W then ignore it
	memo[n-1] = knapsack(W,wt,val,n-1);

	return memo[n-1];
}
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(W, wt, val, n);
    return 0;
}
