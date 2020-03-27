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
int a,b,f[12][10],len[12];
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
void Prepare()
{
	for(ri i=0;i<=9;i++)f[1][i]=1;
	for(ri i=2;i<=10;i++)
	for(ri j=0;j<=9;j++)
	for(ri k=0;k<=9;k++)if(j<=k)f[i][j]+=f[i-1][k];
}
int DP(int num)
{
	int ans=0;
	memset(len,0,sizeof(len));
	if(num==0)return 1;
	while(num)
	{
		len[++len[0]]=num%10;
		num/=10;
	}
	for(ri i=len[0];i>=1;i--)
	{
		for(ri j=0;j<len[i];j++)if(len[i+1]<=j)ans+=f[i][j];
		if(len[i+1]>len[i])break;
		if(i==1)ans+=(len[1]>=len[2]);
	}
	return ans;
}
int main()
{
	Prepare();
	while(~(a=getint()))
	{
		b=getint();
		printf("%d\n",DP(b)-DP(a-1));
	}
	return 0;
}

