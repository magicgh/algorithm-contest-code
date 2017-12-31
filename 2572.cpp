#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
#include<list>
using namespace std;
struct node
{
	int to,val;
};
struct que
{
	int to,val;
};
bool operator <(que a,que b)
{
	return a.val>b.val;
}
list<node>a[10005];
int N,M,ANS;
int dist[10005],prt[10005];
bool vst[10005];
priority_queue<que>q;
inline void Prim(int v0)
{
	for(int i=1;i<=N;i++)dist[i]=0x7fffffff;
	dist[v0]=0;prt[v0]=v0;q.push((que){v0,0});
	while(!q.empty())
	{
		que now=q.top();
		q.pop();
		if(!vst[now.to])
		{
		vst[now.to]=1;
		ANS+=now.val;
		list<node>::iterator k;
		for(k=a[now.to].begin();k!=a[now.to].end();++k)
		{
			if(!vst[k->to]&&dist[k->to]>k->val)
			{
				dist[k->to]=k->val;
				prt[k->to]=now.to;
				q.push((que){k->to,dist[k->to]});
			}
		}
	}
	}
	
}
int main(){
	cin>>N>>M;
	memset(dist,0,sizeof(dist));
	memset(prt,0,sizeof(prt));
	memset(vst,0,sizeof(vst));
	int x,y,z;
	for(int i=1;i<=M;i++)
	{
		cin>>x>>y>>z;
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
	}
	Prim(1);
	cout<<ANS;
	return 0;
}
