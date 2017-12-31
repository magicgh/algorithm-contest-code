#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<cstdlib>
using namespace std;
int n,num[50][50];
int main()
{
memset(num,0,sizeof(num));
scanf("%d",&n);
int x=1,y=n/2+1,i=0;
while(i<=n*n)
{
	num[x][y]=++i;
	if(x==1&&y!=n)x=n,y++;
	else if(y==n&&x!=1)y=1,x--;
	else if(x==1&&y==n)x++;
	else if(x!=1&&y!=n)
	{
		if(!num[x-1][y+1])x--,y++;
		else x++;
	}
}
for(int i=1;i<=n;i++)
{
   for(int j=1;j<=n;j++)printf("%d ",num[i][j]);
   printf("\n");
}
return 0;
}
