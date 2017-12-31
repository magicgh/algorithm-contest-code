#include <iostream>
using namespace std;
bool a[1005][1005]={0},visit[1005]={0};
int x,y,ans=0,n;
void dfs(int i)
{
	int j;
visit[i]=true;
for(j=1;j<=n;j++)
{
	if(visit[j]==false&&a[i][j]==true)dfs(j);
}	

}
int main()
 {
   int m,i,assign;
   	cin>>n>>m;
   for(i=1;i<=m;i++)
   {
   	cin>>x>>y;
   	a[x][y]=a[y][x]=true;
   }
   for(i=1;i<=n;i++)
   {
   	if(visit[i]==0){dfs(i);ans++;}
   	}
  cout<<ans; 
	return 0;
}

