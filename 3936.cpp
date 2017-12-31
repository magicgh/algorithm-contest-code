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
const int MAXN=2005;
struct Dwarf
{
	int h1,h2;
	bool operator <(const Dwarf &rhs)
	const {return h1+h2<rhs.h1+rhs.h2;}
};
Dwarf a[MAXN];
int f[MAXN];
int n,H,Ans;
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
	for(ri i=1;i<=n;i++)
	{
		int Height=getint(),Hand=getint();
		a[i]=(Dwarf){Height,Hand};
	}
	sort(a+1,a+n+1);
	memset(f,-1,sizeof(f));
	f[0]=0;
	for(ri i=1;i<=n;i++)
		f[0]+=a[i].h1;
	H=getint();
	for(ri i=1;i<=n;i++)
		for(ri j=Ans;j>=0;j--)
		{
			if(f[j]+a[i].h2>=H)
				f[j+1]=max(f[j+1],f[j]-a[i].h1);
			if(f[Ans+1]!=-1)Ans++;//如果又逃出了一个人 
		}
	printf("%d\n",Ans);
	return 0;
}

