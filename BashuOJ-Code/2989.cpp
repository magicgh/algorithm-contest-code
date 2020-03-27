#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
#include<algorithm>
//#include<vector>
using namespace std;
list<int>a[205];
struct node
{
	int a,b;
}data[1005];
//vector<int>data[5005];
int p=0,n,m,cnt=0,prt[205],low_link[205],dfs_sort[205];
bool used[205]; 
inline bool cmp(const node a,const node b)
{
	return a.a<b.a||(a.a==b.a&&a.b<b.b);
}
inline void DFS(int x)
{
	dfs_sort[x]=low_link[x]=++cnt;
	list<int>::iterator i;
	for(i=a[x].begin();i!=a[x].end();++i)
	{
		if(prt[x]!=*i)
		{
			//cout<<x<<' '<<*i<<":**:"<<used[*i]<<endl;
			if(dfs_sort[*i]==0)
			{
				//cout<<x<<' '<<*i<<"::"<<used[*i]<<endl;
				prt[*i]=x;
				DFS(*i);
				//cout<<x<<"->"<<*i<<":::"<<low_link[x]<<" "<<low_link[*i]<<endl;
				low_link[x]=min(low_link[x],low_link[*i]);
		        if(low_link[*i]>dfs_sort[x])data[++p].a=x,data[p].b=*i;
				
			}
			else 
			{
			low_link[x]=min(low_link[x],dfs_sort[*i]);
			}
		}
	}
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(low_link,0,sizeof(low_link));
	memset(dfs_sort,0,sizeof(dfs_sort));
	memset(used,0,sizeof(used));
	memset(prt,0,sizeof(prt));
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	DFS(1);
	sort(data+1,data+p+1,cmp);
	for(int i=1;i<=p;i++)cout<<data[i].a<<" "<<data[i].b<<endl;
	//map<int,int>::iterator i;
	//for(i=data.begin();i!=data.end();++i)printf("%d% d\n",i->first,i->second);
	return 0;
}
