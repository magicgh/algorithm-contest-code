#include<iostream>
using namespace std;
int main(){
    long long  s,e,t,d,n,i,j,m,lj=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
    cin>>s>>e>>t>>d;
    m=(e-s)/t+1;
    lj+=m+m*(m-1)/2*d;
    }
    cout<<lj;
//system("pause");
return 0;
}
