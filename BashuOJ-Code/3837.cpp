#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;
const int MAXN=5005;
const int INF=0x7fffffff;
const double eps=1e-3;
struct edge{int x,y,z;};
struct node{int to;double val;};
edge path[MAXN];
vector<node>a[MAXN];
int L,P,VM=0;
int joy[MAXN],used[MAXN];
double dist[MAXN];
bool ext[MAXN];
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
inline void BuildGraph(double k)
{
	for(int i=0;i<=P;i++)a[i].clear();
	for(int i=1;i<=P;i++)
		a[path[i].x].push_back((node){path[i].y,double(k*path[i].z)-double(joy[path[i].y])});
}
inline bool SPFA(int v0)
{	
	memset(used,0,sizeof(used));
	memset(ext,0,sizeof(ext));
	deque<int>q;
	for(int i=1;i<=L;i++)dist[i]=INF;
	q.push_front(v0);dist[v0]=0;ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();q.pop_front();
		ext[now]=0;
		vector<node>::iterator it;
		for(it=a[now].begin();it!=a[now].end();++it)
		{
			if(dist[it->to]>dist[now]+it->val)
			{
				dist[it->to]=dist[now]+it->val;
				if(!ext[it->to])
				{
					if(++used[it->to]>=L)return 0;
					if(!q.empty()&&dist[q.front()]>dist[it->to])q.push_front(it->to);
					else q.push_back(it->to);
					ext[it->to]=1;
				}
			}
	}
}
	return 1;
}
int main(){
	L=GetInt();
	P=GetInt();
	for(int i=1;i<=L;i++)joy[i]=GetInt(),VM+=joy[i];
	for(int i=1;i<=P;i++)
	{
		int x=GetInt(),y=GetInt(),z=GetInt();
		path[i]=(edge){x,y,z};
	}
	double l=0,r=VM;
	while(r-l>eps)
	{
		double mid=(l+r)/2;
		BuildGraph(mid);
		if(!SPFA(1))l=mid;
		else r=mid;
	}
	printf("%.2lf",l);
	return 0;
}	