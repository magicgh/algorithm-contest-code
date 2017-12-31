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
using namespace std;
const double eps=1e-15;
int n,m;
double ans,a[17][17];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{ 
		if(c==EOF)return EOF;
		bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	} 
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{	
	while(~(n=getint()))
	{
		m=getint();
		for(ri i=1;i<=m;i++)
		{
			int x=getint(),y=getint();
			a[x][y]--,a[y][x]--;
			a[x][x]++,a[y][y]++;
		}
		ans=1;		
		for(int i=1;i<n;i++)
		{
			int j=i;	
			while(j<n&&fabs(a[j][i])<eps)j++;//找到一个非0的 
			if(j==n){ans=0;break;}
			ans*=a[i][i];
			for(int k=i;k<n;k++)swap(a[i][k],a[j][k]);//交换
			for(int j=i+1;j<n;j++)
			{
				double t=a[j][i]/a[i][i];//作商求倍数
				for(int k=i+1;k<n;k++)a[j][k]-=a[i][k]*t;
			}
		}
		printf("%d\n",int(ans+0.5));
	}
	return 0;
}

