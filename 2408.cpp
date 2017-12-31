#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#define Max 100005
using namespace std;
int sum[Max];
int main() {
	int i,j,x,y;
	bool bj=0;
	cin>>x>>y;
	for (i=0;i<=Max;i++)sum[i]=1;
	for (i=2;i<=Max/2;i++)
	{
		j=i*2;
		while (j<=Max) {
			sum[j]+=i;
			j+=i;
		}
	}
	for (i=x;i<=y;i++)
	if(sum[i]>i&&sum[i]<=y&&sum[sum[i]]==i)
	{
	bj=1;
	cout<<i<<' '<<sum[i]<<endl;
	}
	if(bj==0)cout<<"Sorry";
	return 0;
}