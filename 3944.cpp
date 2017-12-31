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
const int MAXN=205;
int T,n;
vector<int>a[MAXN];
int Belong[MAXN],vst[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
bool DFS(int u,int t)
{
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(vst[*it]==t)continue;
		vst[*it]=t;
		if(!Belong[*it]||DFS(Belong[*it],t))
		{
			Belong[*it]=u;
			return 1;
		}
	}	
	return 0;
}
bool Hungry()
{
	int Ans=0;
	for(ri i=1;i<=n;i++)
		if(DFS(i,i))Ans++;
	return Ans==n;
}
int main()
{
	T=getint();
	while(T--)
	{
		n=getint();
		for(ri i=1;i<=n;i++)a[i].clear(),Belong[i]=vst[i]=0;
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=n;j++)
			{
				int color=getint();
				if(color)a[i].push_back(j);			
			}
		if(Hungry())printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}


