#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define N 20005
using namespace std;
int m,n,a[N];
long long ans=0;
bool PrimeNum[N];
void Prime()
{
	int i,j;
	PrimeNum[0]=PrimeNum[1]=1;
	PrimeNum[2]=0;
 for(i=2;i<=sqrt(N);i++)
    {
    	if(PrimeNum[i]==0)
    	{
		  j=2;
    		while(i*j<=N)
    		{
    			PrimeNum[i*j]=1;
    			j++;
			}
		}
	}
	return;
}
void Init()
{
	memset(a,0,sizeof(a));
	memset(PrimeNum,0,sizeof(PrimeNum));
	a[1]=a[0]=1;
	return;
}
void Multi(int k)
{
	for(int i=1;i<=a[0];i++)a[i]*=k;
	for(int i=1;i<=a[0];i++)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10; 
	}
while(a[a[0]+1]>0)
{
	a[0]++;
	a[a[0]+1]+=a[a[0]]/10;
	a[a[0]]%=10; 
}
return;
}
void Plus()
{
	for(int i=1;i<=a[0];i++)ans+=a[i];
}
int main(){
cin>>m;
Init();
Prime();
for(int i=1;i<=m;i++)Multi(i);
Plus();
cout<<ans;
if(!PrimeNum[ans])cout<<"T";
else cout<<"F";
	return 0;
}