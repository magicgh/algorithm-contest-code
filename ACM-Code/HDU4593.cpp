#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,a[123123],b[12312];

int main()
{
	while(~scanf("%d",&n))
	{
		
	memset(b,0,sizeof(b));
	for(int i=1;i<=n+1;++i)
	{
		int x;
		cin>>x;
		if(b[x]) 
		{
			cout<<x<<endl;
		}
		b[x]=1;
	}}
    return 0;
}