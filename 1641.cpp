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
int sum,n,c,p[55],w[55],ans=0x7fffffff;
bool vst[55];
void DFS(int pos,int w1,int w2,int cnt)
{
	if(w1>ans)return;
	if(cnt>=n)
	{
		ans=w1;
		return;
	}
	int l=pos,r=pos;
	while(vst[l]&&l>=1)l--;
	while(vst[r]&&r<=n)r++;//找到没关的灯 
	if(l>=1)
	{
		vst[l]=1;
		DFS(l,w1+abs(p[l]-p[pos])*w2,w2-w[l],cnt+1);
		vst[l]=0;
	}
	if(r<=n)
	{
		vst[r]=1;	
		DFS(r,w1+abs(p[r]-p[pos])*w2,w2-w[r],cnt+1);
		vst[r]=0;
	}
}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),c=getint();
	for(ri i=1;i<=n;i++)p[i]=getint(),w[i]=getint(),sum+=w[i];
	vst[c]=1; 
	DFS(c,0,sum-w[c],1);
	printf("%d",ans);
	return 0;
}

