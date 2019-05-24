//discrete Knapsack using Greedy Technique
#include <stdio.h>
#include <stdlib.h>


typedef struct item{
	int wt;
	int val;
	float vwt;//value per weight
}item;

int cmp(const void *a,const void *b){
	float x = (*(item *)a).vwt;
	float y = (*(item *)b).vwt;
	
	return y - x;
}

int main(){
	float profit=0;
	float fracWt;
	item *knapsack;
	int i,C;//capacity of the knapsack left
	int nItems;
	knapsack = (item *)malloc(sizeof(item)*nItems);
	printf("Capacity of Knapsack: ");
	scanf("%d",&C);
	printf("Number of Total items: ");
	scanf("%d",&nItems);
	for(i=0;i<nItems;i++){	//input the values into the items
		printf("%d item: weight value",i+1);
		scanf("%d%d",&knapsack[i].wt,&knapsack[i].val);
		knapsack[i].vwt = knapsack[i].wt/(float)knapsack[i].val;
	}
	qsort(knapsack,nItems,sizeof(item),cmp);
	for(i=0; C != 0 && i < nItems ;i++){	//either capacity limit is reached or items are exhausted
		if(C >= knapsack[i].wt){			//if Capacity is enough then fill completely
			profit += knapsack[i].val;
			C -= knapsack[i].wt;
		}
		else{			//otherwise fill fractionallly
		fracWt = C/(float)knapsack[i].wt;
			profit += fracWt * knapsack[i].val;
			C = 0;
		}
	}
	printf("\n\nProfit= %.2f",profit);
	return 0;

}
