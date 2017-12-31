#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,len1[200005]={0},len2[200005]={0},head[2000005]={0},prt[200005]={0};
struct node
{
	int next,to;
}a[400005];
inline void AddEdge(int x,int y)
{
	a[++cnt].to=y;
	a[cnt].next=head[x];
	head[x]=cnt;
}
inline void dfs(int x)
{
	for(int i=head[x];i;i=a[i].next)
	{
		int y=a[i].to;
		if(prt[x]!=y)
		{
			prt[y]=x;
			dfs(y);
			if(len1[y]+1>len1[x])
			{
				len2[x]=len1[x];
				len1[x]=len1[y]+1;
			}
			else if(len1[y]+1>len2[x])len2[x]=len1[y]+1;
		}
	}
	return;
}
int main(){
	cin>>n;
	memset(a,0,sizeof(a));
	int x,y;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		x++,y++;
		AddEdge(x,y);
		AddEdge(y,x);
	}
	dfs(1);
	int Max=INT_MIN;
	for(int i=1;i<=n;i++)Max=max(Max,len1[i]+len2[i]);
	cout<<Max;
	return 0;
}
