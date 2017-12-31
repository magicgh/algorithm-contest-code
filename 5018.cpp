#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ri register int
using namespace std;
const int MAXN=50005;
const int PMAXN=10005;
struct Div{int x,y;};
Div a[MAXN];
int n,p[205],f[PMAXN],Ans;
bool vst[PMAXN];
inline bool cmp(const Div &a,const Div &b){return a.y<b.y;}
inline int max(const int &a,const int &b){return a>b?a:b;}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
void Init()
{
	int Limit=1050;
	for(int i=2;i<=Limit;i++)
	{
		if(!vst[i])p[++p[0]]=i;
		for(ri j=1;j<=p[0]&&i*p[j]<=Limit;j++)
		{
			vst[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
}
int main()
{
	Init();
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		int x=getint(),t=x;
		for(ri j=1;j<=p[0]&&p[j]<=sqrt(x);j++)
			if(t%p[j]==0)
			{
				a[i].x=p[j];
				a[i].y=t/p[j];
				break;//保证p[j]小于t/p[j] 
			}
	}
	sort(a+1,a+n+1,cmp);
	for(ri i=1;i<=n;i++)
		f[a[i].y]=max(f[a[i].y],f[a[i].x]+1);
	for(ri i=1;i<=n;i++)
		Ans=max(Ans,f[a[i].y]);
	printf("%d\n",Ans);
	return 0;
}