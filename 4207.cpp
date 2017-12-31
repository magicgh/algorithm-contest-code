#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
#define ri register int
using namespace std;
int len[15],f[15][10];
int n,m;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	f[0][0]=1;//0位数0开头有1解 
	for(ri i=1;i<=12;i++)//枚举m最大的位数
	for(ri j=0;j<=9;j++)//枚举第i位
	for(ri k=0;k<=9;k++)//枚举第i-1位
		if(j!=4&&(j!=6||k!=2))//排除4,62
		f[i][j]+=f[i-1][k];//递推 	 
}
void Decompose(int num)
{
	while(num)
	{
		len[++len[0]]=num%10;
		num/=10;
	}
}
int Digit_DP(int num)
{
	int ans=0;len[0]=0;
	Decompose(num);
	len[len[0]+1]=0;//设立len[i+1]的边界 
	for(ri i=len[0];i>=1;i--)//从高位向下比较
	{ 
	for(ri j=0;j<len[i];j++)//枚举[0,len[i])
		if(j!=2||len[i+1]!=6)//在初始化已经排除了4,现在只需判断62 
			ans+=f[i][j];
		if(len[i]==4||(len[i]==2&&len[i+1]==6))break;//已经出现4或62,避免多加上4X或62X的个数 
	}
	return ans;
}
int main()
{
	Init();//初始化f数组
	while(n=getint(),m=getint())
	{
		if(n==0&&m==0)break;
		printf("%d\n",Digit_DP(m+1)-Digit_DP(n));//取区间[n,m],注意一下是n~m+1 
	}
	return 0;
}