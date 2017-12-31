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
const int MAXN=1000005;
struct node{int h,p;}a[MAXN];
stack<int>s1,s2;
int n,goal,ans[MAXN];
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
	n=getint();
	for(ri i=1;i<=n;i++)a[i]=(node){getint(),getint()};
	for(ri i=1;i<=n;i++)
	{
		while(!s1.empty()&&a[s1.top()].h<a[i].h)ans[i]+=a[s1.top()].p,s1.pop();
		s1.push(i);
	}
	for(ri i=n;i>=1;i--)
	{
		while(!s2.empty()&&a[s2.top()].h<a[i].h)ans[i]+=a[s2.top()].p,s2.pop();
		s2.push(i);
	}
	for(ri i=1;i<=n;i++)goal=max(goal,ans[i]);
	printf("%d",goal);
	return 0;
}
