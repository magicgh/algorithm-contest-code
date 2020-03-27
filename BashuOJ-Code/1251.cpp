#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int n,num,Dgree[25],m=0,path[25];
bool map[25][25];
inline void DFS(int x,int k)
{
    if(k==m+2)
    {
    	for(int i=1;i<=m;i++)cout<<path[i]<<"->";
    	cout<<path[m+1];
    	exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		if(map[x][i])
		{
			map[x][i]=map[i][x]=0;
			path[k]=i;
			DFS(i,k+1);
			map[i][x]=map[x][i]=1;
		}
	}
}
int main(){
	cin>>n;
	memset(map,0,sizeof(map));
	memset(path,0,sizeof(path));
	memset(Dgree,0,sizeof(Dgree));
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)
	   {
	   cin>>map[i][j];
	   if(map[i][j])Dgree[i]++,m++;
	   }
	   int cnt=0,cache[25]={0};
	   m/=2;
	   for(int i=1;i<=n;i++)
	   if(Dgree[i]%2==1)cache[++cnt]=i;
	   if(cnt==0)cache[1]=1;
	   if(cnt==2||cnt==0)
	   {
	   	path[1]=cache[1];
	   	DFS(cache[1],2);
	   }
	   else puts("No Solution!");
	return 0;
}
