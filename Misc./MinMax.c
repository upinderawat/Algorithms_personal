/*MaxMin using Tournament Method(D&C). (3/2)n - 2 comparisons in WC if
 * problem is exactly divisible by 2*/

#include <stdio.h>
#include <stdlib.h>
typedef struct pair{
	int min;
	int max;
}pair;
pair MinMax(int A[],int i,int j){			//A[i....j]
	pair mypair;
	pair mpl,mpr;	
	int mid;
	if(i == j)			//base case
		mypair.min = mypair.max = A[i];
	else if(i - j == 1){	//size of 2
		if(A[i] <= A[j]){
			mypair.min = A[i];
			mypair.max = A[j];
		}
		else {
				mypair.min = A[j];
				mypair.max = A[i];
			}
		}
	else{
		mid = (i+j)/2;
		mpl = MinMax(A,i,mid);
		mpr = MinMax(A,mid+1,j);
		if(mpl.min < mpr.min)
			mypair.min = mpl.min;
		else mypair.min = mpr.min;
		if(mpl.max < mpr.max)
			mypair.max = mpr.max;
			else mypair.max = mpl.max;
		}
		return mypair;
}
	
		



int main(){
	int A[]={12,23,4,233,44,87,34};
	pair mypair;
	mypair = MinMax(A,0,6);
	printf("Min: %d\n",mypair.min);
	printf("Max: %d\n",mypair.max);
	
	return 0;
}
