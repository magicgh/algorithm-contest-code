#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
unsigned long long n,tri[1005][1005];
int main(){
	memset(tri,0,sizeof(tri));
	cin>>n;
	if(n==1)cout<<"(a+b)^1=a+b";
	else if(n==2)cout<<"(a+b)^2=a^2+2ab+b^2";
	else
	{
		n++;
		for(int i=1;i<=n;i++)
		   for(int j=1;j<=n;j++)tri[i][j]=1;
		   for(int i=3;i<=n;i++)
		      for(int j=2;j<i;j++)tri[i][j]=tri[i-1][j-1]+tri[i-1][j];
				 cout<<"(a+b)^"<<n-1<<"="<<"a^"<<n-1<<"+"<<tri[n][2]<<"a^"<<n-2<<"b";
				 int t1=n-3,t2=2;
				 for(int i=3;i<n-1;i++)
				 {
				 	cout<<"+"<<tri[n][i]<<"a^"<<t1<<"b^"<<t2;
				 	t1--;
				 	t2++;
				 }
				 cout<<"+"<<tri[n][n-1]<<"a"<<"b^"<<n-2<<"+b^"<<n-1;
	}
	return 0;
}


