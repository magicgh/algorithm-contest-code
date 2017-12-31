#include <bits/stdc++.h>
using namespace std;
int n,f[10005],Max=INT_MIN;
struct node
{
	int x,y;
}a[10005];
inline bool cmp(const node &x,const node &y)
{
	return x.y<y.y||(x.y==y.y&&x.x<y.x);
}
int main() {
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	   for(int j=0;j<=a[i].x;j++)f[a[i].y]=max(f[a[i].y],f[j]+(a[i].y-a[i].x));
	for(int i=1;i<=a[n].y;i++)Max=max(Max,f[i]);
	cout<<Max<<endl;
	return 0;
}