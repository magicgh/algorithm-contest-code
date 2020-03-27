#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
int f,v;
int a[105][105],F[105][105];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int i,int j)
{
	if(i<1||j<1)return;
	if(F[i][j]==F[i][j-1])DFS(i,j-1);//并没放花
	else DFS(i-1,j-1),printf("%d ",j);//输出花瓶
}
int main()
{
	f=getint(),v=getint();
	for(ri i=1;i<=f;i++)
		for(ri j=1;j<=v;j++)a[i][j]=getint();
	for(ri i=1;i<=f;i++)F[i][i]=F[i-1][i-1]+a[i][i];
	for(ri i=1;i<=f;i++)
		for(ri j=i+1;j<=v;j++)
			F[i][j]=max(F[i][j-1],F[i-1][j-1]+a[i][j]);
	printf("%d\n",F[f][v]);
	DFS(f,v);	
	return 0;
}

