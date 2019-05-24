//Greedy Algorithm
//for already sorted finish time
//takes O(n)
#include <iostream>
using namespace std;

int main() {
    int T;//Test cases
    int N;//number of activities
    int S[100];//starting and finishing time of activities
    int F[100];
    cin>>T;
	int i,j;
        int work;
        
    while(T--)
    {
	cin>>N;
        for(i=0;i<N;i++)
        cin>>S[i];
        for(i=0;i<N;i++)
        cin>>F[i];
        //end of input stuff
        
		work=1;
		i=0;  //first activity always get selected
        cout<<i<<"\t";
            for(j=1;j<N;j++)//logic 
            {
                if(S[j]>=F[i])
               { work++;
                 cout<<j<<"\t";
                 i=j;
               }   
            }//end of for loop
    }
    cout<<"\nToal activities: "<<work;
        
    }//end of main

