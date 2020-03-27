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
char s[20005];
int n;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint();
	while(n--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(ri i=1;i<=len;i++)s[len+i]=s[i];
		int i=1,j=2,k=0;
		while(i<=len&&j<=len&&k<=len)
		{
			if(s[i+k]==s[j+k])k++;
			else
			{
				if(s[i+k]<s[j+k])j=j+k+1;
				else i=i+k+1;
				k=0;
			}
			if(i==j)j=i+1;
		}
		printf("%d\n",i);
	}
	return 0;
}

