#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<stack>
#include<list>
using namespace std;
const int M=1005;
list<int>a[M];
stack<int>s;
int low[M],dfn[M],belong[M],InDgree[M];
bool InStack[M];
int t,n,cnt=0,FillColor=0,Ans=0;
inline void Tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	s.push(x);
	InStack[x]=1;
	list<int>::iterator i;
    for(i=a[x].begin();i!=a[x].end();++i)
    {
    		if(!dfn[*i])
    		{
    			Tarjan(*i);
    			low[x]=min(low[x],low[*i]);
			}
			else if(InStack[*i])low[x]=min(low[x],dfn[*i]);
	}
	if(low[x]==dfn[x])
	{
		FillColor++;
		do
		{
			t=s.top();
			s.pop();
			InStack[t]=0;
			belong[t]=FillColor;
		}
		while(t!=x);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(belong,0,sizeof(belong));
	memset(InStack,0,sizeof(InStack));
	memset(InDgree,0,sizeof(InDgree));
	cin>>n;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)
	   {
	   	   cin>>t;
	   	   if(t==1)a[i].push_back(j);
	   }
	   for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
	  list<int>::iterator y;
	   for(int x=1;x<=n;x++)
	      for(y=a[x].begin();y!=a[x].end();++y)
	   {
	   	  if(belong[x]!=belong[*y])InDgree[belong[*y]]++;
	   }
	   for(int i=1;i<=FillColor;i++)if(InDgree[i]==0)Ans++;
	   cout<<Ans;
	return 0;
}
