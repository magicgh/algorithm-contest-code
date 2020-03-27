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
string s;
int n,lev,f[32],cnt,sum,num;
inline void GetLev(int x)
{
	memset(f,0,sizeof(f));
	cnt=1,f[0]=f[1]=1,f[2]=2;	
	while(x>0)
	{
		cnt++,sum=0;
		for(ri i=0;i<cnt;i++)sum+=f[i]*f[cnt-i-1];
		f[cnt]=sum,x-=sum;
	}
	num=x+f[cnt];
}
inline string Solve(int x,int y)
{
	int a=0,b=y,c,l,r;
	string s1,s2;
	if(x==0)return "";
	else if(x==1)return "(X)";
	else
	{
		while(a<x-1&&b-f[a]*f[x-1-a]>0)b-=f[a]*f[x-1-a],a++;
		c=x-1-a;
		l=(b-1)/f[c]+1,r=(b-1)%f[c]+1;
		s1=Solve(a,l),s2=Solve(c,r);
		return "("+s1+"X"+s2+")";
	}
}
int main()
{
	while(~scanf("%d",&n))
	{
		if(n==0)break;
		GetLev(n-1);
		s=Solve(cnt,num);
		for(ri i=1;i<s.length()-1;i++)printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}

