#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
int a1,a2,a3,a4,a5,n;
char t1,t2,t3,t4;
bool bj=0;
void Work(int i,int j,int k,int m)
{
	int ans=0;
	if(i==1)ans+=a1+a2,t1='+';
	if(i==2)ans+=a1-a2,t1='-';
	if(i==3)ans+=a1*a2,t1='*';
	if(i==4)ans+=a1/a2,t1='/';
	
	if(j==1)ans+=a3,t2='+';
	if(j==2)ans-=a3,t2='-';
	if(j==3)ans*=a3,t2='*';
	if(j==4)ans/=a3,t2='/';
	
	if(k==1)ans+=a4,t3='+';
	if(k==2)ans-=a4,t3='-';
	if(k==3)ans*=a4,t3='*';
	if(k==4)ans/=a4,t3='/';
	
	if(m==1)ans+=a5,t4='+';
	if(m==2)ans-=a5,t4='-';
	if(m==3)ans*=a5,t4='*';
	if(m==4)ans/=a5,t4='/';
	if(ans==n)
	{
	bj=1;
	cout<<a1<<t1<<a2<<t2<<a3<<t3<<a4<<t4<<a5<<'='<<n<<endl;
	}
	return;
}
int main(){
	int i,j,k,m;
	cin>>a1>>a2>>a3>>a4>>a5>>n;
	for(i=1;i<=4;i++)
	for(j=1;j<=4;j++)
	for(k=1;k<=4;k++)
	for(m=1;m<=4;m++)
	{
	Work(i,j,k,m);
	}
	if(!bj)cout<<"no answer!";
	return 0;
}
