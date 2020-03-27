#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<stack>
#include<vector>
#define rui register unsigned int
using namespace std;
const int MAXN=4005;
stack<int>s;
vector<int>a[MAXN];
int part,cnt,n,m,dfn[MAXN],low[MAXN],belong[MAXN],opp[MAXN];
bool ins[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	s.push(x),ins[x]=1;
	vector<int>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)
	{
		if(!dfn[*it])Tarjan(*it),low[x]=min(low[x],low[*it]);
		else if(ins[*it])low[x]=min(low[x],dfn[*it]);
	}
	if(low[x]==dfn[x])
	{
		int u;part++;
		do {u=s.top(),s.pop(),ins[u]=0,belong[u]=part;}
		while(u!=x);
	}
	
}
int main()
{
	n=getint(),m=getint();
	a[3*n].push_back(n),a[0].push_back(2*n);//限定新郎新娘位置 
	for(rui i=1;i<n;i++)
	{
		a[i].push_back(3*n+i),a[3*n+i].push_back(i);
		a[2*n+i].push_back(n+i),a[n+i].push_back(2*n+i);//男左女右,男右女左 
	}
	int n1,n2;char c1,c2;
	for(rui i=1;i<=m;i++)
	{
		scanf("%d%c %d%c",&n1,&c1,&n2,&c2);
		if(c1=='w')n1+=n;if(c2=='w')n2+=n;
		a[n2+2*n].push_back(n1);
		a[n1+2*n].push_back(n2);
	}
	for(int i=0;i<4*n;i++)if(!dfn[i])Tarjan(i);	
	for(int i=0;i<2*n;i++)
	{
		if(belong[i]==belong[i+2*n]){printf("bad luck\n");return 0;}
		opp[belong[i]]=belong[i+2*n];
		opp[belong[i+2*n]]=belong[i];
	}
	memset(ins,0,sizeof(ins));
	for(rui i=1;i<=part;i++)if(!ins[i])ins[opp[i]]=1;
	for(rui i=0;i<2*n;i++)
	{
		if(i==n)continue;
		if(!ins[belong[i]])
		{
			if(i<n)printf("%dh ",i);
			if(i>=n)printf("%dw ",i-n);
		}
	} 
	return 0;
}

