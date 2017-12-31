#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define MAXN 1000000000
using namespace std;
int num[1500005][10],n;   
void Plus(int c[],int a[],int b[])
{
	c[0]=max(max(a[0],b[0]),c[0]);
	for(int i=1;i<=c[0];i++)
	{
		c[i]+=(a[i]+b[i]);
		if(c[i]>=MAXN)
		{
		c[i+1]+=c[i]/MAXN;
		c[i]%=MAXN;		
		}
	}
    while(c[c[0]+1]>0)c[0]++;
	return;					  
}
void output(int a[])
{
	printf("%d",a[a[0]]);
	for(int i=a[0]-1;i>=1;i--)
	{
		printf("%d",a[i]/100000000);
		printf("%d",a[i]/(10000000)%10);
		printf("%d",(a[i]/1000000)%10);
		printf("%d",(a[i]/100000)%10);
		printf("%d",(a[i]/10000)%10);
		printf("%d",(a[i]/1000)%10);
		printf("%d",(a[i]/100)%10);
		printf("%d",(a[i]/10)%10);
		printf("%d",(a[i]%10));
}            
return;
}
int main(){
	scanf("%d",&n);
	num[1][0]=num[1][1]=1;
	for(int i=2;i<=n/2+2;i++)
	{
		Plus(num[i],num[i/2+1],num[i-1]);
	}
	output(num[n/2+2]);
	return 0;
}