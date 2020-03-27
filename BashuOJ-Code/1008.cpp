#include<iostream>
using namespace std;
int main(){
 int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,max;
cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n;
a=a+b;
b=c+d;
c=e+f;
d=g+h;
e=i+j;
f=k+l;
g=m+n;
max=a;
o=1;
if(max<b) {max=b; o=2;}
if(max<c) {max=c; o=3;}
if(max<d) {max=d; o=4;}
if(max<e) {max=e; o=5;}
if(max<f) {max=f; o=5;}
if(max<g) {max=g; o=7;}
if(max<8) cout<<0;
else 
cout<<o;
    //stsyem("pause");
    return 0;
}
