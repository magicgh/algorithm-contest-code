#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int ans1=0,ans2=0;
bool Hash[1000005]={0};
inline int GetInt()	
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(bj==-1||c=='-')?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}	
int t;
int main(){
	while(scanf("%d",&t)!=EOF)
	{
		ans1=ans2=0;
		memset(Hash,0,sizeof(Hash));
		for(int n=1;n<=sqrt(t);n++)
		   for(int m=n+1;m<=sqrt(t);m++)
		   {
		   	if(m*m+n*n>t)break;
		   	if(n%2==m%2||gcd(n,m)!=1)continue;
		   	int x=m*m-n*n;
		   	int y=2*m*n;
		   	int z=m*m+n*n;
		   	ans1++;
		   	for(int i=1;i*z<=t;i++)
		   	{
		   	Hash[i*x]=1;
		   	Hash[i*y]=1;
		   	Hash[i*z]=1;
			}
		   }
	
	for(int i=1;i<=t;i++)if(Hash[i]==0)ans2++;
	printf("%d %d\n",ans1,ans2);
	}
	return 0;
}
