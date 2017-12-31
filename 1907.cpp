#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
struct node
{
	int x,y;
}Map[10005];
bool cmp(node aa,node bb)
{
	return aa.x<bb.x;
}
int n,m,k,f[10005];
double ans=0;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)cin>>Map[i].x>>Map[i].y;
	sort(Map+1,Map+k+1,cmp);
	for(int i=1;i<=k;i++)f[i]=1;
	for(int i=2;i<=k;i++)
	  for(int j=1;j<i;j++)if(Map[i].y>Map[j].y&&f[j]+1>f[i])f[i]=f[j]+1;
	  int Max=-0x7fffffff;
	for(int i=1;i<=k;i++)Max=max(Max,f[i]);
	ans=(n+m-Max*2)*100+Max*100*sqrt(2);
	cout<<int(ans+0.5);
	return 0;
}
