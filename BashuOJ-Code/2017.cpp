#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<stack>
#include<list>
using namespace std;
const int M=10005;
list<int>a[M];
stack<int>s;
int low[M],dfn[M],belong[M],OutDgree[M],Size[M];
bool InStack[M];
int n,m,cnt=0,FillColor=0,Ans=0,Num=0;
inline void Tarjan(int x)
{
	int t;
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
			Size[FillColor]++;
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
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(belong,0,sizeof(belong));
	memset(InStack,0,sizeof(InStack));
	memset(Size,0,sizeof(Size));
	memset(OutDgree,0,sizeof(OutDgree));
	scanf("%d%d",&n,&m);
	int x1,x2;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x1,&x2);
		a[x1].push_back(x2);
	}
	   for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
	  list<int>::iterator y;
	   for(int x=1;x<=n;x++)
	      for(y=a[x].begin();y!=a[x].end();++y)
	   {
	   	  if(belong[x]!=belong[*y])OutDgree[belong[x]]++;
	   }
	   for(int i=1;i<=FillColor;i++)if(OutDgree[i]==0)Num++,Ans=Size[i];
	   printf("%d\n",Num==1?Ans:0); 
	return 0;
}