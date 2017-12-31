#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define Srh_Max 2005
using namespace std;
int n,m,a[1005],f[Srh_Max],Maxv=0,Max=-0x7fffffff;
bool used[1005];
int DP()
{
	    int ans=0;
		for(int i=1;i<=Maxv;i++)f[i]=0;
		f[0]=1;
		for(int i=1;i<=n;i++)
		{
		
		if(!used[i])
		{
		   for(int j=Maxv;j>=a[i];j--)if(f[j-a[i]])f[j]=1;
	   }
	   }
	   for(int i=Maxv;i>=1;i--)if(f[i])ans++;
	   return ans;
}
void dfs(int x,int y)
{
	if(y==0)Max=max(DP(),Max);
	else for(int i=x;i<=n-y+1;i++)
	{
		if(!used[i])
		{
		used[i]=1;
		dfs(i+1,y-1);
		used[i]=0;
		}
	}
	   return;
}
int main(){
	memset(a,0,sizeof(a));
	memset(used,0,sizeof(used));
	memset(f,0,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],Maxv+=a[i];
	dfs(1,m);
	cout<<Max;
	return 0;
}