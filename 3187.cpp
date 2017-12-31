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
const int MAXN=200005;
struct swiss{long long s;int p,id;};
swiss a[MAXN],l1[MAXN],l2[MAXN]; 
int n,r,q;
inline bool cmp(const swiss &a,const swiss &b)
{
	return (a.s==b.s&&a.id<b.id)||(a.s>b.s);
}
void Merge()
{
	int n1=0,n2=0,k=0;
	for(int i=1;i<=2*n;i+=2)
	{
		if(a[i+1].p>a[i].p)
		{
			a[i+1].s++;
			l1[++n1]=a[i+1];
			l2[++n2]=a[i];
		}
		if(a[i].p>a[i+1].p)
		{
			a[i].s++;
			l1[++n1]=a[i];
			l2[++n2]=a[i+1];
		}
	}
	int i=1,j=1;
	while(i<=n1&&j<=n2)
	{
		if(cmp(l1[i],l2[j]))a[++k]=l1[i],i++;
		else a[++k]=l2[j],j++;
	}
	while(i<=n1)a[++k]=l1[i],i++;
	while(j<=n2)a[++k]=l2[j],j++;
}
int main()
{
	scanf("%d%d%d",&n,&r,&q);
	for(ri i=1;i<=2*n;i++)scanf("%lld",&a[i].s),a[i].id=i;
	for(ri i=1;i<=2*n;i++)scanf("%d",&a[i].p);
	sort(a+1,a+2*n+1,cmp);
	for(ri i=1;i<=r;i++)Merge();
	printf("%d\n",a[q].id);
	return 0;
}

