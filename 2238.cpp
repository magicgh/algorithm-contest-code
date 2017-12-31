#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
#define ri register int
const double eps=1e-9;
const int MAXN=100005;
using namespace std;
struct currency{double a,b,r,x,y;int n;};
currency c[MAXN],tmp[MAXN];
double f[MAXN],ans=0;
int stack[MAXN],top=0;
int n,Time;//Time为划分的时间
inline bool cmp(const currency &x,const currency &y){return x.a*y.b<y.a*x.b;}
inline bool sp(const currency &x){return x.n<=Time;}//True在左 False在右 
inline bool merge_xy(const currency &x,const currency &y)
{
	if(fabs(x.x-y.x)<=eps)return x.y<y.y;
	return x.x<y.x;
}
inline double cross(currency &A,currency &B,currency &C){return (A.x-C.x)*(B.y-C.y)-(A.y-C.y)*(B.x-C.x);}
inline double calc(int j,int i){return c[j].x*c[i].a+c[j].y*c[i].b;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline double getk(int a,int b)//获得斜率 
{
	if(!b)return -1e20;
	if(fabs(c[a].x-c[b].x)<eps)return 1e20;//分母为0,斜率最大
	return (c[a].y-c[b].y)/(c[a].x-c[b].x); 
}
void Binary(int l,int r)
{
	if(l==r){
		f[l]=max(f[l],f[l-1]);
		c[l].y=f[l]/(c[l].a*c[l].r+c[l].b);
		c[l].x=c[l].y*c[l].r;
		ans=max(ans,f[l]);
		return;
	}
	int mid=(l+r)>>1;Time=mid;
	stable_partition(c+l,c+r+1,sp);//稳定划分(保持相对顺序)
	Binary(l,mid);
	top=0;
	for(ri i=l;i<=mid;i++)//[L,mid]维护凸壳 
	{
		while(top>1&&cross(c[stack[top]],c[i],c[stack[top-1]])>=0)top--;
		stack[++top]=i;
	}
	int j=1;
	for(ri i=mid+1;i<=r;i++)//[L,mid]的决策更新[mid+1,R]的情况 
	{
		while(j+1<=top&&calc(stack[j+1],i)>calc(stack[j],i))j++;//找到最大值的j 
		f[c[i].n]=max(f[c[i].n],calc(stack[j],i));//DP
	}
	Binary(mid+1,r);
	int len=merge(c+l,c+mid+1,c+mid+1,c+r+1,tmp+1,merge_xy)-tmp-1;//有序表合并 
	memcpy(c+l,tmp+1,sizeof(*tmp)*len);
	 
}
int main()
{
	n=getint(),ans=f[0]=getint();//初始资金 
	for(ri i=1;i<=n;i++)
	{
		scanf("%lf%lf%lf",&c[i].a,&c[i].b,&c[i].r);
		c[i].n=i;
	}
	sort(c+1,c+n+1,cmp);//叉积排序 
	Binary(1,n);
	printf("%.3lf",ans);
	return 0;
}
