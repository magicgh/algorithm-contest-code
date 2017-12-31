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
const int MAXN=200005;
const int INF=0x7fffffff/2;
int n,L,s,Ans,x[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Solve(int cnt,int S)
{
	int ret=INF;
	priority_queue<int,vector<int>,greater<int> >q;
	if(cnt<S)return abs(x[S]-x[1]+x[n]-x[1]);
	int Limit=2*abs(x[n]-x[1])-abs(x[S+1]-x[S]);
	for(ri E=S+2;E<=n;E++)
	{
		Limit-=abs(x[E]-x[E-1]);
		q.push(2*abs(x[E]-x[E-1]));
		while(n-1+S-E<cnt)
			cnt--,Limit+=q.top(),q.pop();
		ret=min(ret,Limit);
	}
	return ret;
}
int main()
{
	n=getint(),L=getint(),s=getint();
	for(ri i=1;i<=n;i++)x[i]=getint();
	if((s!=1&&L==0)||(s!=n&&L==n-1)){printf("-1\n");return 0;}
	Ans=Solve(L,s);
	L=n-1-L,s=n-s+1;
	reverse(x+1,x+n+1);
	printf("%d\n",min(Ans,Solve(L,s)));
	return 0;
}

