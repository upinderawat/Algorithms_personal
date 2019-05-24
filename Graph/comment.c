#include <stdio.h>
#include <string.h>
char ans[1000000];
int n;
int main(){
char buffer[100000];
int len, i, j, lines, line, single=0, multi=0, slash=0, error=0, star=0;
n=0;
printf("Enter the number of lines: ");
scanf("%d", &lines);
fgets(buffer, 100000, stdin);
for(line=1;line<=lines;line++){
printf("%d: ", line);
fflush(stdout);
fgets(buffer, 100000, stdin);
len = strlen(buffer);
single = 0;
slash = star = 0;
for(i=0;i<len;i++){
if(single){
sprintf(ans+n, "%c\0", buffer[i]);
n = strlen(ans);
}
else if(multi){
if(star){
if(buffer[i]=='/'){
multi = 0;
slash = star = 0;
sprintf(ans+n, "\n\0");
n = strlen(ans);
}
else{
star = 0;
sprintf(ans+n, "*%c\0", buffer[i]);
n = strlen(ans);
}
}
else if(buffer[i]=='*'){
star = 1;
}
else{
sprintf(ans+n, "%c\0", buffer[i]);
n = strlen(ans);
}
}
else{
if(slash){
if(buffer[i]=='/'){
sprintf(ans+n, "\n**Single line comment found on line %d\n\0", line);
n = strlen(ans);
single=1;}
else if(buffer[i]=='*'){
sprintf(ans+n, "\n**Multi line comment found on line %d\n\0", line);
n = strlen(ans);
multi = 1;}
else{
slash=0;
error = 1;
}
}
else if(buffer[i]=='/') slash = 1;}}}
if(multi){
printf("\n**Error occured. Multi line comment not closes\n\n");
}
else{
puts(ans);
}
return 0;
}