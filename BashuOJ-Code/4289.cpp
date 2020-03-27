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
int Mod[6]={0,11261,19997,22877,21893,14843};
char ch[10005];
int n,m,a[6][105],Ans[6][30005],Base[6][105],ans[1000005];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Input(int x)
{
	scanf("%s",ch+1);
	int bj=1,len=strlen(ch+1);
	for(ri i=1;i<=5;i++)
		if(ch[1]!='-')a[i][x]=ch[1]-'0';
		else a[i][x]=0,bj=-1;
	for(ri i=1;i<=5;i++)
	{
		for(ri j=2;j<=len;j++)
		a[i][x]=(a[i][x]*10+ch[j]-'0')%Mod[i];
		a[i][x]*=bj;
	}
}
inline int Calc(int t)
{
	int sum=0;
	for(ri i=0;i<=n;i++)
		sum=((sum+Base[t][i]*a[t][i])%Mod[t]+Mod[t])%Mod[t];
	return sum;
}
inline bool Check(int x)
{
	for(ri i=1;i<=5;i++)
		if(Ans[i][x%Mod[i]]!=0)return 0;
	return 1;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=0;i<=n;i++)Input(i);
	for(ri i=1;i<=5;i++)
		for(ri x=1;x<Mod[i];x++)
		{
			Base[i][0]=1;
			for(ri j=1;j<=n;j++)
				Base[i][j]=(Base[i][j-1]*x)%Mod[i];
			Ans[i][x]=Calc(i);
		}
	for(ri i=1;i<=m;i++)
		if(Check(i))ans[++ans[0]]=i;
	printf("%d\n",ans[0]);
	for(ri i=1;i<=ans[0];i++)
		printf("%d\n",ans[i]);
	return 0;
}