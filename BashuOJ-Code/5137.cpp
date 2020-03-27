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
const int MAXN=1000005;
string str;
int Trie[MAXN][30];
int n,m,cnt=1,tot,dep[MAXN],p[MAXN][21],pos[MAXN];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Getchar(string &str)
{
	str.clear();
	char ch=getchar();
	while(!islower(ch))ch=getchar();
	while(islower(ch))str.push_back(ch),ch=getchar();
}
inline void ST(int i)
{
	int k=log2(dep[i]);
	for(ri j=1;j<=k;j++)
		p[i][j]=p[p[i][j-1]][j-1];
}
inline void Insert(string &str)
{
	int u=1;string::reverse_iterator it;
	for(it=str.rbegin();it!=str.rend();++it)
	{
		int x=*it-'a'+1;
		if(!Trie[u][x])
		{
			Trie[u][x]=++cnt;
			p[cnt][0]=u,dep[cnt]=dep[u]+1;
			ST(cnt);
		}
		u=Trie[u][x];
	}
	pos[++tot]=u;
}
inline int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=log2(dep[a]);
	for(ri i=k;i>=0;i--)
		if(dep[a]-(1<<i)>=dep[b])a=p[a][i];
	if(a==b)return a;
	for(ri i=k;i>=0;i--)
		if(p[a][i]!=-1&&p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
int main()
{
	n=GetInt(),m=GetInt();
	for(ri i=1;i<=n;i++)Getchar(str),Insert(str);
	for(ri i=1;i<=m;i++)
	{
		int op=GetInt();
		if(op==1)Getchar(str),Insert(str);
		if(op==2)
		{
			int Len=GetInt(),lca=pos[GetInt()];
			for(ri i=2;i<=Len;i++)lca=LCA(lca,pos[GetInt()]);
			printf("%d\n",dep[lca]);
		}
	}
	return 0;
}


