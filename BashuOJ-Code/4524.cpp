#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long n,m,a[505][505];
char map[505][505];
void Search(int x,int y)
{
	int temp=0;
	if(map[x][y-1]=='*')temp++;
	if(map[x][y+1]=='*')temp++;
	if(map[x+1][y]=='*')temp++;
	if(map[x-1][y]=='*')temp++;
	if(map[x-1][y-1]=='*')temp++;
	if(map[x+1][y+1]=='*')temp++;
	if(map[x-1][y+1]=='*')temp++;
	if(map[x+1][y-1]=='*')temp++;
	a[x][y]=temp;
	
}
int main()
{
int i,j;
memset(a,0,sizeof(a));
cin>>n>>m;
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)cin>>map[i][j];
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
{
	if(map[i][j]=='*')a[i][j]=142857;
	else Search(i,j);
}
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
	if(a[i][j]==142857)cout<<"*";
	else cout<<a[i][j];
}
cout<<endl;
}
return 0;
}
