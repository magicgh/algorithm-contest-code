#include<iostream>
#include<cstdio>
#include<algorithm>
#define ri register int
using namespace std;
int a[20],n,xyj,Ans=0x7fffffff;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int k,int A,int B,int C)
{
	if(++xyj>=100000){printf("%d\n",Ans);exit(0);}
	if(Ans<=max(A,max(B,C)))return;
	if(k==n){Ans=min(Ans,max(A,max(B,C)));return;}
	DFS(k+1,A+a[k],B,C);
	DFS(k+1,A,B+a[k],C);
	DFS(k+1,A,B,C+a[k]);
}
int main()
{
	n=getint();
	for(ri i=0;i<n;i++)a[i]=getint();
	sort(a+1,a+n+1,greater<int>()); 
	DFS(0,0,0,0);
	printf("%d\n",Ans);
	return 0;
}