#include <stdio.h>
void Merge(int A[],int m , int B[],int n,int C[]){	//merges two sorted subArray A[0..m-1] B[0...n-1] to C[0..m+n-1]
	int i,j,k;	//indexes for A,B,C
	for(i=0,j=0,k=0;k< m+n ;k++ ){
		if(i < m && j < n){
			if(A[i]< B[j]){
				C[k] = A[i];
				i++;
			}
			else if(A[i] > B[j]){
				C[k] = B[j];
				j++;
			}
			else if(A[i] == B[j]){
				C[k] = A[i];
				C[k+1] = B[j];
				k++;
				i++;
				j++;
			}
		}
		else{
			if(i >= m){
				C[k] = B[j];
				j++;
			}
			else {
				C[k] = A[i];
				i++;
			}
		}
	}
}

void MergeSort(int A[],int i,int j,int B[]){//	A[i...j]
	int mid;
	int L[1000];
	int R[1000];
	if(i == j)
		B[0] = A[i];
	else{
		mid = (i+j)/2;
		MergeSort(A,i,mid,L);
		MergeSort(A,mid+1,j,R);
		Merge(L,mid - i + 1,R,j-mid,B);
	}
	
}
int main(){
	int i;
//	int A[]={12,23,34,45,56};
	//int B[] = {21,32,43,54,65,98};
	//int C[100]={0};
	//Merge(A,B,C,5,6);
	int A[] ={12,23,34,45,56,6,7,54,3};
	int B[1000];
	MergeSort(A,0,8,B);
	for(i=0 ;i<9;i++)
		printf("%d ",B[i]);
		
	return 0;
}
