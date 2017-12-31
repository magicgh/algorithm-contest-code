#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	int x,y;
	double z;
}a[1005];
struct xy
{
	int x, y;
}b[1005];
int m,prt[1005]={0},cnt=0;
double ans=0;
inline bool cmp(const node &a,const node &b)
{
	return a.z<b.z;
}
inline int GetFather(int u)
{
	if(prt[u]==u)return u;
	prt[u]=GetFather(prt[u]);
	return prt[u];
}
inline void kruskal()
{
	int i,f1,f2,k=0;
	for(i=1;i<=m;i++)prt[i]=i;
	for(i=1;i<=cnt;i++)
	{
		f1=GetFather(a[i].x);
		f2=GetFather(a[i].y);
		if(f1!=f2)
		{
			ans=ans+a[i].z;
			prt[f1]=f2;
			k++;
			if(k==m-1)break;
		}
	}
	 printf("%.2lf\n",ans);
}
int main()
{
   scanf("%d",&m);
   for(int i=1;i<=m;i++)scanf("%d%d",&b[i].x,&b[i].y);
   for(int i=1;i<m;i++)
   for(int j=i+1;j<=m;j++)a[++cnt].x=i,a[cnt].y=j,a[cnt].z=sqrt((b[i].x-b[j].x)*(b[i].x-b[j].x)+(b[i].y-b[j].y)*(b[i].y-b[j].y));
   sort(a+1,a+cnt+1,cmp);
   kruskal();
  
return 0;
}