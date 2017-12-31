#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int pi;
	int ai;
	bool operator <(const node &b)const
	{
		return pi<b.pi;
	}
} Milk[5005];
int main()
{
	int n,m,i;
	cin>>n>>m;
	for(i=1; i<=m; i++)cin>>Milk[i].pi>>Milk[i].ai;
	sort(Milk+1,Milk+m+1);
	int cnt=0,ans=0;
	for(i=1;cnt<n;i++)
	{
		ans+=Milk[i].pi*Milk[i].ai;
		cnt+=Milk[i].ai;
	}
	cout<<ans-(cnt-n)*Milk[i-1].pi;
	return 0;
}
