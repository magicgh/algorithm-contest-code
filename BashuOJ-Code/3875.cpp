#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
const int MAXN=100005;
vector<int>	a[MAXN];
int N,M,cnt=0;
int val[MAXN],root[MAXN],dep[MAXN],ch[2000005][2],s[2000005],p[MAXN][50];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
void AddEdge(int x,int y)
{
	a[x].push_back(y);
	a[y].push_back(x);
}
void ST()
{
	for(int j=1;j<=int(log2(N));j++)
	for(int i=1;i<=N;i++)
		if(p[i][j-1]!=-1)p[i][j]=p[p[i][j-1]][j-1];
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b])swap(a,b);
	int k=int(log2(dep[a]));
	for(int i=k;i>=0;i--)if(dep[a]-(1<<i)>=dep[b])a=p[a][i];
	if(a==b)return a;
	for(int i=k;i>=0;i--)if(p[a][i]!=-1&&p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
int Build(int now,int val)
{
	int next,order;
	order=next=++cnt;
	for(int i=15;i>=0;i--)
	{
	ch[next][0]=ch[now][0];
	ch[next][1]=ch[now][1];
	s[next]=s[now]+1;
	int t=(val>>i)&1;
	now=ch[now][t];
	ch[next][t]=++cnt;
	next=ch[next][t];
	}
	s[next]=s[now]+1;
	return order;
}
int Query(int x,int y,int z,int v)
{
	int ans=0;
	for(int i=15;i>=0;i--)
	{
		int t=(v>>i)&1;
		if(s[ch[x][!t]]+s[ch[y][!t]]>2*s[ch[z][!t]])
		{
			x=ch[x][!t],y=ch[y][!t],z=ch[z][!t];
			ans+=(1<<i);
		}
		else x=ch[x][t],y=ch[y][t],z=ch[z][t];
	}
	return ans;
}
void DFS(int x,int fa,int d)
{
	dep[x]=d;
	root[x]=Build(root[p[x][0]],val[x]);
	vector<int>::iterator it;
	for(it=a[x].begin();it!=a[x].end();++it)if(*it!=fa)p[*it][0]=x,DFS(*it,x,d+1);
}
int main(){
	while(~scanf("%d%d",&N,&M))
	{
	cnt=0;
	memset(val,0,sizeof(val));
	memset(p,0,sizeof(p));
	memset(root,0,sizeof(root));
	memset(s,0,sizeof(s));
	for(int i=1;i<=N;i++)a[i].clear();
	for(int i=1;i<=N;i++)val[i]=GetInt();
	for(int i=1;i<N;i++)AddEdge(GetInt(),GetInt());
	DFS(1,0,1);
	ST();
	for(int i=1;i<=M;i++)
	{
		int x=GetInt(),y=GetInt(),z=GetInt(),lca=LCA(x,y);
		printf("%d\n",max(Query(root[x],root[y],root[lca],z),val[lca]^z));
	}
}
	return 0;
}