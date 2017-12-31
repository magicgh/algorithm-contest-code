#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,m,num[1005],f[10005],ans[10005][60];
void Add(int a[],int b[])
{
	b[0]=max(a[0],b[0]);
	for(int i=1;i<=b[0];i++)
	{
	b[i]+=a[i];
	if(b[i]>=10)b[i+1]+=b[i]/10;
	b[i]%=10;
}
	while(b[b[0]+1]>0)b[0]++;
}
int main(){
	memset(num,0,sizeof(num));
	memset(f,0,sizeof(f));
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>num[i];
	f[0]=ans[0][0]=ans[0][1]=1;
	for(int i=1;i<=n;i++)
	   for(int j=m;j>=num[i];j--)
	   {
	   	if(f[j-num[i]])
	   	{
	   		Add(ans[j-num[i]],ans[j]);
	   		f[j]=1;
		   }
	   }
	   for(int i=ans[m][0];i>=1;i--)cout<<ans[m][i];
	return 0;
}
