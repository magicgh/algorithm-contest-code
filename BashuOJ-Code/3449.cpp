#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define N 1001005
bool PrimeNum[N]={0};
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
	int n,i,a1=-0x7fffffff;
	cin>>n;
	memset(PrimeNum,0,sizeof(PrimeNum));
	Prime();
	for(i=1;i<=N;i++)
	{
		if(PrimeNum[i]==0&&i<=n)a1=max(a1,i);
		if(PrimeNum[i]==0&&i>=n)break;
	}
	cout<<i-a1;
	return 0;
}
