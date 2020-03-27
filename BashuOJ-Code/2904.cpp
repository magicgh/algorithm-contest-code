#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int a[100005],b[100005],cnt=0;
inline int separ(int x)
{
	int i=1;
	while(x>1)
	{
		i++;
		if(x%i==0)
		{
			a[++cnt]=i;
			while(x%i==0)x/=i,b[cnt]++;
		}
	}
	int ans=1;
	for(int i=1;i<=cnt;i++)ans*=(b[i]+1);
	return ans;
}
inline int euler(int x)
{
	int ans=x;
	for(int i=1;i<=cnt;i++)if(b[i]!=0)ans-=ans/a[i];
	return ans;
}
int main(){
	int n;
	cin>>n;
	cout<<n-separ(n)-euler(n)+1;
	return 0;
}