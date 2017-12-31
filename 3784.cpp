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
priority_queue<int,vector<int>,greater<int> >q;
ll Ans;
int n;
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
	n=getint();
	char ch;
	for(ri i=1;i<=n;i++)
	{
		while(ch=getchar())
			if(ch=='c'||ch=='e')break;
		if(ch=='c')q.push(getint());
		if(ch=='e')
		{
			int Limit=getint();
			if(i!=n)while(!q.empty()&&q.size()>=(unsigned int)Limit)q.pop();
			if(i==n)if(q.size()<(unsigned int)Limit){printf("-1\n");return 0;}
		}
	}
	while(!q.empty())
		Ans+=(ll)q.top(),q.pop();
	printf("%lld\n",Ans);
	return 0;
}