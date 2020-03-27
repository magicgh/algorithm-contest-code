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
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int l,s,t,m,a[105],f[30005],cnt;
bool iss[30005];
int main()
{
	l=getint();
	s=getint(),t=getint(),m=getint();
	for(int i=1;i<=m;i++)a[i]=getint();
	if(s!=t)
	{
		sort(a+1,a+m+1);a[0]=0;
		for(int i=1;i<=m;i++)
		{
			if(a[i]-a[i-1]>=90)
			{
				int d=a[i]-a[i-1]-90;
				for(int j=i;j<=m;j++)a[j]-=d;
			}
			iss[a[i]]=1;
		}
		for(int i=1;i<=a[m]+t;i++)f[i]=110;
		f[0]=0;
		for(int i=t;i<=a[m]+t;i++)
		for(int j=i-t;j<=i-s;j++)
		{
			if(iss[i]&&f[j]+1<f[i])f[i]=f[j]+1;
			if(!iss[i]&&f[j]<f[i])f[i]=f[j];
		}
		int Ans=110;
		for(int i=a[m];i<=a[m]+t;i++)Ans=min(Ans,f[i]);
		printf("%d",Ans); 
	}
	else 
	{
		for(int i=1;i<=m;i++)if(a[i]%s==0)cnt++;
		printf("%d",cnt);
	}
	return 0;
}

