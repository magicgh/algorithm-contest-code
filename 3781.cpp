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
const int MAXA=300005;
const int MAXB=205;
char s1[MAXA],s2[MAXB];
ll pos,cnt,f[MAXB];
int l1,l2;
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	scanf("%s%s",s1+1,s2+1);
	l1=strlen(s1+1),l2=strlen(s2+1);
	for(ri i=1;i<=l1;i++)
	{
		f[0]=i;
		for(ri j=l2;j>=1;j--)
		{
			if(s1[i]==s2[j])f[j]=f[j-1];
			if(j==l2&&f[j])cnt+=(f[j]-pos)*(ll)(l1-i+1),pos=f[j];
		}
	}
	printf("%lld\n",cnt);
	return 0;
}


