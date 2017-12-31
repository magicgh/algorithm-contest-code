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
stack<int>s;
const int MAXN=100005;
int n,ans=1,h[MAXN];
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
	for(ri i=1;i<=n;i++)h[i]=getint();
	s.push(0),s.push(h[1]);
	for(ri i=2;i<=n;i++)
	{
		while(s.top()>h[i]&&!s.empty())s.pop();
		if(h[i]>s.top())s.push(h[i]),ans++; 
	}
	printf("%d",ans);
	return 0;
}

