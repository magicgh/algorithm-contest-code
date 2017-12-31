#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=100005;
struct node{int to,val;};
struct path{int x,y,z;};
vector<node>a[MAXN];
path b[MAXN];
int n,cnt,Deg[MAXN],Edge[MAXN];
bool vst[MAXN];
inline bool cmp(const path &a,const path &b){return a.z>b.z;}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int Limit)
{
	vst[u]=1;cnt++;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(vst[it->to]||it->val<Limit)continue;
		DFS(it->to,Limit);
	 } 
}
inline bool Check(int Limit)
{
	queue<int>q;
	for(ri i=1;i<=n;i++)
		Deg[i]=0,vst[i]=0;
	for(ri i=1;i<=n;i++)
	{
		if(b[i].z>=Limit)
			Deg[b[i].x]++,Deg[b[i].y]++;
		else break;
	}
	for(ri i=1;i<=n;i++)
	{
		if(!Deg[i])return 0;
		if(Deg[i]==1)q.push(i);
	}
	while(!q.empty())//处理树的情况 
	{
		int now=q.front();q.pop();
		if(vst[now])continue;
		vector<node>::iterator it1;
		for(it1=a[now].begin();it1!=a[now].end();++it1)
		{
			if(vst[it1->to]||it1->val<Limit)continue;
			vst[now]=vst[it1->to]=1;//匹配
			vector<node>::iterator it2;
			for(it2=a[it1->to].begin();it2!=a[it1->to].end();++it2)
			{
				if(vst[it2->to]||it2->val<Limit)continue;
				Deg[it2->to]--;
				if(Deg[it2->to]==1)q.push(it2->to);
				if(!Deg[it2->to])return 0;	
			}
			break;
		}
	}
	for(ri i=1;i<=n;i++)
	{
		if(!vst[i])
		{
			cnt=0;
			DFS(i,Limit);
		}
		if(cnt&1)return 0;
	} 
	return 1;
}
void Binary()
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(Edge[mid]))l=mid+1;
		else r=mid-1;
	}
	if(!Edge[r])printf("no answer\n");
	else printf("%d\n",Edge[r]);
}
int main()
{
	n=getint();
	if(n&1){printf("no answer\n");return 0;}
	for(ri i=1;i<=n;i++)
	{
		int u=getint(),v=getint(),w=getint();
		b[i]=(path){u,v,w};
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w});
		Edge[i]=w;
	}
	sort(b+1,b+n+1,cmp);
	sort(Edge+1,Edge+n+1);
	Binary();
	return 0;
}


