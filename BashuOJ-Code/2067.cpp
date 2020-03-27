/*
ID: baymax01
PROG: barn1
LANG: C++    
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	//freopen("barn1.in","r",stdin);
	//freopen("barn1.out","w",stdout);
	int m,s,c,i,a[1005],b[1005];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cin>>m>>s>>c;
	for(i=0;i<c;i++)cin>>a[i];
	sort(a,a+c);
	int sum=a[c-1]-a[0]+1;
	for(i=1;i<c;i++)b[i]=a[i]-a[i-1]-1;
	sort(b+1,b+c,cmp);
	for(i=1;i<m;i++)sum-=b[i];
	cout<<sum<<endl;
	return 0;
}
