#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ll long long
using namespace std; 
const int MAXN=10005;
int a[2505]={1,1},b[2505]={1,2},c[2505];
int n,m,ans;
string name[MAXN],s;
inline int Binary()
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(name[mid]<=s)l=mid+1;
		else r=mid-1;
	}
	return l;
}
void Plus()
{
	memset(c,0,sizeof(c));
	c[0]=max(a[0],b[0]);
	for(int i=1;i<=c[0];i++)c[i]=a[i]+b[i];
	for(int i=1;i<=c[0];i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	while(c[c[0]+1])
	{
		c[0]++;
		c[c[0]+1]=c[c[0]]/10;
		c[c[0]]%=10;
	}
	memcpy(a,b,sizeof(b));
	memcpy(b,c,sizeof(c));
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>name[i];
	sort(name+1,name+n+1);
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		int pos=Binary();
		if(name[pos].find(s)==0)ans++;
	}
	printf("%d\n",ans);
	if(n<=3)printf("%d",n);
	else
	{
		for(int i=3;i<=n;i++)Plus();
		for(int i=c[0];i>=1;i--)cout<<c[i];
	}
	return 0;
}