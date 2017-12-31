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
struct Ave{double a,b,c,d;};
Ave path[MAXN];
int n,m,tmpn;
double tmp[MAXN],e;
priority_queue<double,vector<double>,greater<double> >q;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double Fac(int yid)
{
	double x=e,y=tmp[yid],Ans=0;
	for(ri i=1;i<=n;i++)
		Ans+=(abs(path[i].a*x+path[i].b*y+path[i].c)/sqrt(path[i].a*path[i].a+path[i].b*path[i].b))*path[i].d;
	return Ans;
}
inline void AddLine()
{
	tmpn=0;
	for(ri i=1;i<=n;i++)
		if(path[i].b)tmp[++tmpn]=(-path[i].c-path[i].a*e)/path[i].b;
	sort(tmp+1,tmp+tmpn+1);
	int l=1,r=tmpn;
	while(l<=r)
	{
		int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
		if(Fac(lmid)<Fac(rmid))r=rmid-1;
		else l=lmid+1;
	}
	q.push(Fac(r));
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
		scanf("%lf%lf%lf%lf",&path[i].a,&path[i].b,&path[i].c,&path[i].d);
	m=getint();
	for(ri i=1;i<=m;i++)
	{
		int Type=getint();
		if(Type==0)printf("%.4lf\n",q.top());
		if(Type==1)
		{
			scanf("%lf",&e);
			AddLine();
		}
		if(Type==2)q.pop();
	}
	return 0;
}