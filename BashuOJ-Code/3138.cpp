#include<iostream>
#include<cstdio>
#include<cstring>
#include<list>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
struct node
{
	int to,val;
};
list<node>a[1005];
vector<int>dist[1005];
bool vst[1005]={0},ext[1005]={0};
int M,N;
inline int GetInt()
{
	char c=getchar();
	int num=0;
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
inline bool SPFA(int v0)
{
	list<node>::iterator i;
	queue<int>q;
	for(int i=0;i<=N;i++)dist[v0].push_back(INT_MAX);
	dist[v0][v0]=0;q.push(v0);ext[v0]=1;
	while(!q.empty())
	{
		int now=q.front();
		q.pop();ext[now]=0;
		for(i=a[now].begin();i!=a[now].end();++i)
		{
			if(dist[v0][i->to]>dist[v0][now]+i->val)
			{
			dist[v0][i->to]=dist[v0][now]+i->val;
			vst[i->to]++;
			if(vst[i->to]>=N)return 0;
			if(!ext[i->to])q.push(i->to),ext[i->to]=1;
		    }
		}
	}
	return 1;
}
int main(){
	N=GetInt();
	M=GetInt();
	int x,y,z;
	for(int i=1;i<=M;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		a[x].push_back((node){y,z});
	}
	for(int i=1;i<=N;i++)SPFA(i);
	int Min=INT_MAX;
	for(int i=1;i<N;i++)
	   for(int j=i+1;j<=N;j++)
	      	if(dist[i][j]!=INT_MAX&&dist[j][i]!=INT_MAX)Min=min(Min,dist[i][j]+dist[j][i]);
	printf("%d",Min);
	return 0;
}
