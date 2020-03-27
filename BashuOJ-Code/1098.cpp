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
const int MAXN=50005;
const int INF=0x7fffffff;
struct node{int to,val;};
struct path{int x,y,z;};
vector<node>a[MAXN];
vector<int>p;
int base[]={0,1,2,6,24,120};
int n,m,K,spe[10],tot=INF,dist[10][MAXN];
bool ext[MAXN],Hash[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void SPFA(int t,int v0)
{
	deque<int>q;
	for(ri i=1;i<=n;i++)dist[t][i]=INF,ext[i]=0;
	dist[t][v0]=0,q.push_back(v0),ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front();ext[now]=0;
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(dist[t][now]+it->val<dist[t][it->to])
			{
				dist[t][it->to]=dist[t][now]+it->val;
				if(!ext[it->to])
				{
					if(!q.empty()&&dist[t][q.front()]<dist[t][it->to])q.push_back(it->to);
					else q.push_front(it->to);
					ext[it->to]=1;	
				}	
			}	
		} 
	}
}
int main()
{
	n=getint(),m=getint(),K=5;
	for(ri i=1;i<=K;i++)spe[i]=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
	}
	for(ri i=1;i<=K;i++)SPFA(i,spe[i]);
	for(int i=1;i<=K;i++)p.push_back(i),Hash[spe[i]]=1;
	for(ri i=1;i<=base[K];i++)
	{
		int ans=0;
		for(ri k=1;k<K;k++)ans+=dist[p[k-1]][spe[p[k]]];
		int sum=ans;
		sum+=dist[p[0]][1];
		tot=min(sum,tot);
		next_permutation(p.begin(),p.end());
	}
	printf("%d",tot);
	return 0;
}
