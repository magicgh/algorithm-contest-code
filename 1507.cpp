#include<iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long a[n+1],k=0,t=0;
    for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<n;i++)
        {
        for(int j=i+1;j<=n;j++)
        {
        if(a[i]>a[j]){t=a[i];a[i]=a[j];a[j]=t;}
         if(a[i]==a[j]&&a[j]!=0)
         {
         a[j]=0;
         k++;
         }
         }
         }
         cout<<n-k<<endl;
         for(int i=1;i<=n;i++)
         {
         if(a[i]!=0)cout<<a[i]<<" ";
         }
         
                   
//system("pause");
return 0;
}
