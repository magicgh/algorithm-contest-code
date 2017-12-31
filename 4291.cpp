#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
using namespace std;
long long a,b,l;
int i,j,k;
bool t;
double s,Min=0x7fffffff;
int main(){
	cin>>a>>b>>l;
s=double(a)/double(b);a=b=1;
for(i=1;i<=l;i++)
  for(j=1;j<=l;j++)
  {
  	t=1;
  	for(k=2;k<=i;k++)
  		if(i%k==0&&j%k==0)t=0;
  		if(j==1)t=1;
  	if(t&&(double(i)/double(j)>=s)&&(double(i)/double(j)-s<Min)){a=i;b=j;Min=(double(i)/double(j))-s;}
  	}
  cout<<a<<' '<<b;
	return 0;
}