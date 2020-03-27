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
const int INF=0x7fffffff/2;
struct Point{int x,y;};
struct heap
{
	int id; ll val;
	bool operator <(const heap &rhs)
	const{return val>rhs.val;}
};
priority_queue<heap>q;
Point a[MAXN];
int n,m,p,tot,pos,cnt;
int Num[MAXN<<1],L[MAXN<<1],R[MAXN<<1],Deg[MAXN<<1];
ll dist[MAXN<<1],Ans;
bool bj[MAXN<<1];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint(),p=getint();
	Num[++tot]=1,Num[++tot]=n;
	for(ri i=1;i<=m;i++)
	{
		int x=getint(),y=getint();
		a[i]=(Point){x,y};
		Num[++tot]=x,Num[++tot]=y;	
	}
	sort(Num+1,Num+tot+1);
	cnt=unique(Num+1,Num+tot+1)-(Num+1);
	Deg[1]=Deg[cnt]=1;
	for(ri i=1;i<=m;i++)
	{
		a[i].x=lower_bound(Num+1,Num+cnt+1,a[i].x)-Num;
		a[i].y=lower_bound(Num+1,Num+cnt+1,a[i].y)-Num;
		Deg[a[i].x]++,Deg[a[i].y]++;
	}
	int last=0;tot=0;
	for(ri i=1;i<=cnt;i++)
	{
		if(Deg[i]&1)
		{
			if(last)dist[++tot]=Num[i]-Num[last];
			last=i;
		}
	}
	for(ri i=1;i<=tot;i++)
	{
		q.push((heap){i,dist[i]});
		L[i]=i-1,R[i]=i+1;
	}
	int num=(tot-1)/2-p;
	for(ri i=1;i<=num;i++)
	{
		while(bj[q.top().id])q.pop();
		Ans+=q.top().val,pos=q.top().id,q.pop();
		if(!L[pos])
		{
			bj[R[pos]]=1;
			L[R[R[pos]]]=0;
			continue;
		}
		else if(R[pos]>tot)
		{
			bj[L[pos]]=1;
			R[L[L[pos]]]=tot+1;
			continue;
		}
		int l=L[pos],r=R[pos];
		bj[l]=bj[r]=1;		
		dist[pos]=dist[l]+dist[r]-dist[pos];
		q.push((heap){pos,dist[pos]});
		L[pos]=L[l],R[pos]=R[r];
		R[L[l]]=L[R[r]]=pos;
	}
	printf("%lld\n",Ans+n-1);
	return 0;
}
