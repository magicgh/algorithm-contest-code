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
struct path{int x,y;double z;};
struct node{int to;double val;};
path b[MAXN];
vector<node>a[MAXN];
double Ans,Min=1e100,sum[MAXN];
int prt[MAXN],Deg[MAXN];
int n,m,Mink,k;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const path &a,const path &b){return a.z<b.z;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
void kruskal()
{
	for(ri i=1;i<=n;i++)prt[i]=i;
	for(ri i=1;i<=m;i++)
	{
		int f1=getfa(b[i].x),f2=getfa(b[i].y);
		if(f1!=f2)
		{
			prt[f2]=f1;
			Ans+=b[i].z;
			a[b[i].x].push_back((node){b[i].y,b[i].z});
			a[b[i].y].push_back((node){b[i].x,b[i].z});
			Deg[b[i].x]++,Deg[b[i].y]++;
			if(++k==n-1)break;
		}
	}
}
void Tree_DP(int u)
{
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->to==prt[u])continue;
		prt[it->to]=u;
		Tree_DP(it->to);
		sum[u]+=sum[it->to]+it->val;
	}
}
int main()
{
	n=getint(),m=getint();
	int x,y;double z;
	for(ri i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&x,&y,&z);
		b[i]=(path){x,y,z};
	}
	sort(b+1,b+m+1,cmp);
	kruskal();
	memset(prt,0,sizeof(prt));
	Tree_DP(1);
	for(int u=1;u<=n;u++)
	{
		if(Deg[u]<=1)continue;
		double avg=Ans/(double)Deg[u],value=0;
		vector<node>::iterator it;
		for(it=a[u].begin();it!=a[u].end();++it)
		{
			if(it->to==prt[u])continue;
			value+=(sum[it->to]+it->val-avg)*(sum[it->to]+it->val-avg);
		}
		if(u!=1)value+=(Ans-sum[u]-avg)*(Ans-sum[u]-avg);
		if(Min>value)Min=value,Mink=u;
	}
	printf("%d\n",Mink);
	return 0;
}

