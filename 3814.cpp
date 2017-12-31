#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=10005;
bool vst[MAXN];
int p[MAXN],Phi[MAXN];
int m;
void Init()
{
	int Limit=10000;
	for(int i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i,Phi[i]=i-1;
		for(ri j=1;j<=p[0]&&i*p[j]<=Limit;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0){Phi[i*p[j]]=Phi[i]*p[j];break;}
			Phi[i*p[j]]=Phi[i]*Phi[p[j]];
		}
	}
}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
inline bool Check(int a)
{
	int value=1;
	for(int d=1;d<=Phi[m];d++)
	{
		value=value*a%m;
		if(value==1)
		{
			if(d==Phi[m])return 1;
			else return 0;
		}
	}
	return 0;
}
int st,ed;
int main()
{
	m=getint();
	if(m==1){printf("1\n");return 0;}
	Init();
	bool flag=0;
	for(int a=1;a<=m;a++)
	{
		if(gcd(a,m)!=1)continue;
		if(Check(a))
			flag=1,printf("%d\n",a);
	}
	if(!flag)printf("-1\n");
	return 0;
}
