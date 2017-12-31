#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<list>
#include<climits>
using namespace std;
int N,M;
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
inline int Min(int a,int b,int c)
{
	return min(a,min(b,c));
}
struct Tree
{
	list<int>a[200005];
	int Color[50005],f[200005][4];
	bool vst[20005];
	void AddEdge(int x,int y)
	{	
		a[x].push_back(y);
		a[y].push_back(x);
	}
	void TreeDP(int u)
	{
		vst[u]=1;
		if(u<=N){f[u][Color[u]]=1,f[u][1-Color[u]]=INT_MAX,f[u][2]=INT_MAX;return;}
		int sum0=1,sum1=1,sum2=0;
		list<int>::iterator i;//蜜汁位置 
		for(i=a[u].begin();i!=a[u].end();++i)
			if(!vst[*i])
			{
				TreeDP(*i);
				sum0+=Min(f[*i][0]-1,f[*i][1],f[*i][2]);
				sum1+=Min(f[*i][0],f[*i][1]-1,f[*i][2]);
				sum2+=Min(f[*i][0],f[*i][1],f[*i][2]);
			}	
		f[u][0]=sum0,f[u][1]=sum1,f[u][2]=sum2;
	}
};	
Tree leafcolor;
int main(){
	int x,y;
	M=GetInt();
	N=GetInt();
	for(int i=1;i<=N;i++)leafcolor.Color[i]=GetInt();
	for(int i=1;i<=M-1;i++)
	{
		x=GetInt();y=GetInt();
		leafcolor.AddEdge(x,y);
	}
	leafcolor.TreeDP(M);
	printf("%d",Min(leafcolor.f[M][0],leafcolor.f[M][1],leafcolor.f[M][2]));
	return 0;
}

