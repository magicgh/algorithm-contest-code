#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct bitch
{
	int x,y;
} a[50005];
int n,ans=0;
bool vst[10005]= {0};
bool cmp(bitch aa,bitch bb)
{
	return aa.y<bb.y;
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++)
		{
			int cnt=0;
			for(int j=a[i].x; j<=a[i].y; j++)if(vst[j])cnt++;
			if(cnt<2)
				{
					for(int j=a[i].y; j>=a[i].x; j--)
						{
							if(!vst[j])ans++,cnt++,vst[j]=1;
							if(cnt==2)break;
						}
				}
		}
	cout<<ans;
	return 0;
}