#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
struct country
{
	int num;
	string dist,name;
}a[5005];
int cnt;
inline bool cmp(const country &a,const country &b)
{
	int lena=a.dist.length(),lenb=b.dist.length();
	if(lena!=lenb)return lena<lenb;
	else return a.dist<b.dist;
}
int main()
{
	ios::sync_with_stdio(false);
	int sum=0,i,ans=0,n;
	while(cin>>a[++cnt].num)cin>>a[cnt].dist>>a[cnt].name,sum+=a[cnt].num;
	sort(a+1,a+cnt+1,cmp);
	for(i=1;i<=cnt;i++)
	{
		ans+=a[i].num;
		if(ans>sum/2)break;
	}
	cout<<a[i].name;
	return 0;
}

