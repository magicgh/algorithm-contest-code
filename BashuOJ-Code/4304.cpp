#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int M,N;
int main(){
	while(scanf("%d%d",&N,&M))
	{
		if(N==0&&M==0)return 0;
		int ans=GetInt();
		for(int i=2;i<=N;i++)
		{
		int t=GetInt();
		ans=ans/gcd(ans,t)*t;
		}
		printf("%d\n",ans-M);
	}
	return 0;
}