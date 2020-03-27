#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int ans1=0;
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
int l;
int main(){
	while(scanf("%d",&l)!=EOF)
	{
			ans1=0;
			for(int n=1;n<=2005;n++)
		   for(int m=n+1;m<=2005;m++)
		   {
		   	if(m*m+n*n>2005*2005)break;
		   	if(2*m*m+2*m*n>l||n%2==m%2||gcd(n,m)!=1)continue;
		   	int x=m*m-n*n;
		   	int y=2*m*n;
		   	int z=m*m+n*n;
		   	for(int i=1;x*i+y*i+z*i<=l;i++)ans1++;
		   }
	printf("%d\n",ans1);
	}
	return 0;
}