#include<iostream>
using namespace std;
int main(){
    long long n,i,a1=0,a2=1,a3;
    cin>>n;
    if(n==2||n==3) a3=1;
    for(i=3;i<=n;i++)
    {
    a3=a1+a2;
    a1=a2;
    a2=a3;
    }
    cout<<a3;
             
    //system("pause");
    return 0;
}
