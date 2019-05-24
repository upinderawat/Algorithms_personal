#include<bits/stdc++.h>
using namespace std;

int main(){
   int N, K;
   int i=0,j;
   int result=0;
   cin >> N >> K;
   int C[N];
   for(i = 0; i < N; i++){
      cin >> C[i];
   }
   sort(C,C+N,greater<int >());
   
   i=0;
   for(j=0;j < ceil(N/(float)K) ;j++){
	   while((i < K*(j+1)) and (i < N)){
		   result += (j+1)*C[i];
           i++;
       }
   }
   cout << result << "\n";
   
   return 0;
}
