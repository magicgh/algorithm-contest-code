#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<bitset>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=2005;
bitset<MAXN>a[MAXN];
int n,Ans;
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
		a[i][i]=1;
		for(ri j=1;j<=n;j++)
		{
			while(ch=getchar())
				if(ch=='0'||ch=='1')break;
			if(ch=='1')a[i][j]=1;
		}
	}
	for(ri k=1;k<=n;k++)
		for(ri i=1;i<=n;i++)
			if(a[i][k])a[i]|=a[k];//Floyed
	for(ri i=1;i<=n;i++)
		Ans+=a[i].count();
	printf("%d\n",Ans);
	return 0;
}
