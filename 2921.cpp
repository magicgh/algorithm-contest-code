#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
char s[500005];
int n,k,num[500005]={0};
bool Check(int x)
{
	int i=1,cnt=0;
	while(i<=n)
	{
		if(num[i]==0)i++;
		if(num[i]==1)
		{
			cnt++;
			i+=x;
		}
	}
	if(cnt<=k)return 0;
	else return 1;
}
int erfen(int l,int r)
{
	int mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(Check(mid))l=mid+1;
		else r=mid-1;
	}
	return l;
}
int main(){
	bool t=0;
	scanf("%d%d%s",&n,&k,&s);
	for(int i=0;i<n;i++)
	{
	num[i+1]=s[i]-'0';
	if(num[i+1]==1)t=1;
	}
	if(t==0)printf("0");
	else printf("%d",erfen(1,n));
	return 0;
}
