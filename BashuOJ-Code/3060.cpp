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
const int MAXN=2005;
int n,b[MAXN],Ans[10005]={1,1};
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Multi(int a[],int k)
{
	for(ri i=1;i<=a[0];i++)a[i]*=k;
	for(ri i=1;i<=a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
	}
	while(a[a[0]+1]>0)
	{
		a[0]++;
		a[a[0]+1]+=a[a[0]]/10;
		a[a[0]]%=10;
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)b[i]=getint();
	for(ri i=1;i<n;i++)
		if(b[i+1]-b[i]<0||b[i+1]-b[i]>2||b[i]>i){printf("0\n");return 0;}
	if(b[n]!=n){printf("0\n");return 0;}
	for(ri i=2;i<=n;i++)
	{
		if(b[i]-b[i-1]==1)Multi(Ans,(2*i-1-2*b[i-1]));
		else if(b[i]-b[i-1]==2)Multi(Ans,(i-1-b[i-1])*(i-1-b[i-1]));
	}
	for(ri i=Ans[0];i>=1;i--)printf("%d",Ans[i]);
	return 0;
}

