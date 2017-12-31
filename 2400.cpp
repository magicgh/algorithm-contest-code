#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<climits>
using namespace std;
const int M=100005;
list<int>a[M];
int dfs_sort[M],low_link[M],prt[M],cnt_a[M],cnt_b[M];
int n,m,k,l,cnt_ans=0,cnt=0;
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
				cnt_a[x]+=cnt_a[*i];
				cnt_b[x]+=cnt_b[*i];
				if(low_link[*i]>dfs_sort[x]&&(cnt_a[*i]==0||cnt_a[*i]==k||cnt_b[*i]==0||cnt_b[*i]==l))cnt_ans++;
			}
			else low_link[x]=min(low_link[x],dfs_sort[*i]);
		}
	}
	return;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&l);
	int x,y;
	memset(dfs_sort,0,sizeof(dfs_sort));
	memset(low_link,0,sizeof(low_link));
	memset(prt,0,sizeof(prt));
	memset(cnt_a,0,sizeof(cnt_a));
	memset(cnt_b,0,sizeof(cnt_b));
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&x);
		cnt_a[x]=1;
	}
	for(int i=1;i<=l;i++)
	{
		scanf("%d",&y);
		cnt_b[y]=1;
	}
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&x,&y);
    	a[x].push_back(y);
    	a[y].push_back(x);
	}
	DFS(1);
	printf("%d",cnt_ans);
	return 0;
}