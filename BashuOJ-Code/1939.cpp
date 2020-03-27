#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int M=1000005;
const int N=int(log(M)/log(2))+5;
int f[M][N],n,m;
inline int Ask(int x,int y)
{
	int t=int(log(y-x+1)/log(2));
	return max(f[x][t],f[y-(1<<t)+1][t]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>f[i][0];
	for(int j=1;(1<<j)<=n;j++)
	   for(int i=1;(i+(1<<j)-1)<=n;i++)
	   {
	   	f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	   }
	   int x,y;
	   for(int i=1;i<=m;i++)
	   {
	   cin>>x>>y;cout<<Ask(x,y)<<endl;
	   }
	return 0;
}
