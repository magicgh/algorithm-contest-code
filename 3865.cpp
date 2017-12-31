#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100005;
const int SegM=3000005;
vector<int>edge[MAXN*2];
int N,M,NN,Ans=0;
int a[MAXN],b[MAXN],depth[MAXN],p[MAXN][25],root[SegM];
inline void swap(int &x1,int &x2){x1^=x2,x2^=x1,x1^=x2;}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline int PutInt(int x)
{
	 if(x<0) putchar('-'),x=-x;
     if(x>9) PutInt(x/10);
     putchar(x%10+'0');
}
inline void AddEdge(int x,int y)
{
	edge[x].push_back(y);
	edge[y].push_back(x);
	return;
}
struct SegTree
{
	int L[SegM],R[SegM],s[SegM],cnt;
	inline int Insert(int l,int r,int now,int val)
	{
		int next=++cnt;
		s[next]=s[now]+1;
		L[next]=L[now],R[next]=R[now];
		if(l==r)return next;
		int mid=(l+r)>>1;
		if(val<=mid)L[next]=Insert(l,mid,L[now],val);
		else R[next]=Insert(mid+1,r,R[now],val);
		return next;
	}
	inline int Query(int l,int r,int x,int y,int fa,int grdfa,int k)
	{
		if(l==r)return l;
		int mid=(l+r)>>1;
		int order=s[L[y]]+s[L[x]]-s[L[fa]]-s[L[grdfa]];
		if(order>=k)return Query(l,mid,L[x],L[y],L[fa],L[grdfa],k);
		else return Query(mid+1,r,R[x],R[y],R[fa],R[grdfa],k-order);
	}
}tr;
void ST()
{
	for(int i=1;i<=N;i++)
	for(int j=1;j<=17;j++)p[i][j]=-1;
	for(int j=1;j<=17;j++)
	for(int i=1;i<=N;i++)
		if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
int LCA(int a,int b)
{
	if(depth[a]<depth[b])swap(a,b);
	for(int i=17;i>=0;i--)if(depth[a]-(1<<i)>=depth[b])a=p[a][i];
	if(a==b)return a;
	for(int i=17;i>=0;i--)if(depth[a]-(1<<i)>=0&&p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
void DFS(int x,int fa,int dep)
{
	depth[x]=dep;
	p[x][0]=fa;
	root[x]=tr.Insert(1,NN,root[fa],a[x]);
	vector<int>::iterator it;
	for(it=edge[x].begin();it!=edge[x].end();++it)
		if(*it!=fa)DFS(*it,x,dep+1);
}
int main(){
	int x,y,z;
	N=GetInt();
	M=GetInt();
	for(int i=1;i<=N;i++)a[i]=b[i]=GetInt();
	sort(b+1,b+N+1);
	NN=unique(b+1,b+N+1)-(b+1);
	for(int i=1;i<=N;i++)a[i]=lower_bound(b+1,b+NN+1,a[i])-b;
	for(int i=1;i<N;i++)AddEdge(GetInt(),GetInt());
	DFS(1,0,1);
	ST();
	for(int i=1;i<=M;i++)
	{
		x=GetInt(),y=GetInt(),z=GetInt();
		x=x^Ans;
		int lca=LCA(x,y);
		Ans=b[tr.Query(1,NN,root[x],root[y],root[lca],root[p[lca][0]],z)];
		printf("%d\n",Ans);
	}
	return 0;
}