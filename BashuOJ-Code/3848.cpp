#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<list>
using namespace std;
struct node
{
	int to,value;
};
int n,m,q,dist[1005]={0},used[1005]={0},prt[1005]={0},MaxPath[1005][1005];
list<node>a[1005];
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
inline void Prim(int v0)
{
	for(int i=1;i<=n;i++)dist[i]=0x7fffffff;
	dist[v0]=0,prt[v0]=0;
	for(int i=1;i<=n;i++)
	{
		int Min=0x7fffffff,MinNum=0;
		for(int j=1;j<=n;j++)if(!used[j]&&Min>dist[j])Min=dist[j],MinNum=j;
		int Father=prt[MinNum];
		for(int j=1;j<=n;j++)if(used[j])MaxPath[MinNum][j]=MaxPath[j][MinNum]=MaxPath[j][Father]>Min?MaxPath[j][Father]:Min;
		used[MinNum]=1;
		list<node>::iterator k;
		for(k=a[MinNum].begin();k!=a[MinNum].end();++k)
		{
			if(!used[k->to]&&dist[k->to]>k->value)dist[k->to]=k->value,prt[k->to]=MinNum;
		}
		
	}
}
int main(){
	n=GetInt(),m=GetInt();
	memset(MaxPath,0,sizeof(MaxPath));
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		a[x].push_back({y,z});
		a[y].push_back({x,z});
	}
	Prim(1);
	q=GetInt();
	for(int i=1;i<=q;i++)
	{
		x=GetInt();
		y=GetInt();
		printf("%d\n",(!MaxPath[x][y])?-1:MaxPath[x][y]);
	}
	return 0;
}
