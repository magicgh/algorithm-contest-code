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
char Input[110005],s[220005];
int p[220005];
int main()
{
	while(~scanf("%s",Input))
	{
		int len=strlen(Input),slen=0;
		s[slen]='%';
		for(ri i=0;i<=len;i++)
		{
			s[++slen]='#';
			s[++slen]=Input[i];
		}
		int Max=-0x7fffffff/2,k=0;
		for(ri i=0;i<=slen;i++)
		{
			if(Max>i)p[i]=min(p[2*k-i],Max-i);
			else p[i]=1;
			while(s[i+p[i]]==s[i-p[i]])p[i]++;
			if(p[i]+i>Max)Max=p[i]+i,k=i;
		}
		int Ans=-0x7fffffff;
		for(ri i=1;i<=slen;i++)Ans=max(Ans,p[i]-1);
		printf("%d\n",Ans);
	}
	return 0;
}

