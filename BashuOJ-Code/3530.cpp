#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<climits>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=1015;
struct King{int L,R;ll Mul,Coin;};
King a[MAXN];
int n,Ji[100005]={1,1},c[100005],Max[100005]={1,0};
inline bool cmp(const King &a,const King &b){return (a.Mul<b.Mul);}
inline int getint()
{
	int num=0,bj=1;	
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool BigIntcmp(int *a,int *b)
{
	if(a[0]>b[0])return 1;
	if(a[0]<b[0])return 0;
	for(ri i=a[0];i>=1;i--)
		return a[i]>b[i];
}
inline void Multi(int *a,int b)
{
	for(ri i=1;i<=a[0];i++)a[i]*=b;
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
inline void Div(int *a,int b)
{
	int d=0;
	memset(c,0,sizeof(c));
	for(ri i=a[0];i>=1;i--)
	{
		d=d*10+a[i];
		c[i]=d/b;
		d%=b;
	}
	c[0]=a[0];
	while(c[0]>1&&c[c[0]]==0)c[0]--;
}
int main()
{
	n=getint();
	a[1].L=getint(),a[1].R=getint();
	for(ri i=2;i<=n+1;i++)
	{
		int x=getint(),y=getint();
		a[i]=(King){x,y,x*y};
	}
	sort(a+2,a+n+2,cmp);
	for(ri i=2;i<=n+1;i++)
	{
		Multi(Ji,a[i-1].L);
		Div(Ji,a[i].R);
		if(BigIntcmp(c,Max))memmove(Max,c,sizeof(c));
	}
	for(ri i=Max[0];i>=1;i--)printf("%d",Max[i]);
	return 0;
}

