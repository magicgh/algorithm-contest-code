#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n,i,t;
    cin>>n;
    int a[n+5];
    memset(a,0,sizeof(a));
    for(i=1;i<=n-2;i++){cin>>t;a[t]=1;}
    for(i=1;i<=n;i++)
    {
      if(a[i]==0)
      cout<<i<<" ";
      }
//system("pause");
return 0;
}
