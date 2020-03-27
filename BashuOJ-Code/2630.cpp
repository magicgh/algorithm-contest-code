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
struct seg{int v,t;};
seg a[2005];
int n,m,x=1,y=1,ans;
inline bool cmp(const seg &a,const seg &b){return a.v>b.v;}
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
	n=getint(),m=getint();
	for(ri i=1;i<n;i++)a[i]=(seg){getint(),1};
	for(ri i=1;i<m;i++)a[i+n-1]=(seg){getint(),2};
	sort(a+1,a+n+m-1,cmp);
	for(ri i=1;i<=n+m-2;i++)
	{
		if(a[i].t==1)ans+=a[i].v*y,x++;
		else ans+=a[i].v*x,y++;
	}
	printf("%d",ans);
	return 0;
}

