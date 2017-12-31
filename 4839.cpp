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
const int MAXN=100005;
const int MAXK=20;
const int MAXS=(1<<16)+5;
int a[MAXK],b[MAXN],f[MAXS],g[MAXS];
//f[i]:i使用状态最多能付到的账单编号
//g[i]:f[i]最大时的最多余额 
int k,n,Ans=-1;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Binary(int l,int r,int x)
{
	int st=l;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(b[mid]-b[st-1]>x)r=mid-1;
		else l=mid+1;
	}
	return r;
}
int main()
{
	k=getint(),n=getint();
	for(ri i=1;i<=k;i++)
		g[0]+=(a[i]=getint());
	for(ri i=1;i<=n;i++)
		b[i]=b[i-1]+getint();
	for(int S=0;S<(1<<k);S++)
	{
		for(ri j=1;j<=k;j++)
			if(!(S&((1<<(j-1)))))
			{
				int Farid=Binary(f[S]+1,n,a[j]),p=(S|(1<<(j-1)));
				if(Farid>f[p]||(Farid==f[p]&&g[S]-a[j]>=g[p]))f[p]=Farid,g[p]=g[S]-a[j];
				if(f[p]==n&&g[p]>=Ans)Ans=g[p];
			} 
	}
	printf("%d\n",Ans);
	return 0;
}

