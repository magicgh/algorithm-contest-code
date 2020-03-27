#include<iostream>
#include<cstdio>
#include<list>
#include<queue>
using namespace std;
const int INF=0x7fffffff;
struct node
{
	int to,val,num;
};
struct que
{
	int to,val,num;
	bool operator <(que t)
	const{return val>t.val;}
};
list<node>a[501];
list<node>::iterator k;
priority_queue<que>q;
int n,m,ans=0,cnt=0;
int dist[501]={0},prt[501]={0},Max[501][501]={0};
bool vst[501]={0},Hash[10001]={0};
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
inline void Prim(int v0)
{
	for(int i=1;i<=n;i++)dist[i]=INF;
	dist[v0]=0;prt[v0]=0;q.push((que){v0,0,0});
	while(!q.empty()&&cnt<n)
	{
		que now=q.top();
		q.pop();
		if(!vst[now.to])
		{
		for(int i=1;i<=n;i++)
		if(vst[i])Max[now.to][i]=Max[i][now.to]=max(Max[i][prt[now.to]],dist[now.to]);
		vst[now.to]=1;
		cnt++;
		Hash[now.num]=1;
		ans+=dist[now.to];
		for(k=a[now.to].begin();k!=a[now.to].end();++k)
		{
			if(!vst[k->to]&&dist[k->to]>k->val)
			{
				dist[k->to]=k->val;
				q.push((que){k->to,dist[k->to],k->num});
				prt[k->to]=now.to;
			}
		}
	}
	}
    return;
}
int main(){
	n=GetInt();
	m=GetInt();
	int x,y,z;
	for(int i=1;i<=m;i++)
	{
		x=GetInt();
		y=GetInt();
		z=GetInt();
		a[x].push_back((node){y,z,i});
		a[y].push_back((node){x,z,i});
	}
	Prim(1);
	int Min=INF,tmp;
	for(int i=1;i<=n;i++)
	{
		for(k=a[i].begin();k!=a[i].end();++k)
		{
			if(!Hash[k->num])
			{
			tmp=ans+k->val-Max[i][k->to];
			Min=Min>tmp?tmp:Min;
		    }
		}
	}
	printf("%d",Min);
	return 0;
}