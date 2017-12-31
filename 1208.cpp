#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,z;
}a[100005];
int m,n,prt[100005]={0};
long long ans=0;
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
	for(i=0;i<=n;i++)prt[i]=i;
	for(i=1;i<=m;i++)
	{
		f1=GetFather(a[i].x);
		f2=GetFather(a[i].y);
		if(f1!=f2)
		{
			ans=ans+a[i].z;
			prt[f1]=f2;
			k++;
			if(k==n)break;
		}
	}
	 printf("%d\n",ans);
}
int main()
{
   int i,j;
   scanf("%d",&n);
   for(i=1;i<=n;i++)a[i].x=0,a[i].y=i,scanf("%d",&a[i].z); 
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)scanf("%d",&a[(i-1)*n+j+n].z),a[(i-1)*n+j+n].x=i,a[(i-1)*n+j+n].y=j;
   m=n*n+n;
   sort(a+1,a+m+1,cmp);
   kruskal();
  
return 0;
}