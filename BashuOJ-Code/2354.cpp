#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	int x,y;
	long double z;
}a[1000005];
int p,m=0,n,prt[10005]={0},dx[10005]={0},dy[10005]={0};
long double ans=0;
inline int GetInt()
{
	int num=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num;
}
inline long double dist(int x1,int x2,int y1,int y2)
{
	long double xx=(x1-x2),yy=(y1-y2);
	return sqrt(xx*xx+yy*yy);
}
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
	int i,f1,f2,k=0,x,y;
	for(i=1;i<=n;i++)prt[i]=i;
	for(i=1;i<=p;i++)
	{
		x=GetInt(),y=GetInt();
		f1=GetFather(x);
		f2=GetFather(y);
		if(f1!=f2)
		{
			prt[f1]=f2;
			k++;
		}
	}
	for(i=1;i<=m;i++)
	{
		f1=GetFather(a[i].x);
		f2=GetFather(a[i].y);
		if(f1!=f2)
		{
			ans=ans+a[i].z;
			prt[f1]=f2;
			k++;
			if(k==n-1)break;
		}
	}
	 printf("%.2lf",double(ans));  
}
int main()
{
   int i,j;
   n=GetInt();
   p=GetInt();
   for(i=1;i<=n;i++)dx[i]=GetInt(),dy[i]=GetInt();
   for(i=1;i<n;i++)
   	  for(j=i+1;j<=n;j++)
   	  {
   	  	a[++m].x=i;
   	  	a[m].y=j;
   	  	a[m].z=dist(dx[i],dx[j],dy[i],dy[j]);
   	  }
   sort(a+1,a+m+1,cmp);
   kruskal();
  
return 0;
}