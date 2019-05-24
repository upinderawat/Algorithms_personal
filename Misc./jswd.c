//job scheduling with deadlines
#include <stdio.h>
#include <stdlib.h>

typedef struct job{
	int profit;
	int deadline;
}job;

int cmp(const void *a,const void *b){
	int l = (*(job *)a).profit ;//(job *)a->profit
	int r = (*(job *)b).profit ;	
	
	return r - l;
}

int main(){
    job *arrjob;
    job *jobseq;	//gives the job seq with deadline
    int N,max;
    int i;
    printf("Input number of jobs: ");
    scanf("%d",&N);
	arrjob = (job *)malloc(sizeof(job *)*N);
	for(i=0;i<N;i++){
		printf("Profit %d job: ",i+1);
		scanf("%d",&arrjob[i].profit);
		printf("Deadline %d job: ",i+1);
		scanf("%d",&arrjob[i].deadline);
	}
	qsort(arrjob,N,sizeof(job),cmp);
	for(i=0;i<N;i++){
		printf("profit %d : %d\n",i+1,arrjob[i].profit);
		printf("deadline %d : %d\n\n",i+1,arrjob[i].deadline);
	}
	max = arrjob[0].deadline;
	for(i =1;i<N;i++){
		if(arrjob[i].deadline > max)
			max = arrjob[i].deadline;
	}
	jobseq = (job *)malloc(sizeof(job *)*max);
	for(i = max-1;i>=0;i--){
		
	return 0;
}

