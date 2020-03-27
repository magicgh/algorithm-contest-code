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
const int INF=0x7fffffff; 
struct travel{int t,a,b;};
travel bus[10005];
int n,m,k,ans;
int dist[1005],sum[1005],arrive[1005],setoff[1005],affect[1005];
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
	n=getint(),m=getint(),k=getint();
	for(ri i=1;i<n;i++)dist[i]=getint();
	for(ri i=1;i<=m;i++)
	{
		int t=getint(),a=getint(),b=getint();
		bus[i]=(travel){t,a,b};
		setoff[bus[i].a]=max(setoff[bus[i].a],bus[i].t);//最晚出发时间 
		sum[bus[i].b]++;
	}
	for(ri i=1;i<=n;i++)sum[i]+=sum[i-1];//下车人数前缀和 
	for(ri i=2;i<=n;i++)
		arrive[i]=max(arrive[i-1],setoff[i-1])+dist[i-1];//最晚到达时间 
	for(ri i=1;i<=m;i++)ans+=arrive[bus[i].b]-bus[i].t;//不加速的时间总和
	while(k--)
	{
		affect[n]=affect[n-1]=n;//i站点加速最远会影响到affect[i]站点下车乘客的旅行时间 
		for(ri i=n-1;i>=1;i--)
		{
			if(arrive[i]<=setoff[i])affect[i-1]=i;//巴士早到对i站点之后乘客的时间无影响 
			else affect[i-1]=affect[i];//巴士晚到会影响到最远的站点下车乘客的时间 
		}
		//i->affect[i]构成了一个可加速区间 
		int Max=-INF,Num=0;	
		for(ri i=1;i<=n;i++)//寻找可加速区间中乘客最多的区间,对该段时间加速,乘客的总旅行时间可减少最多 
		{
			if(sum[affect[i]]-sum[i]>Max&&dist[i]>0)//必须是合法区间
				Max=sum[affect[i]]-sum[i],Num=i; 
		}
		if(Max==-INF)break;//无可加速区间且加速器没用完,就算了
		ans-=Max;//更新答案
		dist[Num]--;//该区间被加速,距离缩短
		arrive[1]=0;//初始化 
		for(ri i=2;i<=n;i++)arrive[i]=max(arrive[i-1],setoff[i-1])+dist[i-1];//距离缩短,更新到达时间 
	}
	printf("%d",ans);
	return 0;
}

