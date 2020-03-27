#include<iostream>
using namespace std;
int main()
{
int a,b,c,x,y,z;
cin>>a>>b>>c;
x=a; if(b<x) x=b; if(c<x) x=c;
z=a; if(b>z) z=b; if(c>z) z=c;
y=a+b+c-x-z;
cout<<z<<' '<<y<<' '<<x<<endl;
//system("pause");
return 0;
}
