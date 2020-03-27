#include<iostream>
using namespace std;
long long m,used[205]={0},n,bj=0,a[205];
string len;
void QPL(int k)
{
	int i;
	if(k>m)
	{
	bj++;cout<<bj<<":";
	for(i=1;i<=m;i++)cout<<char(a[i]+97);cout<<endl;return;
	}
	for(i=a[k-1];i<=26;i++)
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
cin>>len>>m;
n=len.length();
for(i=0;i<n;i++)used[len[i]-'a']++;
QPL(1);
return 0;
}
