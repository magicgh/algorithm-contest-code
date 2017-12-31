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
const int INF=0x7fffffff/2;
const int MAXN=400005;
const int MAXW=1000005;
struct Path{int u,v;};
struct List{int u,v,Next;};
vector<Path>Edge[MAXW];
List a[MAXN<<1]; 
int n,Max,Maxlen,cnt,tot,vst[MAXN<<1],Ans[MAXN],Head[MAXN],Link[MAXN<<1]; 
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void AddEdge(int u,int v)
{
	a[++tot]=(List){u,v,Head[u]},Head[u]=tot,Link[tot]=u;
	a[++tot]=(List){v,u,Head[v]},Head[v]=tot,Link[tot]=v;
}
int DFS(int u)
{
	vst[u]=cnt;
	int Maxson=0;
	for(ri i=Head[u];i;i=a[i].Next)
	{
		if(vst[a[i].v]==cnt)continue;
		int ch=DFS(a[i].v);
		Maxlen=max(Maxlen,Maxson+ch+1);
		Maxson=max(Maxson,ch+1);
	}
	return Maxson;
} 
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint(),w=getint();
		Max=max(Max,w);
		Edge[w].push_back((Path){u,v});
	}
	for(ri i=1;i<=Max;i++)//枚举边权(Gcd) 
	{
		for(ri j=i;j<=Max;j+=i)//枚举i的倍数 
		{
			vector<Path>::iterator it;
			for(it=Edge[j].begin();it!=Edge[j].end();++it)
				 AddEdge(it->u,it->v);
		} 
		Maxlen=0,cnt++;
		for(ri u=1;u<=tot;u++)
          if(vst[Link[u]]!=cnt)DFS(Link[u]);
        for(ri u=1;u<=tot;u++)Head[Link[u]]=0;
        tot=0,Ans[Maxlen]=i; 
	} 
	for(ri i=n-1;i>=1;i--)
		Ans[i]=max(Ans[i],Ans[i+1]);//Gcd的非增性
	for(ri i=1;i<=n;i++)printf("%d\n",Ans[i]); 
	return 0;
}


