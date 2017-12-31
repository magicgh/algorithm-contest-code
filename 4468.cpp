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
const int MAXN=100005;
struct Query{int u,v,e;};
Query a[MAXN];
int T,n,Pn,Un,Point[MAXN<<1],prt[MAXN<<1];
inline bool cmp(const Query &a,const Query &b){return a.e>b.e;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline void Init(){Un=Pn=0;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);
}
int main()
{
	T=getint();
	while(T--)
	{
		n=getint();
		Init();
		for(ri i=1;i<=n;i++)
		{
			int u=getint(),v=getint(),e=getint();
			Point[++Pn]=u,Point[++Pn]=v;
			a[i]=(Query){u,v,e};
		}
		sort(Point+1,Point+Pn+1);
		sort(a+1,a+n+1,cmp);
		Un=unique(Point+1,Point+Pn+1)-(Point+1);
		for(ri i=1;i<=Un;i++)prt[i]=i;
		bool flag=0;
		for(ri i=1;i<=n;i++)
		{
			int x=lower_bound(Point+1,Point+Un+1,a[i].u)-Point;
			int y=lower_bound(Point+1,Point+Un+1,a[i].v)-Point;
			if(a[i].e==1)
			{
				int f1=getfa(x),f2=getfa(y);
				if(f1!=f2)prt[f1]=f2;
			}
			if(a[i].e==0)
			{
				int f1=getfa(x),f2=getfa(y);
				if(f1==f2){flag=1;break;}
			}
		}
		printf(flag?"NO\n":"YES\n");
	}
	return 0;
}
