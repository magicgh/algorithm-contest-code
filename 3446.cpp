#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
bool PrimeNum[20005];
void Prime()
{
  int i,j;
	PrimeNum[0]=1;
	PrimeNum[1]=PrimeNum[2]=0;
 for(i=2;i<sqrt(20005);i++)
    {
    	if(PrimeNum[i]==0)
    	{
		  j=2;
    		while(i*j<20005)
    		{
    			PrimeNum[i*j]=1;
    			j++;
			}
		}
	} 
	return;
}
int main(){
	memset(PrimeNum,0,sizeof(PrimeNum));
	Prime();
	int n,t,i,j,Max1=-0x7fffffff,Max2=-0x7fffffff;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		for(j=1;j<=sqrt(t);j++)
		{
		if(t%j==0)
		{
		if(PrimeNum[j]==0)if(Max1<=j){Max1=j;Max2=max(Max2,t);}
		if(PrimeNum[t/j]==0)if(Max1<=t/j){Max1=t/j;Max2=max(Max2,t);}
		}
		}
	}
	cout<<Max2;
	return 0;
}
