#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void print_array(int dim,int M[][dim]){
    int i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
}
void intialize(int dim,int M[][dim]){
	int i,j;
	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			M[i][j] = 0;
		}
	}
}
int main() {
    char arr[200001];
    int i;
    long long sum =0;
    scanf("%s",arr);
    int size = strlen(arr);
    int len = size;
    long long t=1;
    for(i=size-1;i>=0;i--){
    	sum += ((arr[i] - '0')*len*t)1000000007;
    	t *= 10;
    	t++;
    	len--;
    }
    printf("%lld",sum);
    return 0;
}
 