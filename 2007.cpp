#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
void Work(int k)
{
	int i,m,ans[10005];
	memset(ans,0,sizeof(ans));
	ans[0]=ans[1]=1;
	for(m=1;m<=k;m++)
	{
	for(i=1;i<=ans[0];i++)ans[i]*=2;
	for(i=1;i<=ans[0];i++)ans[i+1]+=ans[i]/10,ans[i]%=10;
	while(ans[ans[0]+1]>0)ans[0]++;
	}
	ans[1]-=2;
		for(i=1;i<=ans[0];i++)
		{
			if(ans[i]>=0)break;
			else ans[i]+=10,ans[i+1]--;
		}
	while(ans[ans[0]]==0)ans[0]--;
	for(i=ans[0];i>=1;i--)cout<<ans[i];
}
int main(){
	int n;
	cin>>n;
	Work(n+1);
	return 0;
}