//if finish time is not sorted
//take O(nlogn)
#include <stdio.h>
#include <stdlib.h>
typedef struct Activitiy{
	int S;
	int F;
}Activitiy;
int cmp(const void *a,const void *b){
	int f1 = (*(Activitiy *)a).F;
	int f2 = ((Activitiy *)b)->F;
	return f1 - f2;
}
void printMaxActivities(Activitiy *arr,int n){
	int i,j;//i denotes prev activity and j for next activity
	qsort(arr,n,sizeof(arr[0]),cmp);
	printf("(%d,%d) ",arr[i].S,arr[i].F);
	for(i=0,j=1;j<n;j++){
		if(arr[j].S >= arr[i].F){
			printf("(%d,%d) ",arr[j].S,arr[j].F);
			i = j;
		}
	}	
}

int main()
{
    Activitiy arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},
                                       {5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxActivities(arr, n);
    return 0;
}