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
const int MAXN=2000005;
const ll Mod=32416190071ll;
struct node{int to,next;ll val;};
node Edge[MAXN];
int N,cnt,Deg[MAXN],H[MAXN];
ll f[MAXN];
queue<int>q;
inline void AddEdge(int x,int y,ll z)
{
	Edge[++cnt]=(node){y,H[x],z};
	H[x]=cnt;
}
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
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
	inline const ll GetLL()
	{
		ll num=0,bj=1;
		char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
};
using namespace FastIO;
void Topsort()
{
	int Cnt=0,Last;
	for(ri i=1;i<=N;i++)
		if(!Deg[i])q.push(i),Cnt++;
	while(!q.empty())
	{
		int now=q.front();q.pop(),Last=now;
		for(int i=H[now];i;i=Edge[i].next)
		{
			int y=Edge[i].to,z=Edge[i].val;
			f[y]=(f[y]+f[now]*z%Mod)%Mod;
			Deg[y]--;
			if(!Deg[y])q.push(y);
		} 
	}
	printf("%d\n%lld\n",Cnt,f[Last]);
}
int main()
{
	N=GetInt();
	for(ri i=1;i<N;i++)
	{
		int u=GetInt(),v=GetInt();ll w=GetLL();
		AddEdge(v,u,w),Deg[u]++;
	}
	for(ri i=1;i<=N;i++)f[i]=GetLL();
	Topsort();
	return 0;
}

