#include <stdio.h>

void swap(int *a,int *b){
	int t;
	t = *b;
	*b = *a;
	*a = t;
	}


int Partition(int A[],int i,int j){	//sorts element of size 2 and 3.
	int pivot = A[i];	//first element is chosen as pivot
	int L = i,R;
	for(R=i+1; R <= j ;R++){
		if(A[R] < pivot){
			L++;
			swap(&A[L],&A[R]);
		}
	}
	swap(&A[L],&A[i]);
	return (L);
}
void quicksort(int A[],int i,int j){
	int m;
	if(i<j){
		m = Partition(A,i,j);
		quicksort(A,i,m-1);
		quicksort(A,m+1,j);
	}
}


int main(){
	int i,n;
	int A[1000000];
	printf("Input number:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	quicksort(A,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	
	
	return 0;
}
