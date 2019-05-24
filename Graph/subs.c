#include <stdio.h>
#include <string.h>

char str[10000], str2[10000];
int table[1000][100];

int find(){
int l1 = strlen(str), l2 = strlen(str2), i, j, ans=-1, k, f;
//printf("%d %d**\n", l1, l2);
i=j=0;
for(k=0;k<l2;k++){
j = k;
i=0;
f=1;
while(i<l1 && j<l2){
if(str[i]!=str2[j]){
f=0;
break;
}
i++;
j++;
}
if(f && j>=l2){
ans = l2-k;
break;
}
}
return ans;
}

int main(){
char symbols[100];
int i, nSymb, nStates, len, j, t, f, choice, ch;
printf("Enter the number of input symbols: ");
scanf("%d", &nSymb);
printf("\nEnter the symbols\n");
for(i=0;i<nSymb;i++){
printf("Symbol %d: ", i+1);
scanf(" %c", &symbols[i]);
}
ch=1;

while(ch){
printf("\n\n1. Ending with DFA\n2. Starting with DFA\n3. DFA containing substring\nEnter Choice: ");
scanf("%d", &choice);
while(choice<1 || choice>3){
printf("Invalid Choice entered\nEnter a valid choice: ");
scanf("%d", &choice);
}
printf("\nEnter the string: ");
scanf(" %s", str);
do{
len = strlen(str);
for(i=0;i<len;i++){
f=0;
for(j=0;j<nSymb;j++){
if(str[i]==symbols[j]){
f=1;
break;
}
}
if(f==0) break;
}
if(f==0){
printf("Invalid String\nPlease enter a valid string: ");
scanf(" %s", str);
}
}while(f==0);
//printf("**%s**\n", str);
switch(choice){
case 1:
nStates = len+1;
for(i=0;i<nStates;i++){
for(j=0;j<nSymb;j++){
table[i][j] = -1;
}
}
for(i=0;i<len;i++){
for(j=0;j<nSymb;j++){
if(symbols[j]==str[i]) break;
}
table[i][j] = i+1;
}
for(i=0;i<nStates;i++){
for(j=0;j<i;j++){
str2[j] = str[j];
}
for(j=0;j<nSymb;j++){
//printf("**%d %d**\n", i, j);
if(table[i][j]==-1){
str2[i] = symbols[j];
str2[i+1] = '\0';
t = find();
if(t==-1) table[i][j] = 0;
else table[i][j] = t;
}
}
}
printf("\nTransition table is:\n\n");
printf("\t");
for(i=0;i<nSymb;i++) printf("%c\t", symbols[i]);
printf("\n----------------------------------\n");
for(i=0;i<nStates;i++){
if(i==0){
printf("-> q%d", i);
}
else{
printf("   q%d", i);
}
if(i==nStates-1){
printf("*");
}
printf("\t|");
for(j=0;j<nSymb;j++){
printf("q%d\t", table[i][j]);
}
printf("\n");
}

printf("\n\nKey:\n");
printf("-> - Initial State\n");
printf("* - Final State\n\n");
break;
case 2:
len = strlen(str);
nStates = len+2;
for(i=0;i<nStates;i++){
for(j=0;j<nSymb;j++){
table[i][j] = -1;
}
}
for(i=0;i<len;i++){
for(j=0;j<nSymb;j++){
if(symbols[j]==str[i]) break;
}
table[i][j] = i+1;
}

for(i=0;i<nStates-2;i++){
for(j=0;j<nSymb;j++){
//printf("**%d %d**\n", i, j);
if(table[i][j]==-1){
table[i][j] = nStates-1;
}
}
}
for(i=0;i<nSymb;i++){
table[nStates-2][i] = nStates-2;
table[nStates-1][i] = nStates-1;
}
printf("\nTransition table is:\n\n");
printf("\t");
for(i=0;i<nSymb;i++) printf("%c\t", symbols[i]);
printf("\n----------------------------------\n");
for(i=0;i<nStates;i++){
if(i==0){
printf("-> q%d", i);
}
else{
printf("   q%d", i);
}
if(i==nStates-2){
printf("*");
}
else if(i==nStates-1){
printf("#");
}
printf("\t|");
for(j=0;j<nSymb;j++){
printf("q%d\t", table[i][j]);
}
printf("\n");
}

printf("\n\nKey:\n");
printf("-> - Initial State\n");
printf("* - Final State\n");
printf("# - Dead State\n\n");
break;
case 3:
len = strlen(str);
nStates = len+1;
for(i=0;i<nStates;i++){
for(j=0;j<nSymb;j++){
table[i][j] = -1;
}
}
for(i=0;i<len;i++){
for(j=0;j<nSymb;j++){
if(symbols[j]==str[i]) break;
}
table[i][j] = i+1;
}
for(i=0;i<nStates;i++){
for(j=0;j<i;j++){
str2[j] = str[j];
}

for(j=0;j<nSymb;j++){
//printf("**%d %d**\n", i, j);
if(table[i][j]==-1){
str2[i] = symbols[j];
str2[i+1] = '\0';
t = find();
if(t==-1) table[i][j] = 0;
else table[i][j] = t;
}
}
}
for(i=0;i<nSymb;i++){
table[nStates-1][i] = nStates-1;
}
printf("\nTransition table is:\n\n");
printf("\t");
for(i=0;i<nSymb;i++) printf("%c\t", symbols[i]);
printf("\n----------------------------------\n");
for(i=0;i<nStates;i++){
if(i==0){
printf("-> q%d", i);
}
else{
printf("   q%d", i);
}
if(i==nStates-1){
printf("*");
}
printf("\t|");
for(j=0;j<nSymb;j++){
printf("q%d\t", table[i][j]);
}
printf("\n");
}
printf("\n\nKey:\n");
printf("-> - Initial State\n");
printf("* - Final State\n\n");
}

printf("Enter 1 to make another dfa, 0 to exit: ");
scanf("%d", &ch);

while(ch<0 || ch>1){
printf("Invalid Choice\nPlease enter a valid choice: ");
scanf("%d", &ch);
}
}
return 0;
}