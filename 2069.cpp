#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#define f for
using namespace std;
int cnt=0,n;
bool Jinwei(int ans[])
{
	ans[2]+=ans[3]/10;
	ans[3]%=10;
	ans[1]+=ans[2]/10;
	ans[2]%=10;
	ans[5]+=ans[6]/10;
	ans[6]%=10;
	ans[4]+=ans[5]/10;
	ans[5]%=10;
	if(ans[1]>=10||ans[4]>=10)return 1;
	return 0;
}
bool Jinwei1(int ans[])
{
	ans[9]+=ans[10]/10;
	ans[10]%=10;
	ans[8]+=ans[9]/10;
	ans[9]%=10;
	ans[7]+=ans[8]/10;
	ans[8]%=10;
	if(ans[7]>=10)return 1;
	//cout<<ans[7]<<' '<<ans[8]<<' '<<ans[9]<<' '<<ans[10];
	return 0;
}
void Find(int ans[],int a[])
{
	int i,j,bj=0;
	f(i=1;i<=10;i++)
	  f(j=1;j<=n;j++)if(ans[i]==a[j]){bj++;continue;}
	if(bj==10)cnt++;
	return;
}
int main(){
	//freopen("haha.out","w",stdout);
int a[15],i,j,k,m,q,ans[15];
cin>>n;
memset(a,0,sizeof(a));
memset(ans,0,sizeof(ans));
f(i=1;i<=n;i++)cin>>a[i];
f(i=1;i<=n;i++)
f(j=1;j<=n;j++)
f(k=1;k<=n;k++)
f(m=1;m<=n;m++)
f(q=1;q<=n;q++)
{
	ans[1]=a[i]*a[q];
	ans[2]=a[j]*a[q];
	ans[3]=a[k]*a[q];
	ans[4]=a[m]*a[i];
	ans[5]=a[m]*a[j];
	ans[6]=a[m]*a[k];
	if(Jinwei(ans))continue;
	ans[7]=ans[4];
	ans[8]=ans[1]+ans[5];
	ans[9]=ans[2]+ans[6];
	ans[10]=a[3];
	if(Jinwei1(ans))continue;
	Find(ans,a);
}
cout<<cnt;
	return 0;
}
