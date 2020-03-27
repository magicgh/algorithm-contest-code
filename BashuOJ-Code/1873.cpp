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
int a,b,n,len[12],f[12][105];
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
inline int DFS(int x,int sum,int flag)
{
	if(!x)return (sum==0);
	if(!flag&&f[x][sum]!=-1)return f[x][sum];
	int k=flag?len[x]:9,ans=0;
	for(ri i=0;i<=k;i++)ans+=DFS(x-1,(sum+i)%n,flag&&i==k);
	if(!flag)f[x][sum]=ans;
	return ans;
	
}
int query(int num)
{
	memset(len,0,sizeof(len));
	memset(f,-1,sizeof(f));
	while(num)len[++len[0]]=num%10,num/=10;
	len[len[0]+1]=-1;
	return DFS(len[0],0,1);
}
int main()
{
	while(~(a=getint()))
	{
		b=getint(),n=getint();
		printf("%d\n",query(b)-query(a-1));
	}
	return 0;
}

