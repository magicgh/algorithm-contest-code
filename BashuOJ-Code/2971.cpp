#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
const int INF=0x7fffffff;
int n,l1[155],l2[155],d[155];
bool f[155][155*300];
int Mx=-INF,Mi=INF;
inline int getint()
{
	int num=0,bj=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')bj=(ch=='-'||bj==-1)?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9')num=num*10+ch-'0',ch=getchar();
	return num*bj;
}
int main()
{
	n=getint();
	for(int i=1;i<=n;i++)
	{
		l1[i]=getint(),l2[i]=getint();
		Mx+=max(l1[i],l2[i]);
		Mi+=min(l1[i],l2[i]);
		d[i]=abs(l1[i]-l2[i]);
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=Mx-Mi+2;j++)
		{
			f[i][j]=f[i][j]||f[i-1][j+d[i]];
			if(j>=d[i])f[i][j]=f[i][j]||f[i-1][j-d[i]];
			else f[i][j]=f[i][j]||f[i-1][d[i]-j];
		}
	}
	for(int i=0;i<=Mx-Mi+2;i++)if(f[n][i]){printf("%d",i);break;}
	return 0;
}