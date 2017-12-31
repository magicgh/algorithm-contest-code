#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=100005;
const ll Mod=1000000007;
const int W=30;
const ll INF=1e18;
int n,cnt=1,ch[MAXN*30][2];
ll Ans,ret=1,Min,Count,Cnt[MAXN*30];
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll Pow(ll a,ll b)
{
	ll ret=1,base=a;
	while(b)
	{
		if(b&1)ret=(ret*base)%Mod;
		base=(base*base)%Mod;
		b>>=1;
	}
	return ret;
}
inline void Insert(int x)
{
	int u=1;Cnt[u]++;
	for(ri i=W;i>=1;i--)
	{
		int Bit=(((1<<(i-1))&x)>0);//第i位的值
		if(!ch[u][Bit])ch[u][Bit]=++cnt;
		u=ch[u][Bit];
		Cnt[u]++;//统计该节点经过图中点的个数 
	}
}
void DFS(int Bit,int L,int R,ll Val)
{
	if(!Cnt[L]||!Cnt[R])return;//一端为空的情况
	if(!Bit)//最低位统计答案 
	{
		if(Val<Min)
		{
			Min=Val;
			Count=Cnt[L]*Cnt[R]%Mod;
		}
		else if(Val==Min)
			Count=(Count+Cnt[L]*Cnt[R]%Mod)%Mod;
		return;
	}
	//向下递归 
	if(Cnt[ch[L][0]])
	{
		if(Cnt[ch[R][0]])DFS(Bit-1,ch[L][0],ch[R][0],Val);
		else DFS(Bit-1,ch[L][0],ch[R][1],Val|(1<<(Bit-1)));
	}
	if(Cnt[ch[L][1]])
	{
		if(Cnt[ch[R][1]])DFS(Bit-1,ch[L][1],ch[R][1],Val);
		else DFS(Bit-1,ch[L][1],ch[R][0],Val|(1<<(Bit-1)));
	}
	
} 
inline void Solve(int u,int Bit)
{
	if(Cnt[u]<=1)return;//不能构成一条边
	if(!Bit)//计算到最低位 
	{
		ret=ret*Pow(Cnt[u],Cnt[u]-2)%Mod;//运用Cayley定理 
		return; 
	} 
	Solve(ch[u][0],Bit-1);
	Solve(ch[u][1],Bit-1);//递归左右两棵树
	if(Cnt[ch[u][0]]&&Cnt[ch[u][1]])
	{
		Min=INF,Count=0;
		DFS(Bit-1,ch[u][0],ch[u][1],1<<(Bit-1));//从当前节点的左右儿子开始向下暴力统计
		Ans+=Min,ret=ret*Count%Mod; 
	}
}
int main()
{
	n=GetInt();
	for(ri i=1;i<=n;i++)Insert(GetInt());
	Solve(1,W);
	printf("%lld\n%lld\n",Ans,ret);
	return 0;
}


