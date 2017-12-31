#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
double S;
int N,M;
double ans=0;
struct node{int to;double val;};
struct heap
{
	int num;double val;
	bool operator <(const heap &rhs)const{return val>rhs.val;}
};
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct MST
{
	vector<node>a[100005];
	double dist[100005];
	bool vst[100005];
	inline void AddEdge(int x,int y,double z)
	{
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
	}
	inline bool Prim(int v0)
	{
		int cnt=0;
		priority_queue<heap>q;
		vector<node>::iterator j;
		for(int i=1;i<=N;i++)dist[i]=1e100;
		dist[v0]=0;q.push((heap){v0,0});
		while(!q.empty()&&cnt<=N)
		{
			heap now=q.top();
			q.pop();
			if(vst[now.num])continue;
			ans+=now.val;
			vst[now.num]=1;
			cnt++;
			vector<node>::iterator j;
			for(j=a[now.num].begin();j!=a[now.num].end();++j)
			{ 
				if(!vst[j->to]&&dist[j->to]>j->val)
				{
					dist[j->to]=j->val;
					q.push((heap){j->to,dist[j->to]});
				}
			}
		}
		if(cnt==N)return 1;
		else return 0;
	}
};
MST tree;
int main(){
	scanf("%lf",&S);N=getint();
	int x,y;double z;
	while(~scanf("%d%d%lf",&x,&y,&z))tree.AddEdge(x,y,z);
	if(tree.Prim(1))
	{
		
		if(ans<S)printf("%.2lf",ans);
		else printf("Impossible");
	}
	else printf("Impossible");	
	return 0;
}