#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=20005;
const int INF=0x7fffffff;
struct node{int to,val;};
vector<node>a[MAXN];
bool flag;
int n,m,Max=-INF,Min=INF,vst[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void DFS(int u,int col,int k)
{
	vst[u]=col;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(it->val<=k)continue;//小于答案直接在一个监狱，只考虑大于答案的才划分 
		else if(!vst[it->to])DFS(it->to,3-col,k);
		else if(vst[it->to]!=3-col){flag=1;return;}
	}
}
inline bool Check(int k)
{
	memset(vst,0,sizeof(vst));flag=0;
	for(ri i=1;i<=n;i++)
	{
		if(!vst[i])
		{
			DFS(i,1,k);
			if(flag)return 0;
		}
	}
	return 1;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint(),z=getint();
		a[x].push_back((node){y,z});
		a[y].push_back((node){x,z});
		Max=max(Max,z),Min=min(Min,z);
	}
	int l=(Min==Max)?0:Min,r=Max;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}


