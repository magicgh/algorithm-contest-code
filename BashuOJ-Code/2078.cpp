/*
ID: baymax01
PROG: sort3
LANG: C++            
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
	//freopen("sort3.in","r",stdin);
	//freopen("sort3.out","w",stdout);
	int i,n,a[1005],b[1005],num[5][5],js=0,ans=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(num,0,sizeof(num));
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
	{
		if(a[i]!=b[i])num[a[i]][b[i]]++,js++;
	}
	ans+=min(num[1][2],num[2][1]);js-=min(num[1][2],num[2][1])*2;
	ans+=min(num[1][3],num[3][1]);js-=min(num[1][3],num[3][1])*2;
	ans+=min(num[2][3],num[3][2]);js-=min(num[2][3],num[3][2])*2;
	cout<<ans+(js/3)*2<<endl;
	return 0;
}
