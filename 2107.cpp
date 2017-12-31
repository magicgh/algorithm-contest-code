#include<iostream>
#include<cstdio>
#include<list>
#include<queue>
using namespace std;
const int INF=0x7fffffff;
struct node
{
	int to,val;
};
struct que
{
	int to,val;
	bool operator <(que t)
	const{return val>t.val;}
};
list<node>a[501];
list<node>::iterator k;
priority_queue<que>q;
int n,ans=0,cnt=0;
int dist[501]={0};
bool vst[501]={0};
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
	dist[v0]=0;q.push((que){v0,0});
	while(!q.empty()&&cnt<n)
	{
		que now=q.top();
		q.pop();
		if(!vst[now.to])
		{
		vst[now.to]=1;
		cnt++;
		ans+=dist[now.to];
		for(k=a[now.to].begin();k!=a[now.to].end();++k)
		{
			if(!vst[k->to]&&dist[k->to]>k->val)
			{
				dist[k->to]=k->val;
				q.push((que){k->to,dist[k->to]});
			}
		}
	}
	}
    return;
}
int main(){
	n=GetInt();
	int x;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)
	{
		x=GetInt();
		a[i].push_back((node){j,x});
	}
	Prim(1);
	printf("%d",ans);
	return 0;
}