#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	long long a,b,c,sum=0,i,num[10005],ans=0;
	char t1,t2;
	cin>>a>>t1>>b>>t2>>c;
	memset(num,0,sizeof(num));
	if(b==10)
	{
	i=0;
	while(a)
	{
	 i++; 
	 sum=sum+(a%c)*pow(10,i-1);
	 a/=c;
	}
	cout<<sum;
	}
	if(b!=10)
	{
		i=0;
		while(a)
		{
			num[++i]=a%10;
			a/=10;
		}
		for(int j=i;j>=1;j--)sum=sum*b+num[j];
		if(c==10)cout<<sum;
		else 
		{
			i=0;
	while(sum)
	{
	 i++; 
	 ans=ans+(sum%c)*pow(10,i-1);
	 sum/=c;
	} cout<<ans;	
	}
	
	}
	return 0;
}
