#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int N=65540;
long long phi[N],n;
int main(){
	for(int i=1;i<=N;i++)phi[i]=i;
	for(int i=2;i<=N;i+=2)phi[i]/=2;
	for(int i=3;i<=N;i+=2)
	   if(phi[i]==i)
	      for(int j=i;j<=N;j+=i)phi[j]-=phi[j]/i;
	while(cin>>n)
	{
		cout<<phi[n-1]<<endl;
	}
	return 0;
}