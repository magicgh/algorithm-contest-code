/*
ID: magicgh
PROG: MaoLaoDaNumber
LANG: C++                  
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
#define N 50000005
using namespace std;
bool PrimeNum[N];
bool PrimeCheck(int n)
{
	int i;
	if(n==0||n==1)return 1;
	for(i=2;i<=sqrt(n);i++)if(n%i==0)return 1;
	return 0;
}
void Prime()
{
	int i,j;
	PrimeNum[0]=PrimeNum[1]=1;
	PrimeNum[2]=0;
 for(i=2;i<sqrt(N);i++)
    {
    	if(PrimeNum[i]==0)for(j=i*i;j<N;j+=i)PrimeNum[j]=1;
	}
}
int main(){
long long n,i;
cin>>n;
memset(PrimeNum,0,sizeof(PrimeNum));
Prime();
for(i=2;i<sqrt(N);i++)if(n%i==0){
if(PrimeNum[i]==0&&PrimeCheck(n/i)==0){
cout<<"It's a MaoLaoDa number.";return 0;}}
cout<<"It's not a MaoLaoDa number.";
	return 0;
}