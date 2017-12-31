#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
	int a,b,c,k;
}s[1005];
inline bool cmp(const node &aa,const node &bb)
{
	return (aa.c==bb.c&&aa.k<bb.k)||aa.c>bb.c;
}
inline bool cmp1(const node &aa,const node &bb)
{
	return aa.k<bb.k;
}
int x,y,n;
int main(){
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++)cin>>s[i].a,s[i].k=i;
	for(int i=1;i<=n;i++)cin>>s[i].b,s[i].c=s[i].a*x+s[i].b*y;
	sort(s+1,s+n+1,cmp);
	int i=15;
	while(s[i].c==s[i+1].c)i++;
    if(i>=n)
    	for(int i=1;i<=n;i++)cout<<i<<' ';
	if(i<n)
	{
		sort(s+1,s+i+1,cmp1);
		int bj=i;
		for(int i=1;i<=bj;i++)cout<<s[i].k<<' ';
	}
	return 0;
}