#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int cnt=0,n,m,a[105];
inline int Prime(int x){
	for(int i=2;i<=sqrt(x);i++)if(x%i==0)return 0;
	return 1;
}
inline void dfs(int num,int sum,int k)
{
	if(num==m)
		{if(Prime(sum))cnt++;}
	else for(int i=k;i<=n;i++)dfs(num+1,sum+a[i],i+1);
}
int main(){
	memset(a,0,sizeof(a));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	dfs(0,0,1);
	printf("%d",cnt);
	return 0;
}