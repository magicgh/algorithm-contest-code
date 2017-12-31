 #include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
using namespace std;
const int MAXN=1005;
const int INF=0x7fffffff;
int n,m,Min=INF,Minx,north[MAXN],south[MAXN],sn[MAXN],ss[MAXN];
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
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
		{
			char ch;
			while(ch=getchar())if(ch=='N'||ch=='S')break;
			if(ch=='N')north[i]++;if(ch=='S')south[i]++;
		}
	for(ri i=n;i>=1;i--)sn[i]=sn[i+1]+north[i],ss[i]=ss[i+1]+south[i];
	for(ri i=n+1;i>=1;i--)
	{
		int temp=sn[i]+(ss[1]-ss[i]);
		if(temp<=Min)Min=temp,Minx=i-1;
	}
	printf("%d",Minx);
	return 0;
}

