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
#include<map>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=105;
char ch[MAXN];
struct BigInt
{
	static const int SIZE=30;
	static const int Width=4;
	static const int Base=10000;
	int a[SIZE],bj;
	int &operator[](const int &x){return a[x];}
	BigInt(){memset(a,0,sizeof(a));a[0]=1,a[1]=0,bj=1;}
	inline void Input()
	{
		scanf("%s",ch);
		int len=strlen(ch);
		a[0]=(len-1)/4+1;
		if(ch[0]=='-')bj=-1;
		for(ri i=0;i<len;i++)
		{
			if(ch[i]=='-')continue;
			int pos=(len-1-i)/4+1;
			a[pos]=a[pos]*10+ch[i]-'0';
		}
	}
	inline void Output()
	{
		if(bj==-1)printf("-");
		if(a[0])printf("%d",a[a[0]]);
		for(ri i=a[0]-1;i>=1;i--)printf("%04d",a[i]);
	}
	inline friend int Compare(BigInt &a,BigInt &b)
	{
		if(a[0]>b[0])return 1;
		else if(a[0]<b[0])return -1;
		else for(ri i=a[0];i>=1;i--)
		{
			if(a[i]>b[i])return 1;
			else if(a[i]<b[i])return -1;
		}
		return 0;
	}
	inline friend BigInt operator +(BigInt &a,BigInt &b)
	{
		BigInt c;
		c[0]=max(a[0],b[0]);
		for(ri i=1;i<=c[0];i++)c[i]=a[i]+b[i];
		for(ri i=1;i<=c[0];i++)
			c[i+1]+=c[i]/Base,c[i]%=Base;
		while(c[c[0]+1]>0)c[c[0]]++,c[c[0]+1]+=c[c[0]]/Base,c[c[0]]%=Base;
		return c;
	}
	inline friend BigInt operator -(BigInt &a,BigInt &b)
	{
		BigInt c;
		int res=Compare(a,b);
		if(res==-1){c=b-a,c.bj=-1;return c;}
		else if(res==0){c[0]=1,c[1]=0;return c;}
		c[0]=max(a[0],b[0]);
		for(ri i=1;i<=c[0];i++)c[i]=a[i]-b[i];
		for(ri i=1;i<=c[0];i++)
			if(c[i]<0)c[i+1]--,c[i]+=Base;
		while(!c[c[0]]&&c[0]>1)c[0]--;
		return c;
	}
	inline friend BigInt operator *(BigInt &a,int &b)
	{
		BigInt c;c[0]=a[0];
		for(ri i=1;i<=c[0];i++)c[i]=a[i]*b;
		for(ri i=1;i<=c[0];i++)c[i+1]+=c[i]/Base,c[i]%=Base;
		while(c[c[0]+1]>0)c[c[0]]++,c[c[0]+1]+=c[c[0]]/Base,c[c[0]]%=Base;
		return c;
	}
	inline friend BigInt operator *(BigInt &a,BigInt &b)
	{
		BigInt c;c[0]=a[0]+b[0];
		for(ri i=1;i<=a[0];i++)
			for(ri j=1;j<=b[0];j++)
			{
				c[i+j-1]+=a[i]*b[j];
				c[i+j]+=c[i+j-1]/Base;
				c[i+j-1]%=Base;
			}
		for(ri i=1;i<=c[0];i++)c[i+1]+=c[i]/Base,c[i]%=Base;
		while(!c[c[0]]&&c[0]>1)c[0]--;
		return c;
	}
	inline friend BigInt operator /(BigInt &a,int &b)
	{
		BigInt c;c[0]=a[0];
		int x=0;
		for(ri i=c[0];i>=1;i--)
		{
			x=x*Base+a[i];
			c[i]=x/Base;
			x%=Base;
		}
		while(!c[c[0]]&&c[0]>1)c[0]--;
		return c;
	}
};
int main()
{	
	BigInt a,b,c;
	a.Input(),b.Input();
	c=a-b;
	c.Output();
	return 0;
}