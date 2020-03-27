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
int x,y,k,b,len[55],f[55][55];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int DFS(int x,int sum,int flag)
{
	if(!x)return sum==k;
	if(!flag&&f[x][sum]!=-1)return f[x][sum];
	int k=flag?len[x]:b-1,ans=0;
	for(ri i=0;i<=k&&i<=1;i++)ans+=DFS(x-1,sum+i,flag&&i==k);
	if(!flag)f[x][sum]=ans;
	return ans;
	
}
int query(int num)
{
	memset(f,-1,sizeof(f));len[0]=0;
	while(num)len[++len[0]]=num%b,num/=b;
	return DFS(len[0],0,1);
}
int main()
{
	x=getint(),y=getint(),k=getint(),b=getint();
	printf("%d",query(y)-query(x-1));
	return 0;
}

