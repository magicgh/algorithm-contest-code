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
const int MAXN=600005;
int n,a[MAXN];
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
	for(ri i=1;i<=n;i++)a[i]=a[n+i]=getint();
	ri i=1,j=2,k=0;
	while(i<=n&&j<=n&&k<=n)
	{
		if(a[i+k]==a[j+k])k++;
		else
		{
			if(a[i+k]<a[j+k])j=j+k+1;
			else i=i+k+1;
			k=0;
		}
		if(i==j)j=i+1;
	}
	for(ri pos=0;pos<n;pos++)printf("%d ",a[pos+i]);
	return 0;
}

