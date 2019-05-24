#include <bits/stdc++.h>
using namespace std;
#define parent(i) i/2
#define left(i) 2*i
#define right(i) 2*i+1

long* A;
long maxHeapSize;

void swap(long *a,long *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}


void heapify(int i){//top down proces
	int smallest;
	if(left(i)<=maxHeapSize && A[left(i)]<A[i])
		smallest = left(i);
	else smallest = i;
	if(right(i)<=maxHeapSize && A[right(i)]<A[smallest])
		smallest = right(i);
	if(smallest!=i){
		swap(&A[smallest],&A[i]);
		heapify(smallest);
	}
}
void buildMinHeap(){//bottom up 
	for(int i=parent(maxHeapSize);i>=1;i--)
		heapify(i);
}
void insertHeap(long num){
	maxHeapSize++;
	A[maxHeapSize]=num;
	int i= maxHeapSize;
	while(parent(i)>=1 && A[i]<A[parent(i)]){
		swap(&A[i],&A[parent(i)]);
		i = parent(i);
	}
}
int ans(int K){
	long oprct=0;//operation count
	long sum = 0;
	long least;
	long least2;//2nd least element
	while(A[1]<K && maxHeapSize>1){

		sum=0;
		
		least = A[1];
		swap(&A[1],&A[maxHeapSize]);
		maxHeapSize--;
		heapify(1);
		least2 = A[1];
		swap(&A[1],&A[maxHeapSize]);
		maxHeapSize--;
		heapify(1);
		sum = least+2*least2;
		insertHeap(sum);
		oprct++;
	}
	if(A[1]>=K)
		return oprct;
	else return -1;
}
int main(){
	long K;
	cin>>maxHeapSize>>K;
	A = new long[maxHeapSize+1];
	for(int i=1;i<=maxHeapSize;i++){
		cin>>A[i];
	}
	buildMinHeap();
	cout<<ans(K)<<"\n";

	return 0;
}