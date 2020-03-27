#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=5005;
int n,a[MAXN],b[MAXN];
int t1,t2,q1,q2,ans;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Check()
{
	if(b[t2]>a[q2])
	{
		ans++;
		t2--,q2--;
		return;
	}
	if(b[t1]>a[q1])
	{
		t1++,q1++;
		ans++;
		return;
	}
	if(b[t1]<a[q2])
	    ans--;
	if(b[t1]>a[q2])
	    ans++;
	t1++,q2--;
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)a[i]=getint();
	for(ri i=1;i<=n;i++)b[i]=getint();
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	t1=q1=1,t2=q2=n;
	for(ri i=1;i<=n;i++)Check();
	printf("%d",ans);
	return 0;
}
