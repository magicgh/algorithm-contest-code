#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int a,b,c,d,e,f;
cin>>a;
b=a%10;
c=a/10%10;
d=a/100%10;
e=a/1000;
b=b*1000;
c=c*100;
d=d*10;
e=e*1;
f=b+c+d+e;
cout<<f;
//system("pause");
return 0;
}
