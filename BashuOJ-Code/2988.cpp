#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<climits>
#include<list>
using namespace std;
struct node
{
	int to,value;
};
list<node>a[10005];
int Ans=0,n,m,dist[10005]={0},vst[10005]={0};
inline void Prim(int v0)
{
	for(int i=1;i<=n;i++)dist[i]=INT_MAX;
	dist[v0]=0;
	for(int i=1;i<=n;i++)
	{
		int Min=INT_MAX,MinNum=0;
		for(int j=1;j<=n;j++)
		{
			if(!vst[j]&&Min>dist[j])Min=dist[j],MinNum=j;
		}
		Ans=max(Ans,dist[MinNum]),vst[MinNum]=1;
		list<node>::iterator k;
		for(k=a[MinNum].begin();k!=a[MinNum].end();++k)
		{
			if(!vst[k->to]&&dist[k->to]>k->value)dist[k->to]=k->value;
		}
	}
}
int main(){
   int x,y,z;
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;i++)
   {
   	scanf("%d%d%d",&x,&y,&z);
   	a[x].push_back({y,z});
   	a[y].push_back({x,z});
   }
   Prim(1);
   bool f=0;
   for(int i=1;i<=n;i++)if(!vst[i])f=1;
   printf("%d",f==1?-1:Ans);
	return 0;
}