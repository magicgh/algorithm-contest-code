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
int n,m,t,a[MAXN],q,u,v,sq;
double P;
deque<int>Q[3];
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
	n=getint(),m=getint(),q=getint(),u=getint(),v=getint(),t=getint();
	P=(double)u/(double)v;
	for(ri i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1,greater<int>());
	for(ri i=1;i<=n;i++)
		Q[0].push_back(a[i]);
	for(ri i=1;i<=m;i++)
	{
		int Max=-INF,Maxid=0;
		for(ri p=0;p<3;p++)
			if(!Q[p].empty()&&Max<Q[p].front())Max=Q[Maxid=p].front();
		Q[Maxid].pop_front();
		Max+=sq,sq+=q;
		int x1=(int)(P*Max)-sq,x2=Max-(int)(P*Max)-sq;	
		Q[1].push_back(x1),Q[2].push_back(x2);
		if(!(i%t))printf("%d ",Max);
	}
	printf("\n");
	for(ri i=1;i<=m+n;i++)
	{
		int Max=-INF,Maxid=0;
		for(ri p=0;p<3;p++)
			if(!Q[p].empty()&&Max<Q[p].front())Max=Q[Maxid=p].front();
		Q[Maxid].pop_front();
		if(!(i%t))printf("%d ",Max+sq);
	}
	return 0;
}

