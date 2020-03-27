#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int a,b,c;
cin>>a>>b>>c;
if(a>b&&a>c)
cout<<a;
if(b>a&&b>c)
cout<<b;
if(c>a&&c>b)
cout<<c;
//system("pause");
return 0;
}
