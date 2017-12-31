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
const int INF=0x7fffffff;
struct heap
{
	int id;ll val;
	bool operator <(const heap &rhs)
	const{return val>rhs.val;}
};
int n,k,pos;
ll dist[MAXN],len[MAXN],Ans;
priority_queue<heap>q;
int L[MAXN],R[MAXN];
bool bj[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),k=getint();
	for(ri i=1;i<=n;i++)scanf("%lld",&len[i]);
	for(ri i=1;i<n;i++)
	{
		dist[i]=len[i+1]-len[i];
		q.push((heap){i,dist[i]});
	}
	for(ri i=1;i<n;i++)L[i]=i-1,R[i]=i+1;
	L[1]=0,R[n-1]=0,dist[0]=INF;
	for(ri i=1;i<=k;i++)
	{
		while(bj[q.top().id])q.pop();
		Ans+=q.top().val,pos=q.top().id,q.pop();
		int l=L[pos],r=R[pos];
		bj[l]=bj[r]=1;
		dist[pos]=dist[l]+dist[r]-dist[pos];
		q.push((heap){pos,dist[pos]});
		L[pos]=L[l],R[pos]=R[r];
		R[L[l]]=L[R[r]]=pos;
	}
	printf("%lld",Ans); 
	return 0;
}

