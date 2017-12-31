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
const int MAXN=100005;
struct node{int to,val;};
vector<node>a[MAXN];
int Deg[MAXN],K[MAXN];
double f[MAXN],p[MAXN];
int n,m;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Topsort()
{
	queue<int>q;
	q.push(1),p[1]=1	;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vector<node>::iterator it;
		for(it=a[u].begin();it!=a[u].end();++it)
		{
			f[it->to]+=(f[u]+p[u]*(double)it->val)/(double)K[u];
			p[it->to]+=p[u]/(double)K[u]; 
			Deg[it->to]--;
			if(!Deg[it->to])q.push(it->to);
		}
	}
	printf("%.2lf\n",f[n]);
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=m;i++)
	{
		int u=getint(),v=getint(),w=getint();
		a[u].push_back((node){v,w});
		Deg[v]++,K[u]++;
	}
	Topsort();
	return 0;
}

