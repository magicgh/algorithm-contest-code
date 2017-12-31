#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct bitch{
int x,y;	
}a[20005];
int n,ans=0;
bool cmp(bitch aa,bitch bb)
{
	if(aa.x==bb.x)return aa.y<bb.y;
	return aa.x<bb.x;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n;i++)
	{
		if(a[i].y>=a[i+1].x)a[i+1].x=a[i].x,a[i+1].y=max(a[i+1].y,a[i].y);
		else ans+=a[i].y-a[i].x;
}
	cout<<ans+a[n].y-a[n].x;
		return 0;
}