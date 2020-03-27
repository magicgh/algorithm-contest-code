#include<iostream>
#include<cstdio>
using namespace std;
long long used[205]={0},n,bj=0,a[205];
string len;
void QPL(int k)
{
	int i;
	if(k>n)
	{
	bj++;cout<<bj<<":";
	for(i=1;i<=n;i++)cout<<char(a[i]+97);cout<<endl;return;
	}
	for(i=0;i<=25;i++)
	{
	if(used[i]!=0)
	{
	a[k]=i;
	used[i]--;
	QPL(k+1);
	used[i]++;
	}
		
	}
}
int main()
{
	int i;
cin>>len>>n;
for(i=0;i<len.length();i++)used[len[i]-'a']++;
QPL(1);
return 0;
}