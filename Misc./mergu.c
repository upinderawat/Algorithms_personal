#include <stdio.h>
void merge(int A[],int p,int mid,int r){
	int i,j,k;
	int B[r-p+1];
	i = k = p;
	j = mid+1;
	while( i <= mid && j <= r){
		if(A[i] <= A[j])	B[k++] = A[i++];	// '<=' in left sublist => stable sorting
		else B[k++] = A[j++];
	}
	while(i <= mid)
		B[k++] = A[i++];
	while(j <= r)
		B[k++] = A[j++];
	for(i = p ;i <= r;i++)
		A[i] = B[i];	//cp back to A
}
void mergesort(int A[],int p, int r){	//A[p...r]
	int mid;
	if(p < r){
		mid = p + (r - p)/2;
		mergesort(A,p,mid);	//A[p ... mid]
		mergesort(A,mid+1,r);	//A[mid+1...r]
		merge(A,p,mid,r);	//A[p...mid...r]
	}
}

int main(){
	int i;
	int A[] = {12,23,43,32,64,88,55,31};
	mergesort(A,0,7);
	for(i = 0;i<8; i++)
		printf("%d ",A[i]);
	return 0;
}
