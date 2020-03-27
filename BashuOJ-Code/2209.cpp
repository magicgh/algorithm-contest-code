#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<deque>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
deque<int>q;
int x,n,m,ans=-0x7fffffff,s[200005];
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
	for(ri i=1;i<=n;i++)x=getint(),s[i]=s[i-1]+x;
	for(ri i=1;i<=n;i++)
	{
		while(!q.empty()&&q.front()<i-m)q.pop_front();
		while(!q.empty()&&s[q.back()]>=s[i-1])q.pop_back();
		q.push_back(i-1);
		ans=max(ans,s[i]-s[q.front()]);
	}
	printf("%d",ans);
	return 0;
}
