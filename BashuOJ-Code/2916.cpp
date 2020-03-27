#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<stack>
#include<list>
#include<climits>
using namespace std;
const int M=5005;
list<int>a[M];
stack<int>s;
int low[M],dfn[M],belong[M],InDgree[M],Size[M],ColorMin[M];
bool InStack[M];
int n,m,cnt=0,FillColor=0,Ans=0;
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
		ColorMin[FillColor]=INT_MAX;
		do
		{
			t=s.top();
			s.pop();
			Size[FillColor]++;
			ColorMin[FillColor]=min(ColorMin[FillColor],t);
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
	memset(InDgree,0,sizeof(InDgree));
	memset(Size,0,sizeof(Size));
	memset(ColorMin,0,sizeof(ColorMin));
	int x,y,z;
	scanf("%d%d",&n,&m);		
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		a[x].push_back(y);
		if(z==2)a[y].push_back(x);
	} 
	   for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
	   int MaxSize=INT_MIN,MaxColor=0,MinVillage=0; 
       for(int i=1;i<=FillColor;i++)
	   {
	   	 if(MaxSize<Size[i])
	   	 {
	   	 	MinVillage=ColorMin[i];
	   	 	MaxSize=Size[i];
	   	 	MaxColor=i;
		 }
		 if(MaxSize==Size[i]&&MinVillage>ColorMin[i])
		 {
		 	MinVillage=ColorMin[i];
		 	MaxColor=i;
		 }
	   } 
	   printf("%d\n",MaxSize);
	   for(int i=1;i<=n;i++)
	   	  if(belong[i]==MaxColor)printf("%d ",i);
	return 0;
}
