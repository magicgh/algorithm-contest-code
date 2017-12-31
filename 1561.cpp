#include<iostream>
using namespace std;
int n,maxx=0,minx=10000,ma=1,mi=1,i,sum;
int main(){
    cin>>n;
    int a[n+8];
    for(i=1;i<=n+8;i++)a[i]=0;
    for(i=1;i<=n;i++)cin>>a[i];
    a[n+1]=a[1];
    a[n+2]=a[2];
    a[n+3]=a[3];
       for(i=1;i<=n;i++)
    {
         sum=a[i]+a[i+1]+a[i+2]+a[i+3];
         if(sum>maxx){maxx=sum;ma=i;}
         if(sum<minx){minx=sum;mi=i;}
    }
         cout<<ma<<" "<<mi;
//system("pause");
return 0;
}
