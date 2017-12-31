#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
double c,s,r,pi=3.1415926;
cin>>r;
c=2*pi*r;
s=pi*r*r;
cout<<fixed<<setprecision(2)<<c<<' '<<s;
//system("pause");
return 0;
}
