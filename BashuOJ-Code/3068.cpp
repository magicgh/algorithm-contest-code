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
using namespace std;
const int MAXN=200005;
struct node{int to,val;};
vector<node>a[MAXN]; 
int n,m,ans,dist[MAXN],d1[MAXN],d2[MAXN],d3[MAXN],prt[MAXN],Max[MAXN][20],Min[MAXN][20]; 
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFSx1(int u)
{
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]==it->to)continue;
		prt[it->to]=u;
		dist[it->to]=dist[u]+it->val;
		DFSx1(it->to);
		if(d1[it->to]+it->val>d1[u])
			d2[u]=d1[u],d1[u]=d1[it->to]+it->val;
		else if(d1[it->to]+it->val>d2[u])
			d2[u]=d1[it->to]+it->val;
	}
}
void DFSx2(int u)
{
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]==it->to)continue;
		if(d1[u]-d1[it->to]==it->val)
			d3[it->to]=max(d2[u],d3[u])+it->val;
		else d3[it->to]=max(d1[u],d3[u])+it->val;
		DFSx2(it->to);	
	} 
}
void ST()
{
	for(ri i=1;i<=n;i++)Max[i][0]=Min[i][0]=max(d1[i],d3[i]);
	for(ri j=1;j<=(int)log2(n);j++)
		for(ri i=1;i+(1<<j)-1<=n;i++)
		{
			Max[i][j]=max(Max[i][j-1],Max[i+(1<<(j-1))][j-1]);
			Min[i][j]=min(Min[i][j-1],Min[i+(1<<(j-1))][j-1]);
		}
}
inline int RMQ(int l,int r)
{
	int k=log2(r-l+1);
	return max(Max[l][k],Max[r-(1<<k)+1][k])-min(Min[l][k],Min[r-(1<<k)+1][k]);
}
int Binary(int k)
{
	int l=k,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(RMQ(k,mid)<=m)l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=2;i<=n;i++)
	{
		int fa=getint(),val=getint();
		a[fa].push_back((node){i,val});
		a[i].push_back((node){fa,val});
	}
	DFSx1(1),DFSx2(1);
	ST();
	for(ri i=1;i<n;i++)
		ans=max(Binary(i)-i+1,ans);
	printf("%d\n",ans); 
	return 0;
}
