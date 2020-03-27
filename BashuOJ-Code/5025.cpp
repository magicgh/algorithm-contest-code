#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int INF=0x7fffffff;
const int MAXM=805;
const int MAXN=10005;
struct que{int pos;ll val;};
int n,m,t,p,q,z;
ll f[MAXM][MAXN],Ans=-INF,c[MAXN],d[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
struct Queue
{
	deque<que>q;
	inline void push(int pos,ll val)
	{
		while(!q.empty()&&q.back().val<val)q.pop_back();
		q.push_back((que){pos,val});	
	} 
	inline void pop(int L)
	{
		while(!q.empty()&&q.front().pos<L)q.pop_front();
	}
	inline void Init(){q.clear();}
	inline ll front(){return q.empty()?-INF:q.front().val;}//维护一个单调递减的队列 
};
Queue Q[2];
inline void Insert(int i,int j)
{
	if(j==0||d[j]%t)Q[0].push(j,f[i][j]);//没有t因子情况的队列(或从长安出发,没有前序) 
	else Q[1].push(j,f[i][j]); //含有t因子情况的队列
}
void DP()
{
	for(ri i=0;i<=m;i++)
		for(ri j=0;j<=n;j++)f[i][j]=-INF;
	f[0][0]=0;//第j里路经历第i个磨难的最大值
	for(ri i=1;i<=m;i++)//磨难 
	{
		Q[0].Init(),Q[1].Init();
		for(ri j=p;j<min(n,i*p);j++)//把上个阶段且与这个阶段无关的全部情况放入队列 
			Insert(i-1,j-p); 
		for(ri j=min(n,i*p);j<=n;j++)
		{
			Insert(i-1,j-p);//把与这个阶段有关的上一阶段的全部情况放入队列
			Q[0].pop(j-q),Q[1].pop(j-q);//维护下界
			if(d[j]%t)//分有无t因子的情况进行转移 
				f[i][j]=max(f[i][j],max(Q[0].front(),Q[1].front())+c[j]);
			else f[i][j]=max(f[i][j],max(Q[0].front(),Q[1].front()-z)+c[j]);
		}
	}
	for(ri i=0;i<=m;i++)
		for(ri j=0;j<=n;j++)Ans=max(f[i][j],Ans);
	printf("%lld\n",Ans);
}
int main()
{
	n=getint(),m=getint(),t=getll(),p=getint(),q=getint(),z=getll();
	for(ri i=1;i<=n;i++)c[i]=getll();
	for(ri i=1;i<=n;i++)d[i]=getll();
	DP();
	return 0;
}


