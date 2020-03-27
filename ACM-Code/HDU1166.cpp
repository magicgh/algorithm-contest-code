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
int T,M,N,C[50005],cnt;
inline int Lowbit(int x){return x&(-x);}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Modify(int x,int d)
{
	for(ri i=x;i<=N;i+=Lowbit(i))C[i]+=d;
}
inline int Sum(int x)
{
	int Ans=0;
	for(ri i=x;i>0;i-=Lowbit(i))Ans+=C[i];
	return Ans;
} 
int main(){
	T=GetInt(); 
	while(T--)
	{
		memset(C,0,sizeof(C));
		N=GetInt();
		for(ri i=1;i<=N;i++)Modify(i,GetInt());
		printf("Case %d:\n",++cnt);
		while(true)
		{
			string op;cin>>op;
			if(op=="End")break;
			int x=GetInt(),y=GetInt();
			if(op=="Add")Modify(x,y);
			if(op=="Sub")Modify(x,-y);
			if(op=="Query")printf("%d\n",Sum(y)-Sum(x-1));
		} 
	}
	return 0;
}