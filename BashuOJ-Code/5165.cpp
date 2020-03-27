#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define ri register int
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
const int MAXN=2000005;
char ch[MAXN];
ll w[MAXN];
int Trie[MAXN][30];
int n,m,cnt=1;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll GetLL()
{
	ll num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Insert(char *s,ll val)
{
	int root=1,len=strlen(s+1);
	for(ri i=1;i<=len;i++)
	{
		int x=s[i]-'a'+1;
		if(!Trie[root][x])
			Trie[root][x]=++cnt;
		root=Trie[root][x];
	}
	w[root]	=val;
}
inline ll Query(char *s)
{
	int root=1,len=strlen(s+1);
	for(ri i=1;i<=len;i++)
	{
		int x=s[i]-'a'+1;
		if(!Trie[root][x])return -1ll;
		root=Trie[root][x];
	}
	return w[root];
}
int main()
{
	n=GetInt();
	memset(w,-1,sizeof(w));
	for(ri i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		ll w=GetLL();
		Insert(ch,w);
	}
	m=GetInt();
	for(ri i=1;i<=m;i++)
	{
		int x=GetInt();
		ll Ans=0;
		for(ri j=1;j<=x;j++)
		{
			scanf("%s",ch+1);
			ll t=Query(ch);
			if(t==-1){Ans=-1;break;}
			else Ans+=t;
		}
		printf("%lld\n",Ans);
	}
	return 0;
}