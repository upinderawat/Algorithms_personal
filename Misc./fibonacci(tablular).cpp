/*C++ program to implement fibonacci series upto n using tabulation*/
#include<iostream>
using namespace std;

#define MAX 100
#define NIL -1
int fibonacci(int n)
{
int table[n+1];
table[1]=1;
table[0]=0;
	for(int i=2;i<=n;i++)
	table[i]=table[i-1]+table[i-2];
return table[n];
}


int main(){
int n;
cout<<"Sum of fibonnaci upto n"<<endl;
cin>>n;
cout<<fibonacci(n);
return 0;

}

