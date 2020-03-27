#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;
int main(){
	int n,x,y,x1=3,y1=1,x2=3,y2=1,d=8;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		x=x1*x2+d*y1*y2;
		y=x2*y1+y2*x1;
		cout<<y<<' '<<(x-1)/2<<endl;
		x1=x,y1=y;
	}
	return 0;
}
