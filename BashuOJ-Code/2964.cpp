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
using namespace std;
priority_queue<int,vector<int>,greater<int>>q;
struct hw{int lim,val;};
hw a[1000005];
int n,cnt,ans;
inline bool cmp(const hw &x,const hw &y){return (x.lim==y.lim&&x.val>y.val)||x.lim<y.lim;}
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
	int n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),y=getint();
		a[i]=(hw){x,y};
	}
	sort(a+1,a+n+1,cmp);
	for(ri i=1;i<=n;i++)
	{
		if(cnt<a[i].lim)q.push(a[i].val),cnt++;
		else
		{
			int top=q.top();
			if(top<a[i].val)q.pop(),q.push(a[i].val);
		}
	}
	while(!q.empty())ans+=q.top(),q.pop();
	printf("%d",ans);
	return 0;
}
