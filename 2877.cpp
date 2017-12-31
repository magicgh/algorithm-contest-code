#include <iostream>
using namespace std;
long n,a[505][505]={0},used[505]={0},ans=0,found=0;
void dfs(int i,int deep)
{
	int j;
	if(deep==n)
	{
		ans++;
		return;
	}
		for(j=1;j<=n;j++)
		{
			if(a[i][j]==1&&used[j]==0)
			{
				used[j]=1;
				dfs(j,deep+1);
				used[j]=0;
			}
		}
	
}
int main()
 {
 int i,j;
 cin>>n;
 for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)cin>>a[i][j];
 for(i=1;i<=n;i++)
 {
 	used[i]=1;
 	dfs(i,1);
 	used[i]=0;
 }
cout<<ans;
  return 0;
  
}
