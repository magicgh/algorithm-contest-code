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
const int MAXN=1000005;
struct Figure{int two,five;};
Figure a[MAXN];
int T,Ans;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	const int Limit=1000000;
	for(ri i=1;i<=Limit;i++)
	{
		int num=i;
		while(num%5==0)num/=5,a[i].five++;
		while(num%2==0)num/=2,a[i].two++;
	}
	for(ri i=1;i<=Limit;i++)
	{
		a[i].five+=a[i-1].five;
		a[i].two+=a[i-1].two;
	}
}
int main()
{
	Init();
	T=getint();
	while(T--)
	{
		int m=getint(),n=getint();
		Ans=min(a[m].two-a[n].two-a[m-n].two,a[m].five-a[n].five-a[m-n].five);
		printf("%d\n",Ans);
	}
	return 0;
}

