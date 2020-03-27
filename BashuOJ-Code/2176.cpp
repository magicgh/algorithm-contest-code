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
using namespace std;
struct jhb{double a,b;}tb[55];
int n;
double want,c,sum=0,solid=0;
inline bool cmp(const jhb &x,const jhb &y){return x.a<y.a;}
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
	for(ri i=1;i<=n;i++)scanf("%lf",&tb[i].a);
	for(ri i=1;i<=n;i++)scanf("%lf",&tb[i].b),sum+=tb[i].b,solid+=tb[i].a*tb[i].b;
	c=solid/sum;//全部溶液混合 
	scanf("%lf",&want);
	sort(tb+1,tb+n+1,cmp);
	for(ri i=n;i>=1&&c>want;i--)//倒掉溶度偏大的溶液 
	{
		double pour=(solid-sum*want)/(tb[i].a-want);//多余的溶质/偏差的浓度 
		if(pour<=tb[i].b){sum-=pour;break;}//第i瓶溶液倒出部分就满足 
		sum-=tb[i].b,solid-=tb[i].a*tb[i].b; 	
		c=solid/sum;
	}
	for(ri i=1;i<=n&&c<want;i++)//倒掉溶度偏小的溶液 
	{
		double pour=(sum*want-solid)/(want-tb[i].a);
		if(pour<=tb[i].b){sum-=pour;break;}
		sum-=tb[i].b,solid-=tb[i].a*tb[i].b;
		c=solid/sum;
	}
	printf("%.5lf",sum);
	return 0;
}

