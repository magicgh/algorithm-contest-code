#include<bits/stdc++.h>
#define N 3005
using namespace std;
int n,t,cnt=0,ans=INT_MAX,f[N]={0},c[N]={0};
struct Star
{
	int head,next,to;
}a[N*2];
inline void DP(int x,int root)
{
	int ch[N],len=0;
	for(int i=a[x].head;i;i=a[i].next)
	{
		int y=a[i].to;
		if(y==root)continue;
		DP(y,x);
		ch[++len]=f[y];
		}
        int ret=0;
		sort(ch+1,ch+len+1);
		for(int j=1;j<=len;j++)ret=max(ret,len-j+ch[j]);
	    f[x]=ret+1;
}
inline void AddEdge(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=a[x].head;
	a[x].head=cnt;
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&t);
		AddEdge(t,i);AddEdge(i,t);
	}
	for(int i=1;i<=n;i++)
	{
	memset(f,0,sizeof(f));
	DP(i,0);
	ans=ans<f[i]?ans:f[i];
	c[i]=f[i];
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		if(c[i]==ans)printf("%d ",i);
	}
	return 0;
}