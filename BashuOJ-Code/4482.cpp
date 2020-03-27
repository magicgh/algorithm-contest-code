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
int p[1001005];
int T,n,m;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(int x)
{
	int cnt1=0,cnt2=0;
	while(x)
	{
		int t=x%3;
		if(t==1)cnt1++;
		else if(t==2)cnt2++;
		x/=3;
	}
	return cnt1==cnt2;
}
void Init()
{
	const int Limit=1000700;
	for(ri i=1;i<=Limit;i++)
		if(Check(i))p[++p[0]]=i;
}
void ST1()
{
	int tot=0;
	for(ri i=1;i<=p[0];i++)
	{
		if(p[i]>=n)printf("%d ",p[i]),tot++;
		if(tot>=m)break;
	}
	printf("\n");
}
int main()
{

	Init(),T=getint();
	for(ri i=1;i<=T;i++)
	{
		n=getint(),m=getint();
		ST1();
	}
	return 0;
}

