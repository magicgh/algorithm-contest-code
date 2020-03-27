#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<deque>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=1005;
const int INF=0x7fffffff;
struct node{int to,val;};
vector<node>a[MAXN];
int n,p,k,l=INF,r=-INF,ans=INF,dist[MAXN];
bool ext[MAXN];
inline int max(const int &x,const int &y){return x>y?x:y;}
inline int min(const int &x,const int &y){return x<y?x:y;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
bool SPFA(int limit)
{
	deque<int>q;
	for(ri i=1;i<=n;i++)dist[i]=INF,ext[i]=0;
	q.push_back(1),dist[1]=0,ext[1]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front(),ext[now]=0;
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			int delta=(it->val>limit);
			if(dist[it->to]>dist[now]+delta)
			{
				dist[it->to]=dist[now]+delta;
				if(!ext[it->to])
				{
					if(!q.empty()&&dist[q.front()]>dist[it->to])q.push_front(it->to);
					else q.push_back(it->to);
					ext[it->to]=1;
				}
			}
		} 
	}
	return dist[n]<=k;
}
int main()
{
	n=getint(),p=getint(),k=getint();
	for(ri i=1;i<=p;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
		l=min(l,z),r=max(r,z);
	}
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(SPFA(mid))ans=min(ans,mid),r=mid-1;
		else l=mid+1;	
	}
	if(!r)printf("0");
	else printf("%d",ans==INF?-1:ans);
	return 0;
}

