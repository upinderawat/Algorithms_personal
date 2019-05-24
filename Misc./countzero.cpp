//logic for small factorail values
#include <iostream>
using namespace std;
int factorial(int num);

int main() {
    int T,num=0,fact;
    int count;
    cin>>T;
    while(T--)
    {
	count=0;
            cin>>num;
            fact=factorial(num);
            
            while(fact%10==0)
            {
                count++;
                fact=fact/10;
            }
            cout<<"\n"<<count;
    }
    
	//code
	return 0;
}
int factorial(int num)
{
    int i,fact=1;
    for(i=num;i>0;i--)
    {
        fact=fact*i;
    }
return fact;
}
