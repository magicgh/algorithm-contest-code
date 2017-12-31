#include<iostream>
using namespace std;
int main(){
    long long n,i,a1=1,a2=1,a3=1,s=0;
    cin>>n;
    if(n==1||n==2||n==3) a3=1;
    for(i=4;i<=n;i++)
    {
     s=a1+a3;
     a1=a2;
     a2=a3;
     a3=s;
     
    }
    cout<<s;
             
    //system("pause");
    return 0;
}
