#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
int N,M,ans=-0x7fffffff;
struct node{int to,val;};
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
	vector<node>a[2005];
	int dist[2005];
	bool vst[2005];
	inline void AddEdge(int x,int y,int z)
	{
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
	}
	inline bool Prim(int v0)
	{
		int cnt=0;
		priority_queue<heap>q;
		vector<node>::iterator j;
		for(int i=1;i<=N;i++)dist[i]=0x7fffffff;
		dist[v0]=0;q.push((heap){v0,0});
		while(!q.empty()&&cnt<=N)
		{
			heap now=q.top();
			q.pop();
			if(vst[now.num])continue;
			ans=max(now.val,ans);	
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
	N=GetInt(),M=GetInt();
	int x,y,z;
	for(int i=1;i<=M;i++)
	{
	x=GetInt(),y=GetInt(),z=GetInt();
	tree.AddEdge(x,y,z);
	}
	if(tree.Prim(1))printf("%d",ans);
	return 0;
}