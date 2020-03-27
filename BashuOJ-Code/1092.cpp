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
const int MAXN=3005;
const int Mod=160883,p=9110;
char a[MAXN],b[MAXN];
int n,Hash[MAXN];
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int Check(int l,int r,char *s)
{
	if(l+1==r)return 1;
	int cnt=0,j=l,sum=1,Hash[MAXN];
	Hash[0]=0;
	for(ri i=l;i<=r;i++)
	{
		cnt+=(s[i]=='1'?1:-1);
		if(!cnt)//l至i为一棵子树 
		{
			Hash[++Hash[0]]=Check(j+1,i-1,s);
			j=i+1;
		}
	}
	sort(Hash+1,Hash+Hash[0]+1);
	for(ri i=1;i<=Hash[0];i++)
		sum=((ll)sum*p^Hash[i])%Mod;
	return sum;
}
int main()
{
	n=getint();
	while(n--)
	{
		scanf("%s%s",a+1,b+1);
		printf((Check(1,strlen(a+1),a)==Check(1,strlen(b+1),b))?"same\n":"different\n");
	}
	return 0;
}

