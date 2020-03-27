#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
const int MOD=10007;
using namespace std;
int a,b,k,n,m;
int c[1005][1005];
inline int GetInt()	
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	a=GetInt()%MOD;
	b=GetInt()%MOD;
	k=GetInt();
	n=GetInt();
	m=GetInt();	
	for(int i=1;i<=k;i++)
	{
		c[i][i]=c[i][0]=1;
		for(int j=1;j<i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
	}//组合版杨辉三角	
	int ans=c[k][m];
	int ans1=1,ans2=1;
	for(int i=1;i<=n;i++)ans1=a*ans1%MOD; 
	for(int i=1;i<=m;i++)ans2=b*ans2%MOD;
	ans=ans*ans1%MOD*ans2%MOD;
	printf("%d",ans);
	return 0;
}
