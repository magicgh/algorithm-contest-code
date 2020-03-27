#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ll long long
using namespace std;
const int MAXN=30005;
int n,m,ans,prt[MAXN],C[MAXN];
struct tree{int x,y,z;};
tree a[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const tree &a,const tree &b){return a.y<b.y;}
inline int lowbit(int x){return x&(-x);}
inline void add(int x,int val)
{
	for(int i=x;i<=n;i+=lowbit(i))C[i]+=val;
}
inline int query(int x)
{
	int ans=0;
	for(int i=x;i>0;i-=lowbit(i))ans+=C[i];
	return ans;
}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
int main()
{
	n=getint(),m=getint();
	for(int i=1;i<=n;i++)prt[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[i]=(tree){x,y,z};
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int k=query(a[i].y)-query(a[i].x-1);
		if(k>=a[i].z)continue;
		ans+=a[i].z-k,k=a[i].z-k;
		for(int j=getfa(a[i].y);j>=a[i].x&&k;j=getfa(j))
			add(j,1),k--,prt[j]=j-1;
	}
	printf("%d",ans);
	return 0;
}
