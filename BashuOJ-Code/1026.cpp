#include<iostream>
using namespace std;
int main(){
   int n,i,j,flag=0;
   cin>>n;
   int a[1005];
   for(i=1;i<=n;i++)cin>>a[i];
   for(i=1;i<=n;i++)
   for(j=i+1;j<=n;j++)
   if(a[i]>a[j]){swap(a[i],a[j]);flag++;}
cout<<flag<<endl;
    return 0;
}
