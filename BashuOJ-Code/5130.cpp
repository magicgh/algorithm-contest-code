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
const int MAXN=100005;
vector<int>a[MAXN];
int n,k,t,tot,ret,List[MAXN],prt[MAXN],ctrl[MAXN];
bool vst[MAXN];
namespace FastIO
{
	const int L=1<<15;
	char buf[L],*S,*T;
	inline char getchar()
	{
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,L,stdin);
			if(S==T)return EOF;
		}
		return *S++;
	}
	inline const int GetInt()
	{
		int num=0,bj=1;
		char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	inline void PutInt(int x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)PutInt(x/10);
	     putchar(x%10+'0');
	}
}
using FastIO::GetInt;
using FastIO::PutInt;
void BFS(int v0)
{
	queue<int>q;
	q.push(v0);
	while(!q.empty())
	{
		int now=q.front();q.pop();
		List[++tot]=now;
		if(vst[now])continue;
		vst[now]=1;
		vector<int>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(vst[*it])continue;
			prt[*it]=now,q.push(*it);
		}
	}
}
void DFS(int u,int fa,int k)
{
	ctrl[u]=1;
	if(!k)return;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u,k-1);
	}
}
int main()
{
	n=GetInt(),k=GetInt(),t=GetInt();
	for(ri i=1;i<n;i++)
	{
		int u=GetInt(),v=GetInt();
		a[u].push_back(v);
		a[v].push_back(u);
	}
	BFS(1);
	for(ri i=n;i>=1;i--)
	{
		int now=List[i];
		if(!ctrl[now])
		{
			ret++;
			for(ri j=1;j<=k;j++)now=prt[now];
			DFS(now,0,k);
		} 
	}
	PutInt(ret);
	return 0;
}

