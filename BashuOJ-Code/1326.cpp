#include<iostream>
#include<algorithm> 
using namespace std;
long long n,i,j,a[50005]={0},t=0;
int main(){
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];sort(a,a+n+1);
    for(i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    for(i=n;i>0;i--)cout<<a[i]<<" ";
    cout<<endl;
    //system("pause");
    return 0;
}
