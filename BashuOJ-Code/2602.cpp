#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int N=1000005;
long long phi[N],n;
int main(){
	for(int i=1;i<=N;i++)phi[i]=i;
	for(int i=2;i<=N;i+=2)phi[i]/=2;
	for(int i=3;i<=N;i+=2)
	   if(phi[i]==i)
	      for(int j=i;j<=N;j+=i)phi[j]-=phi[j]/i;
	      for(int i=3;i<=N;i++)phi[i]+=phi[i-1];
	while(cin>>n&&n)
	{
		cout<<phi[n]<<endl;
	}
	return 0;
}