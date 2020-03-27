#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct bitch
{
	int x,y,z;
} a[50005];
int n,ans=0,m;
bool vst[50005]= {0};
bool cmp(bitch aa,bitch bb)
{
	return aa.y>bb.y;
}
int main()
{
	cin>>m>>n;
	for(int i=1; i<=n; i++)cin>>a[i].x;
	for(int i=1;i<=n;i++)cin>>a[i].y;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		int bj=0;
		for(int j=a[i].x;j>=1;j--)if(!vst[j]){vst[j]=1;bj=1;break;}
		if(!bj)
		{
			for(int j=n;j>=1;j--)
			if(!vst[j])
			{
				vst[j]=1;break;
			}
			ans+=a[i].y;
	}
	 } 
	 cout<<m-ans;
	return 0;
}