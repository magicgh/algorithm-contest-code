#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int M=50005;
const int N=int(log(M)/log(2))+5;
int f1[M][N],f2[M][N],n,m;
inline int Ask1(int x,int y)
{
	int t=int(log(y-x+1)/log(2));
	return max(f1[x][t],f1[y-(1<<t)+1][t]);
}
inline int Ask2(int x,int y)
{
	int t=int(log(y-x+1)/log(2));
	return min(f2[x][t],f2[y-(1<<t)+1][t]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&f1[i][0]),f2[i][0]=f1[i][0];
	for(int j=1;(1<<j)<=n;j++)
	   for(int i=1;(i+(1<<j)-1)<=n;i++)
	   {
	   	f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
	   }
	   for(int j=1;(1<<j)<=n;j++)
	   for(int i=1;(i+(1<<j)-1)<=n;i++)
	   {
	   	f2[i][j]=min(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
	   }
	   int x,y;
	   for(int i=1;i<=m;i++)
	   {
	   scanf("%d%d",&x,&y);printf("%d\n",Ask1(x,y)-Ask2(x,y));
	   }
	return 0;
}
