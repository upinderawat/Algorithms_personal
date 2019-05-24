#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{
   long X;
   int i,j;
   int T;
   long sum;
   long N;
   long *arr=new long(N);
   cin>>T;
   while(T--)
   {
   		cin>>N;
   		cin>>X;
   		for(i=0;i<N;i++)
   		cin>>arr[i];
   		
   		for(i=0;i<N;i++)
   		{
			sum=0;
   			sum += arr[i];
   			for(j=i+1;j<N;j++)
   			{
   				if(sum<=X)
   				{
   					if(sum==X)
   					{
   						cout<<"\nYES";
   						exit(1);
   					}
   					sum+=arr[j];
   				}
   				else if(sum>12)
   				break;
   			}
   		}
		cout<<endl<<"NO";
   }
    return 0;
}

