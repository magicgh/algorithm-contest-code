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
const int MAXN=500005;
struct node{int x,y,d,v;};
node a[MAXN];
int n,m,prt[1005],delta[1005],ans;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const node &a,const node &b){return a.v>b.v;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)prt[i]=i,delta[i]=1;
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),d=getint(),v=getint();
		a[i]=(node){x,y,d,v};
	}
	sort(a+1,a+m+1,cmp);
	for(ri i=1;i<=m;i++)
	{	
		if(a[i].d==0)
		{
			int f1=getfa(a[i].x),f2=getfa(a[i].y);
			if(delta[f1]+delta[f2]>0)//还有可分配点 
			{
				if(f1!=f2)//不在一个集合 
				{
					prt[f2]=f1;
					delta[f1]+=delta[f2]-1;
					ans+=a[i].v;
				}
				else delta[f1]--,ans+=a[i].v;//在一个集合
			}
		}
		if(a[i].d==1)
		{
			int fa=getfa(a[i].x);
			if(delta[fa]>0)delta[fa]--,ans+=a[i].v;
		}
	}
	printf("%d",ans);
	return 0;
}

