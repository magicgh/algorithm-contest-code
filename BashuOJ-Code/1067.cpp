#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int f[35][35],tree[35],num[35][35],n,ans;
inline int DP(int i,int j)
{
	if(i>j)return 1;
	if(i==j)return tree[i];
	if(f[i][j])return f[i][j];
	for(int k=i;k<=j;k++)
	{
		ans=DP(i,k-1)*DP(k+1,j)+tree[k];
		if(f[i][j]<ans)f[i][j]=ans,num[i][j]=k;
	}
	return f[i][j];
}
inline void Output(int i,int j)
{
	if(i>j)return;
	if(i==j){printf("%d ",i);return;}
	printf("%d ",num[i][j]);
	Output(i,num[i][j]-1);
	Output(num[i][j]+1,j);
	return;
}
int main(){
scanf("%d",&n);
memset(f,0,sizeof(f));
memset(num,0,sizeof(num));
memset(tree,0,sizeof(tree));
for(int i=1;i<=n;i++)scanf("%d",&tree[i]);
printf("%d\n",DP(1,n));
Output(1,n);
	return 0;
}
