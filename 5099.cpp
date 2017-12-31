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
const int INF=0x7fffffff/2;
const int Mod=1000000007;
int n,m,Len,Min=INF,s;
char ch[MAXN];
ll f[2005][2005],Ans;
inline const int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=GetInt(),m=GetInt();
	scanf("%s",ch+1),Len=strlen(ch+1);
	for(ri i=1;i<=Len;i++)
	{
		if(ch[i]=='(')s++;
		else if(ch[i]==')')s--;
		Min=min(Min,s);
	}
	f[0][0]=1;
	for(ri i=1;i<=n-m;i++)
		for(ri j=0;j<=i;j++)
		{
			f[i][j]=(f[i][j]+f[i-1][j+1])%Mod;//添加右括号 
			f[i][j]=(f[i][j]+f[i-1][j-1])%Mod;//添加左括号 
		}
	for(ri i=0;i<=n-m;i++)
		for(ri j=0;j<=i;j++)
			if(j+Min>=0&&n-m-i>=j+s)//每个前缀和均不小于0且括号数不小于括号总和 
				Ans=(Ans+f[i][j]*f[n-m-i][j+s]%Mod)%Mod;
	printf("%lld\n",Ans);
	return 0;
}


