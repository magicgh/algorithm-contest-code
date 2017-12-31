#include<iostream>
using namespace std;
long long used[205]={0},n,bj=0;;
string len;
char a[205];
void QPL(int k)
{
	int i;
	if(k>n)
	{
	bj++;cout<<bj<<":";
	for(i=1;i<=n;i++)cout<<a[i];cout<<endl;return;
	}
	for(i=0;i<n;i++)
	{
	if(used[i]>0)
	{
	 a[k]=len[i];
	 used[i]--;
	 QPL(k+1);
	 used[i]++;
	}
		
	}
}
int main()
{
	int i;
cin>>len;
n=len.length();
for(i=0;i<n;i++)used[len[i]-'a']++;
QPL(1);
return 0;
}
