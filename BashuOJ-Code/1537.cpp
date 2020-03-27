#include<iostream>
using namespace std;
int main(){
int a,b,c,d,i,n,e;
cin>>n;
for(i=1;i<n;i++)
{if(i<10&&i>=1) e=i*i*i;

if(i<1000&&i>100) {a=i%10;
b=i/10%10; c=i/100; e=a*a*a+b*b*b+c*c*c; }

if(i<10000&&i>1000){ a=i%10;
b=i/10%10; c=i/100%10;
d=i/1000;e=a*a*a+b*b*b+c*c*c+d*d*d;}
if(e==i) cout<<e<<endl;
}
    //system("pause");
    return 0;
}
