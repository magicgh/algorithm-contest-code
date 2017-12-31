#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,z;
}a[10005];
int n,m,prt[10005]={0},ans=0;
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
	for(i=1;i<=n;i++)prt[i]=i;
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
	 printf("%d\n",ans);
}
int main()
{
   int i;
   scanf("%d%d",&n,&m);
   for(i=1;i<=m;i++) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
   sort(a+1,a+m+1,cmp);
   kruskal();
  
return 0;
}