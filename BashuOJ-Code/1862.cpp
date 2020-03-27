#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct bitch{
int x,y;	
}a[50005];
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
	int s=a[1].x,d=a[1].y;
	for(int i=2;i<=n;i++)
	{
		if(d>=a[i].x)d=max(d,a[i].y);
		else 
		{
			cout<<s<<' '<<d<<endl;
			s=a[i].x,d=a[i].y;
		}
	}
	cout<<s<<' '<<d<<endl;
		return 0;
}