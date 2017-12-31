#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=805;
const int INF=0x7fffffff/2;
char ch[5];
int n,m,q,a[MAXN][MAXN],s[MAXN][MAXN];
int Max[MAXN][MAXN][11],Min[MAXN][MAXN][11];
namespace FastIO
{
	const int L=1<<15;
	char buf[L],*S,*T;
	inline char getchar()
	{
		if(S==T)
		{
			T=(S=buf)+fread(buf,1,L,stdin);
			if(S==T)return EOF;
		}
		return *S++;
	}
	inline const int GetInt()
	{
		ri num=0,bj=1;
		register char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	void GetString(char *s)
	{
		register char c=getchar();
		while(!(33<=c&&c<=126))c=getchar();
		while(33<=c&&c<=126)*s++=c,c=getchar();
		*s=0;
	}
	inline void PutInt(int x)
	{
	     if(x<0)putchar('-'),x=-x;
	     if(x>9)PutInt(x/10);
	     putchar(x%10+'0');
	}
}
using FastIO::GetInt;
using FastIO::PutInt;
using FastIO::GetString;
inline int max(const int &a,const int &b){return a>b?a:b;}
inline int min(const int &a,const int &b){return a<b?a:b;}
inline void ST()
{
	int k=log2(max(n,m));
		for(ri p=1;p<=k;p++)
			for(ri i=1;i+(1<<p)-1<=n;i++)
				for(ri j=1;j+(1<<p)-1<=m;j++)//拆成四块正方形维护 
				{
					int t=(1<<(p-1));
					Max[i][j][p]=max(Max[i][j][p-1],max(Max[i+t][j][p-1],max(Max[i][j+t][p-1],Max[i+t][j+t][p-1])));
					Min[i][j][p]=min(Min[i][j][p-1],min(Min[i+t][j][p-1],min(Min[i][j+t][p-1],Min[i+t][j+t][p-1])));
				}
}
inline int Sum(int ax,int ay,int bx,int by)
{
	return s[bx][by]-s[ax-1][by]-s[bx][ay-1]+s[ax-1][ay-1];
}
inline int Query_Max(int ax,int ay,int bx,int by)
{
	int ret=-INF,k=log2(min(bx-ax+1,by-ay+1)),t=(1<<k);
	for(ri i=ax;i+t-1<=bx;i+=t)
	{
		for(ri j=ay;j+t-1<=by;j+=t)
			ret=max(ret,Max[i][j][k]);
		ret=max(ret,Max[i][by-t+1][k]);
	}
	for(ri j=ay;j+t-1<=by;j+=t)
		ret=max(ret,Max[bx-t+1][j][k]);
	ret=max(ret,Max[bx-t+1][by-t+1][k]);
	return ret;
}
inline int Query_Min(int ax,int ay,int bx,int by)
{
	int ret=INF,k=log2(min(bx-ax+1,by-ay+1)),t=(1<<k);
	for(ri i=ax;i+t-1<=bx;i+=t)
	{
		for(ri j=ay;j+t-1<=by;j+=t)
			ret=min(ret,Min[i][j][k]);
		ret=min(ret,Min[i][by-t+1][k]);
	}
	for(ri j=ay;j+t-1<=by;j+=t)
		ret=min(ret,Min[bx-t+1][j][k]);
	ret=min(ret,Min[bx-t+1][by-t+1][k]);
	return ret;
}
int main()
{
	n=GetInt(),m=GetInt();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			Max[i][j][0]=Min[i][j][0]=a[i][j]=GetInt();
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<=m;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	ST();
	q=GetInt();
	for(ri i=1;i<=q;i++)
	{
		GetString(ch);
		int ax=GetInt()+1,ay=GetInt()+1;
		int bx=GetInt()+1,by=GetInt()+1;
		if(ch[1]=='U')PutInt(Sum(ax,ay,bx,by)),putchar('\n');
		else if(ch[1]=='A')PutInt(Query_Max(ax,ay,bx,by)),putchar('\n');
		else PutInt(Query_Min(ax,ay,bx,by)),putchar('\n');
	}
	return 0;
}