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
const int INF=99999999;
int n,k,rp[105],ch[105][2],f[105][105];
bool vst[105][105];
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
int Tree_DP(int i,int j)
{
	int Max=-INF;
	if(i==0&&j!=0)return -INF;//没分完 
	if(j==0)return 0;//分完了
	if(j==1)return rp[i];//只剩一份
	if(vst[i][j])return f[i][j];//记忆化搜索 
	for(ri t=0;t<=j-1;t++)Max=max(Max,Tree_DP(ch[i][0],t)+Tree_DP(ch[i][1],j-t-1)+rp[i]);
	f[i][j]=Max,vst[i][j]=1;
	return f[i][j];
} 
int main()
{	
	n=getint(),k=getint();
	for(ri i=2;i<=n;i++)rp[i]=getint();
	for(ri i=1;i<=n;i++)ch[i][0]=getint(),ch[i][1]=getint();
	Tree_DP(1,k+1);printf("%d",f[1][k+1]);
	return 0;
}
