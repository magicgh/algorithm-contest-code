#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int l,r;
}a[5005];
inline bool cmp(const node &a,const node &b)
{
	return a.l<b.l||(a.l==b.l&&a.r<b.r);
}
int main(){
	int f[5005],Max=-0x7fffffff,n;
	cin>>n;
    memset(a,0,sizeof(a));
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)cin>>a[i].l>>a[i].r;
    	sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
    	f[i]=1;
    	for(int j=1;j<i;j++)
    	{
    		if(a[i].r<a[j].r)f[i]=max(f[i],f[j]+1);
    	}
    	Max=max(Max,f[i]);
    }
    cout<<Max;
	return 0;
}