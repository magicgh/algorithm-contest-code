#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<stack>
#include<list>
#include<climits>
using namespace std;
const int M=1050;
list<int>a[M];
list<int>b[M];
stack<int>s;
int low[M],dfn[M],belong[M],InDgree[M];
bool InStack[M],Exist[M][M],flag=0;
int t,m,n,cnt=0,FillColor=0,Ans=0,CntDgree;
inline void DFS(int u,int k)
{
	if(k==FillColor)flag=1;
	list<int>::iterator i;
	for(i=b[u].begin();i!=b[u].end();++i)DFS(*i,k+1);
}
inline void Tarjan(int x)
{
	int temp;
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
			temp=s.top();
			s.pop();
			InStack[temp]=0;
			belong[temp]=FillColor;
		}
		while(temp!=x);
	}
	return;
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
	cnt=0,FillColor=0,Ans=0,CntDgree=0;
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(belong,0,sizeof(belong));
	memset(InStack,0,sizeof(InStack));
	memset(Exist,0,sizeof(Exist));
	memset(InDgree,0,sizeof(InDgree));
	scanf("%d%d",&n,&m);
	int x,y,Root;
	for(int j=1;j<=1005;j++)a[j].clear(),b[j].clear();
	for(int j=1;j<=m;j++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
	} 
	   for(int j=1;j<=n;j++)if(!dfn[j])Tarjan(j);
	   list<int>::iterator k;
	   for(int j=1;j<=n;j++)
	   	  for(k=a[j].begin();k!=a[j].end();++k)
	   	  {
	   	  	if(belong[j]!=belong[*k]&&!Exist[belong[j]][belong[*k]])
	   	  	{
	   	  		b[belong[j]].push_back(belong[*k]);
	   	  		Exist[belong[j]][belong[*k]]=1;
	   	  		InDgree[belong[*k]]++;
			}
		  }
	for(int i=1;i<=FillColor;i++)
	{
		if(InDgree[i]==0)
		{
			Root=i;
			CntDgree++;
		}
	}
	if(CntDgree>1)
	{
		puts("No");
		continue;
	}
	DFS(Root,1);
	if(flag)puts("Yes");
	else puts("No");
	}
	return 0;
}