#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char a[1005],b[1005];
void DFS(char a[],char b[],int k)
{
	int i=0;
	while(b[i]!=a[0])i++;
	if(i>0)DFS(a+1,b,i);
	if(k-i-1>0)DFS(a+i+1,b+i+1,k-i-1);
	printf("%c",a[0]);
}
int main() {
	scanf("%s%s",&a,&b);
	DFS(b,a,strlen(b));
	return 0;
}