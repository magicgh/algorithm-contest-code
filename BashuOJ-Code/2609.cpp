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
const int INF=0x7fffffff/2;
int t;
bool f[1000005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	for(ri i=1;i<=9;i++)f[i]=1;
	for(ri i=10;i<=1000000;i++)
	{
		int tmp=i,Max=-INF,Min=INF;
		while(tmp)
		{
			int x=tmp%10;
			tmp/=10;
			if(x)Max=max(x,Max),Min=min(x,Min);
		}
		f[i]=!(f[i-Max]&&f[i-Min]);
	}
}
int main()
{
	Init();
	t=getint();
	while(t--)
		printf(f[getint()]?"YES\n":"NO\n");
	return 0;
}

