#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
using namespace std;
list<int>a[210];
int dfs_sort[205],low_link[205],prt[205];
bool used[205];
int n,cnt_ch=0,cnt_ans=0,cnt=0;
inline void DFS(int x)
{
	dfs_sort[x]=low_link[x]=++cnt;
	list<int>::iterator i;
	for(i=a[x].begin();i!=a[x].end();++i)
	{
		if(prt[*i]!=x)
		{
			if(dfs_sort[*i]==0)
			{
				prt[*i]=x;
				DFS(*i);
				low_link[x]=min(low_link[x],low_link[*i]);
				if(low_link[*i]>=dfs_sort[x])
				{
                   if(!used[x])cnt_ans++,used[x]=1;
                   if(dfs_sort[x]==1)cnt_ch++;
				}
			}
			else low_link[x]=min(low_link[x],dfs_sort[*i]);
		}
	}
	return;
}
int main(){
	int x,y;
	while(scanf("%d",&n),n!=0)
	{
		memset(dfs_sort,0,sizeof(dfs_sort));
        memset(low_link,0,sizeof(low_link));
        memset(used,0,sizeof(used));
        memset(prt,0,sizeof(prt));
        cnt_ch=0,cnt_ans=0,cnt=0;
        for(int i=1;i<=205;i++)a[i].clear();
		while(scanf("%d",&x),x!=0)
		{
		    while(true)
		   {
			 scanf("%d",&y);
			 char c=getchar();
			 a[x].push_back(y);
			 a[y].push_back(x);
			 if(c=='\n')break;
		   }
	    }
        DFS(1);
        if(cnt_ch==1)cnt_ans--;
        printf("%d\n",cnt_ans);
    }
	return 0;
}