//fibanacci of n in log(n) time complexity
#include <iostream>
using namespace std;
void multiply(int F[2][2],int M[2][2]){
	int x= F[0][0]*M[0][0] + F[0][1]*M[1][0];
	int y= F[0][0]*M[0][1] + F[0][1]*M[1][1];
	int w= F[1][0]*M[0][0] + F[1][1]*M[1][0];
	int z= F[1][0]*M[0][1] + F[1][1]*M[1][1];
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = w;
	F[1][1] = z;
}
void pow(int F[2][2],int m){
	if(m == 0 || m == 1)
		return ;
	int M[2][2]= {{1,1},{1,0}};
	
		if(m%2 == 0){
			pow(F,m/2);
			multiply(F,F);
		}
		else{
			pow(F,m-1);
			multiply(F,M);
		}
}




int main(){
	int n;
	int F[2][2] = {{1,1},{1,0}};
	cin>>n;	//fn is 0,0 of F^n-1
	pow(F,n-1);
	cout<<F[0][0];
	return 0;
}