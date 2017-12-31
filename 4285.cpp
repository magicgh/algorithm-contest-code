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
const int MAXN=200001;
const int Mod=10007;
const int INF=0x7fffffff/2;
int n,sum,Ans,w[MAXN];
vector<int>a[MAXN];
namespace FastIO
{
    const ll L=1<<15;
    char buffer[L],*S,*T;
    inline char getchar()
	{
        if(S==T){T=(S=buffer)+fread(buffer,1,L,stdin);if(S==T)return EOF;}
		return *S++;
    }
    inline const int getint()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
}using FastIO::getint;
void DFS(int u,int fa)
{
	int s=0,d1=0,d2=0;
	vector<int>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(*it==fa)continue;
		DFS(*it,u);
		sum=(sum+w[*it]*s%Mod+w[*it]*w[fa]%Mod)%Mod,s=(s+w[*it])%Mod;
		if(w[*it]>d1)d2=d1,d1=w[*it];
		else if(w[*it]>d2)d2=w[*it];
	}
	if(w[fa]>d1)d2=d1,d1=w[fa];
	else if(w[fa]>d2)d2=w[fa];
	Ans=max(Ans,d1*d2);
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int x=getint(),y=getint();
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for(ri i=1;i<=n;i++)w[i]=getint();
	DFS(1,0);
	printf("%d %d\n",Ans,(sum<<1)%Mod);
	return 0;
}


