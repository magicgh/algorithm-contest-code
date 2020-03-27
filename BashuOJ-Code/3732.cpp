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
const int MAXN=55;
vector<int>a[MAXN];
string Hash[MAXN],h[MAXN],ch[MAXN];
int n,m,Max;
int Size[MAXN],f[MAXN];
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
		a[i].clear(),Max=Size[i]=f[i]=0;
}
void GetCore(int u,int fa)
{
	vector<int>::iterator it;
	Size[u]=1; 
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		GetCore(*it,u);
		Size[u]+=Size[*it];
		f[u]=max(f[u],Size[*it]);
	}
	f[u]=max(f[u],n-Size[u]);
	Max=max(Max,f[u]);
}
void GetHash(int u,int fa)
{
	h[u]="(";
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		GetHash(*it,u);
	}
	int cnt=0;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		ch[++cnt]=h[*it];
	}
	sort(ch+1,ch+cnt+1);
	for(ri i=1;i<=cnt;i++)
		h[u]+=ch[i];
	h[u]+=")";
}
inline string Init()
{
	Clear();
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int fa=getint();
		if(!fa)continue;
		a[fa].push_back(i);
		a[i].push_back(fa);
	}
	GetCore(1,0);
	string Ans="";
	for(ri i=1;i<=n;i++)
	{
		if(f[i]==Max)
		{
			GetHash(i,0);
			if(h[i]>Ans)Ans=h[i];
		}
	}
	return Ans;
}
int main()
{
	m=getint();
	for(ri i=1;i<=m;i++)
		Hash[i]=Init();
	for(ri i=1;i<=m;i++)
		for(ri j=1;j<=i;j++)
			if(Hash[i]==Hash[j]){printf("%d\n",j);break;}
	return 0;
}

