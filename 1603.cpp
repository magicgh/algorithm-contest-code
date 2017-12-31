#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=360005;
int n,a[1005],b[1005],sum,Max,f[12005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint();
	for(int i=1;i<=n;i++)
	{
		a[i]=getint(),b[i]=getint();
		sum+=(a[i]+b[i]),Max+=max(a[i],b[i]); 
	}
	memset(f,INF,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
		for(int j=Max;j>=0;j--)
		{
			int ans=INF;
			if(j-a[i]>=0)ans=f[j-a[i]];
			if(j-b[i]>=0)ans=min(ans,f[j-b[i]]+1);
			f[j]=ans;
		}
	for(int i=sum>>1;i>0;i--)
	{
		int ans=min(f[i],f[sum-i]);
		if(ans<INF){printf("%d",ans);return 0;}
	}
	return 0;
}

