//recurrsive without dp
#include <stdio.h>
#include <string.h>

int max(int a, int b){
	return (a>b?a:b);
}
int lcs(char *A,char *B,int lenA, int lenB){
	int i,j;
	if(lenA == 0 || lenB == 0){
		return 0;
	}
	for(i=0,j=0;i<lenA || j < lenB;i++,j++){
		if(A[i] == B[j]){
			//match occurs
			return 1+lcs(A+1,B+1,lenA-1,lenB-1);
		}
		else{
			return max(lcs(A,B+1,lenA,lenB-1),lcs(A+1,B,lenA-1,lenB));
		}
	}
}
int main(){
	char A[100];
	char B[100];
	int maxlen;
	int lenA;
	int lenB;

	printf("String A:");
	scanf("%s",A);
	printf("String B:");
	scanf("%s",B);
	lenA = strlen(A);
	lenB = strlen(B);
	maxlen = lcs(A,B,lenA,lenB);
	printf("%d\n", maxlen );
	return 0;
}