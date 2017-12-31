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
string Hash[MAXN],h[MAXN],ch[MAXN];
vector<int>a[MAXN],Ans[MAXN];
int Deg[MAXN];
int k,n,root;
bool Ban[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Clear()
{
	for(ri i=1;i<=50;i++)
		a[i].clear(),Deg[i]=root=0;
}
void DFS(int u)
{
	h[u]="(";
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)DFS(*it);
	int cnt=0;
	for(it=a[u].begin();it!=a[u].end();++it)ch[++cnt]=h[*it];
	sort(ch+1,ch+cnt+1);
	for(ri i=1;i<=cnt;i++)h[u]+=ch[i];
	h[u]+=")";
}
inline string Init()
{
	Clear();
	for(ri i=1;i<n;i++)
	{
		int x=getint(),y=getint();
		a[x].push_back(y);
		Deg[y]++;
	}
	for(ri i=1;i<=n;i++)
		if(!Deg[i])root=i;
	DFS(root);
	return h[root];
}
int main()
{
	k=getint(),n=getint();
	for(ri i=1;i<=k;i++)
		Hash[i]=Init();
	for(ri i=1;i<=k;i++)
	{
		if(Ban[i])continue;
		for(ri j=i+1;j<=k;j++)
			if(Hash[i]==Hash[j])
			{
				Ban[j]=1;
				Ans[i].push_back(j);
			}
	}
	for(ri i=1;i<=k;i++)
	{
		if(Ban[i])continue;
		printf("%d",i);
		vector<int>::iterator it;
		for(it=Ans[i].begin();it!=Ans[i].end();++it)
			printf("=%d",*it);
		printf("\n");
	}
	return 0;
}

