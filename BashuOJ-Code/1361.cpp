#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
struct series{int s,id;};
series a[100005];
bool vst[100005];
int n,cnt;
inline bool cmp(const series &a,const series &b){return a.s<b.s;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int Solve()
{
	if(a[1].s<0)return -1;//第一项都为负
	for(ri i=2;i<=n;i++)if(a[i].s==a[i-1].s)return -1;//非严格递增
	for(ri i=1,j=1;i<=n;i++)
	{
		if(!vst[i])
		{
			j=a[i].id,cnt++;//统计环的个数
			while(!vst[j])vst[j]=1,j=a[j].id;//置换
		}
	}
	return n-cnt;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint();
		a[i].s=a[i-1].s+x;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	printf("%d",Solve());
	return 0;
}
