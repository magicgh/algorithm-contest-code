#include<cstdio>
#include<cmath>
#include<algorithm>
#define ri register int
using namespace std;
const double Pi=3.1415926535;
const double Max=0x7fffffff;
struct marisa{int x,y,val,mul;}mao[2005];
int n;double k,sv[2005],sm[2005],f[2005];
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double getslope(const int &alpha){return tan(Pi/180*alpha);}
inline bool cmp(const marisa &t1,const marisa &t2){return double(t1.y-t1.x*k)<(t2.y-t2.x*k);}
inline int max(const int &t1,const int &t2){return t1>t2?t1:t2;}
int main()
{
	n=getint();
	for(ri i=1;i<=n;++i)
	{
		int x=getint(),y=getint(),v=getint(),m=getint();
		mao[i]=(marisa){x,y,v,m};
	}
	k=getslope(getint());
	sort(mao+1,mao+n+1,cmp);
	for(ri i=1;i<=n;++i)sv[i]=sv[i-1]+mao[i].val,sm[i]=sm[i-1]+mao[i].mul;
	for(ri i=1;i<=n;++i)
	{
		f[i]=-Max;
		for(ri j=0;j<i;++j)f[i]=max(f[i],f[j]+((sv[i]-sv[j])/(i-j))*(sm[i]-sm[j]));
	}
	printf("%.3lf",f[n]);
	return 0;
}
