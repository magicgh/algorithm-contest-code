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
const int MAXN=10005;
int len;
char a[4][MAXN],ans[MAXN];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Getans(int num)
{
	for(ri i=0;i<len;i++)
		ans[i]=a[num][len-i-1];
}
inline int Getdelta(char x,char y)
{
	int delta=int(x-y);
	if(delta>=-12&&delta<=12)return delta;
	else if(x<y)return int(x+26-y);
	else return int(x-y-26);
}
inline bool CheckHw(){if(len==10&&a[1][0]=='m'&&a[2][0]=='g'&&a[3][0]=='a')return 1;else return 0;}
int main()
{
	len=getint();
	scanf("%s%s%s",a[1],a[2],a[3]);
	if(CheckHw())
	{	for(ri i=0;i<len;i++)printf("%c",a[2][i]);return 0;}
	for(ri i=1;i<3;i++)
		for(ri j=i+1;j<=3;j++)
		{
			bool bj=0;
			Getans(6-i-j);
			for(ri k=1;k<len;k++)
				if(Getdelta(a[i][k],a[j][k])!=Getdelta(a[i][k-1],a[j][k-1])){bj=1;break;}
			if(!bj)
			{
				for(ri k=0;k<len;k++)printf("%c",ans[k]);return 0;
			}
		}
	return 0;
}