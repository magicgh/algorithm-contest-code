#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int k,f[10]={0},ans[10005]={1,1};
bool a[10][10]={0};
string s;
void Multi(int k)
{
	for(int i=1;i<=ans[0];i++)ans[i]*=k;
	for(int i=1;i<=ans[0];i++)ans[i+1]+=ans[i]/10,ans[i]%=10;
	while(ans[ans[0]+1]>0)
	{
		ans[0]++;
		ans[ans[0]+1]+=ans[ans[0]]/10;
		ans[ans[0]]%=10;
	}
}
int main(){
	cin>>s>>k;
	int x,y,len=s.length();
	for(int i=0;i<=9;i++)a[i][i]=1;
	for(int i=1;i<=k;i++)
	{
		cin>>x>>y;
		a[x][y]=1;
	}
	for(int k=0;k<=9;k++)
	for(int i=0;i<=9;i++)
	for(int j=0;j<=9;j++)
		a[i][j]=a[i][j]||(a[i][k]&&a[k][j]);
	for(int i=0;i<=9;i++)
	   for(int j=0;j<=9;j++)f[i]+=a[i][j];
	   for(int i=0;i<len;i++)
	   	  Multi(f[s[i]-'0']);
	   	  for(int i=ans[0];i>=1;i--)cout<<ans[i];
	return 0;
}
