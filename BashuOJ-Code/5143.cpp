#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=5005;
const int MAXM=1005;
const int Limit=1000;
struct Path{int u,v;};
vector<int>a[MAXM];
Path p[MAXM];
int T,n,m,Col[MAXM];
bool Flag;
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Clear()
{
	Flag=0;
	for(ri i=1;i<=Limit;i++)
		a[i].clear(),Col[i]=0;
}
inline void DFS(int u,int color)
{
	vector<int>::iterator it;
	Col[u]=color;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(!Col[*it])DFS(*it,3-color);
		else if(Col[*it]!=3-color){Flag=1;return;}
	}
}
inline bool Check()
{
	for(ri i=1;i<=m;i++)
	{
		if(!Col[i])
		{
			DFS(i,1);
			if(Flag)return 0;
		}
	}
	return 1;
}
int main()
{
	T=GetInt();
	while(T--)
	{
		Clear();
		n=GetInt(),m=GetInt();
		for(ri i=1;i<=m;i++)
		{
			int u=GetInt(),v=GetInt();
			if(u>v)swap(u,v);
			p[i]=(Path){u,v};
		}
		for(ri i=1;i<=m;i++)
			for(ri j=1;j<=m;j++)
			{
				if(i==j)continue;
				if(p[i].u<p[j].u&&p[i].v<p[j].v&&p[i].v>p[j].u)
				{
					a[i].push_back(j);
					a[j].push_back(i);
				}
			}
		printf(Check()?"sane\n":"non\n");
	}
	return 0;
}


