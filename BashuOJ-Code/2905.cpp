#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define N 50005
bool PrimeNum[N*100]={0};
int Num[N]={0};
void Prime()
{
	int i,j;
	PrimeNum[0]=PrimeNum[1]=1;
	PrimeNum[2]=0;
 for(i=2;i<sqrt(N);i++)
    {
    	if(PrimeNum[i]==0)
    	{
		  j=2;
    		while(i*j<N)
    		{
    			PrimeNum[i*j]=1;
    			j++;
			}
		}
	}
	return;
}
using namespace std;
int main(){
	long long l,r,cnt=0,ans=0;
	cin>>l>>r;
	memset(PrimeNum,0,sizeof(PrimeNum));
	Prime();
	for(int i=2;i<N;i++)if(!PrimeNum[i])Num[++cnt]=i;
	memset(PrimeNum,0,sizeof(PrimeNum));
	for(int i=1;i<=cnt;i++)
	{
		long long j=l/Num[i];
		if(j*Num[i]<l)j++;
		if(j==1)j++;
		for(;j*Num[i]<=r;j++)PrimeNum[j*Num[i]-l]=1;
	}
	for(int i=0;i<=r-l;i++)if(!PrimeNum[i])ans++;
	cout<<ans;
	return 0;
}