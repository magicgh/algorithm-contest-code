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
#define ll long long
using namespace std;
int n,len,p[2500005];
char ch[500005],s[2500005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool Check(char a,char b)
{
	return (a=='#'&&b=='#')||(a=='0'&&b=='1')||(a=='1'&&b=='0');
}
int main()
{
	n=getint();
	scanf("%s",ch);
	s[len]='%';
	for(ri i=0;i<=n;i++)
	{
		s[++len]='#';
		s[++len]=ch[i];
	}
	int Max=-0x7fffffff/2,k=0;
	for(ri i=1;i<=len;i+=2)
	{
		if(Max>i)p[i]=min(p[2*k-i],Max-i);
		else p[i]=1;
		while(Check(s[i+p[i]],s[i-p[i]]))p[i]++;
		if(p[i]+i>Max)Max=p[i]+i,k=i;
	}
	int Ans=0;
	for(ri i=1;i<len;i+=2)Ans+=p[i]>>1;
	printf("%d\n",Ans);
	return 0;
}

