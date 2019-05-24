#define NUM_STATION 4
#include<iostream>
#include<string.h>
using namespace std;
int MIN(int a,int b)
{
	return (a<b) ? a : b;
}

int carAssembly(int a[][NUM_STATION],int t[][NUM_STATION],int e[],int x[]){
	int T0[NUM_STATION],T1[NUM_STATION];// T0[j],T1[j] are the min time taken by chasis to leave station 0 and 1
	int i;
	//BASE CASE
	T0[0]=e[0]+a[0][0];
	T1[0]=e[1]+a[1][0];

	for(i=1;i<NUM_STATION;i++)
	{
		T0[i]=MIN((T0[i-1]+a[0][i]),(T1[i-1]+a[0][i]+t[1][i]));// MIN of two cases:when the line is constant or when the line is changed
		T1[i]=MIN((T1[i-1]+a[1][i]),(T0[i-1]+a[1][i]+t[0][i]));		
	}

	return MIN(T0[NUM_STATION-1]+x[0],T1[NUM_STATION-1]+x[1]);
}
int main(){
	int a[2][NUM_STATION] = {{4, 5, 3, 2},// a[i][j] is the process time at station j on line i   
                {2, 10, 1, 4}};
    int t[2][NUM_STATION] = {{0, 7, 4, 5},// t[0][j] is the time cost taken to move from s[0][j-1] to s[1][j] 
                {0, 9, 2, 8}};
    int e[2] = {10, 12}, x[2] = {18, 7};

	cout<<carAssembly(a,t,e,x);
	
return 0;}
