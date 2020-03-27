#include<iostream>
using namespace std;
int main(){
    long long n,i,a1=1,a2=1,a3;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    a3=a1+a2;
    a1=a2;
    a2=a3;
    }
    cout<<a3;      
  //  system("pause");
    return 0;
}
