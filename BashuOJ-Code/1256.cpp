#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
double a,b,c,d;
double calc(double x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
void Partition(double l,double r)
{
	double l1=calc(l),r1=calc(r),m=(l+r)/2,m1=calc(m);
	if(l+0.0001>r||calc((l+r)/2)==0){cout<<fixed<<setprecision(2)<<(l+r)/2<<' ';return;}
	if(l1*m1<0)Partition(l,m);
	if(m1*r1<0)Partition(m,r);
	return;
}
int main(){
	cin>>a>>b>>c>>d;
	for(int i=-100;i<=100;i++)
	{
		if(calc(i)==0)cout<<fixed<<setprecision(2)<<double(i)<<' ';
		if(calc(i)*calc(i+1)<0)Partition(i,i+1);
	}
	return 0;
}
