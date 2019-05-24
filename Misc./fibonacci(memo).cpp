/*C++ program to implement fibonacci series upto n using memoization*/
#include<iostream>
using namespace std;

#define MAX 100
#define NIL -1
int lookup[MAX];

void initialize(int n)//initialze the loolup memo
{
	for(int i=0;i<n+1;i++)
	lookup[i]=NIL;
}

int fibonacci(int n)
{
	if(lookup[n]==NIL)
	{
		if(n<=1)
		lookup[n]=n;
		else
		lookup[n] = fibonacci(n-1)+fibonacci(n-2);
	}
return lookup[n];
}

int main(){
int n;
cout<<"Sum of fibonnaci upto n"<<endl;
cin>>n;
initialize(n);
cout<<fibonacci(n);
return 0;

}

