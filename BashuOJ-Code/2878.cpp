#include <iostream>
using namespace std;
bool a[205][205]={0},visit[205]={0};
int x,y,ans=0,n;
void dfs(int i)
{
	int j;
ans++;
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
   	a[x][y]=true;
   }
   cin>>assign;
  dfs(assign);
  cout<<ans; 
	return 0;
}
