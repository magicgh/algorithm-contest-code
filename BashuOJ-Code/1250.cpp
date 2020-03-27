#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
#include<list>
#include<climits>
using namespace std;
int ans=0;
int N,M;
struct node
{
	int to,val;
};
struct heap
{
	int num,val;
	bool operator <(const heap &rhs)const{return val>rhs.val;}
};
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
struct MST
{
	list<node>a[305];
	list<node>::iterator j;
	double dist[305];
	bool vst[305];
	inline void AddEdge(int x,int y,double z)
	{
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
		return;
	}
	inline bool Prim(int v0)
	{
	int cnt=0;
	priority_queue<heap>q;
	list<node>::iterator j;
	for(int i=1;i<=N;i++)dist[i]=INT_MAX;
	dist[v0]=0;q.push((heap){v0,0});
	while(!q.empty()&&cnt<=N)
	{
		heap now=q.top();
		q.pop();

		if(vst[now.num])continue;
		ans+=now.val;	
		vst[now.num]=1;
		cnt++;
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
	N=GetInt();
	M=GetInt();
	int x,y,z;
	for(int i=1;i<=M;i++)
	{
	x=GetInt();
	y=GetInt();
	z=GetInt();
	tree.AddEdge(x,y,z);
	}
	if(tree.Prim(1))printf("%d",int(ans));
	else printf("wtf");
	return 0;
}