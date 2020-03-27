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
priority_queue<int,vector<int>,greater<int> >Small;
priority_queue<int>Big;
int n,x;
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
	n=getint(),x=getint();
	Big.push(x);printf("%d\n",x);
	n=(n&1)?n:n-1;
	for(ri i=2;i<=n;i+=2)
	{
		x=getint();
		if(x>Big.top())Small.push(x);
		else Big.push(x);
		x=getint();
		if(x>Big.top())Small.push(x);
		else Big.push(x);
		int delta=Big.size()-Small.size()-1;
		if(delta>0)
		{
			Small.push(Big.top());
			Big.pop();
		}
		if(delta<0)
		{
			Big.push(Small.top());
			Small.pop();
		}
		printf("%d\n",Big.top());
	}
	return 0;
}
