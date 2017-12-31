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
const int MAXN=200005;
stack<int>s;
double X[MAXN],R[MAXN];
int n;
inline int getint()
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
	for(ri i=1;i<=n;i++)
		scanf("%lf%lf",&X[i],&R[i]);
	for(ri i=1;i<=n;i++)
	{
		while(!s.empty())
		{
			R[i]=min(R[i],(X[i]-X[s.top()])*(X[i]-X[s.top()])/(4*R[s.top()]));
			if(R[s.top()]<R[i])s.pop();
			else break;
		}
		s.push(i);
		printf("%.3lf\n",R[i]);
	}
	return 0;
}
