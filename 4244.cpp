#include<iostream>
#include<cstdio>
#include<cstring>
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
struct node{int x,y,z;};
node tree[MAXN];
int Ans,n,m,K,k,prt[MAXN];
inline bool cmp(const node &a,const node &b){return a.z>b.z;}
inline int getint()	
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int getfa(int x)
{
	if(prt[x]==x)return x;
	return prt[x]=getfa(prt[x]);
}
void Kruskal()
{
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(tree[i].x),f2=getfa(tree[i].y);
		if(f1!=f2)
		{
			prt[f2]=f1;
			Ans+=tree[i].z;
			if(++k==K)break;
		}
	}
}
int main()
{
	n=getint(),m=getint(),K=getint();
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),w=getint();
		tree[i]=(node){u,v,w};
	}
	sort(tree+1,tree+m+1,cmp);
	Kruskal();
	printf("%d",Ans);
	return 0;
}

