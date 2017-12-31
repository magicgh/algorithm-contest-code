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
const int MAXN=1000005;
int n,a[MAXN],q[MAXN],L[MAXN],R[MAXN];
ll Ans;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Maintain_Left()
{
	int head=1,tail=0;
	for(ri i=1;i<=n;i++)
	{
		while(head<=tail&&a[q[tail]]>=a[i])tail--;
			L[i]=i-q[tail]-1;
			q[++tail]=i;
	}
}
void Maintain_Right()
{
	int head=1,tail=0;
	q[0]=n+1;
	for(ri i=n;i>=1;i--)
	{
		while(head<=tail&&a[q[tail]]>=a[i])tail--;
			R[i]=q[tail]-i-1;
			q[++tail]=i;
	}
}
int main()
{
	while(~(n=getint()))
	{
		Ans=0;
		for(ri i=1;i<=n;i++)a[i]=getint();
		Maintain_Left();
		Maintain_Right();
		for(ri i=1;i<=n;i++)
			Ans=max(Ans,(ll)a[i]*(ll)(L[i]+R[i]+1));
		printf("%lld\n",Ans);
	} 
	return 0;
}

