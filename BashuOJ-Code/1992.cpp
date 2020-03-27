#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int x,y;
}a[100005];
bool cmp(const node &aa,const node &bb)
{
	return aa.x>bb.x||(aa.x==bb.x&&aa.y>bb.y);
}
int n,b[100005];
int main(){
	cin>>n;
	memset(b,0,sizeof(b));
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	int l,r,len=1;
	b[1]=a[1].y;
	for(int i=2;i<=n;i++)
	{
		l=1,r=len;
		if(b[len]>=a[i].y){b[++len]=a[i].y;continue;}
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(b[mid]>=a[i].y)l=mid+1;
			else r=mid-1;
		}
		b[l]=a[i].y;
	}
	cout<<len;
	return 0;
}
