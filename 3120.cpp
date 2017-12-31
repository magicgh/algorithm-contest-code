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
const int MAXN=70005;
struct Ant{char dir;int pos;};
Ant a[MAXN];
int l,t,n;
inline bool cmp(const Ant &a,const Ant &b){return a.pos<b.pos;}
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
	l=getint(),t=getint(),n=getint();
	for(ri i=1;i<=n;i++)
	{
		scanf("%d%s",&a[i].pos,&a[i].dir);
		int Now=abs(a[i].pos+((a[i].dir=='L')?-t:t));
		a[i].pos=((Now/l)&1)?l-Now%l:Now%l;
	}
	sort(a+1,a+n+1,cmp);
	for(ri i=1;i<=n;i++)
		printf("%d ",a[i].pos);
	return 0;
}


