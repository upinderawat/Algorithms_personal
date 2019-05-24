#include<iostream>
#include<string.h>
using namespace std;
int MAX(int a,int b)
{
	return (a>b) ? a : b;
}

int lcs(char *X,char *Y,int m,int n)
{
	int L[m+1][m+1];
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
		{	if(i==0||j==0)
			{
				L[i][j]=0;//BASE CASE
			}
		else if(X[i-1]==Y[j-1])//if the match occurs
			L[i][j]=1+L[i-1][j-1];
		else
			L[i][j]=MAX(L[i][j-1],L[i-1][j]);			
		}
return L[m][n];
}

int main(){
char X[20];
char Y[20];
int m,n;//X[1..m-1] and Y[1..n-1]

cout<<"Input 1st string\n";
cin>>X;
cout<<"Input 2nd string";
cin>>Y;
m=strlen(X);
n=strlen(Y);
cout<<"Length of LCS:"<<lcs(X,Y,m,n);

return 0;}
