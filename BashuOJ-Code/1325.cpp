#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<climits>
using namespace std;
list<int>a[210];
int dfs_sort[205],low_link[205],prt[205];
bool used[205];
int s,t,n,cnt_ans=INT_MAX,cnt=0;
inline void DFS(int x)
{
	dfs_sort[x]=low_link[x]=++cnt;
	list<int>::iterator i;
	for(i=a[x].begin();i!=a[x].end();++i)
	{
		if(prt[x]!=*i)
		{
			if(dfs_sort[*i]==0)
			{
				prt[*i]=x;
				DFS(*i);
				low_link[x]=min(low_link[x],low_link[*i]);
			}
			else low_link[x]=min(low_link[x],dfs_sort[*i]);
		}
	}
	return;
}
inline void Check(int u)
{
	if(u==s)return;
	if(low_link[u]>=dfs_sort[prt[u]]&&prt[u]!=s)cnt_ans=min(cnt_ans,prt[u]);
	Check(prt[u]);
}
int main(){
	scanf("%d",&n);
	int x,y;
	while(scanf("%d%d",&x,&y),x!=0&&y!=0)
	{
		a[x].push_back(y);
		a[y].push_back(x);
	}
	scanf("%d%d",&s,&t);
	DFS(s);
	Check(t);
	if(cnt_ans!=INT_MAX)printf("%d",cnt_ans);
	else puts("No solution");
	return 0;
}