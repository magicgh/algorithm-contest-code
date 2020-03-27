#include<iostream>
using namespace std;
int main(){
int n,m;
cin>>n;
if(n<100) m=10;
if(n>=100&&n<110) m=30;
if(n>=110&&n<120) m=50;
if(n>=120&&n<130) m=70;
if(n>130) m=80;
cout<<m;
//    system("pause");
    return 0;
}
