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
#define N 70000
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
int list[1005],p=0,n,i;
memset(PrimeNum,0,sizeof(PrimeNum));
Prime();
while(cin>>n)
{
p=i=0;
memset(list,0,sizeof(list));
while(1)
{
	i++;
	if(PrimeNum[i]==1)continue;
	if(i>n)break;
	if(n%i==0){n/=i;list[++p]=i;i=0;}
}
if(p==0)cout<<n<<endl;
else
{
for(i=1;i<p;i++)cout<<list[i]<<'*';
cout<<list[p]<<endl;
}
}
	return 0;
}