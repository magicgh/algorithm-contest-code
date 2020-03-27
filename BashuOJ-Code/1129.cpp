#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;
int n,f[105][105]={0},people[105]={0};
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	   for(int j=1;j<=n;j++)if(i!=j)f[i][j]=INT_MAX;
	   int x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>people[i]>>x>>y;
		f[i][x]=f[x][i]=f[i][y]=f[y][i]=1;
		
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		if(f[i][k]!=INT_MAX&&f[k][j]!=INT_MAX)f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		int MIN=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
	   for(int j=1;j<=n;j++)
	   {
	   	sum+=f[i][j]*people[j];
	   }
	   MIN=min(MIN,sum);
    } 
    cout<<MIN;
	return 0;
}
