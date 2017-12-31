#include<iostream>
using namespace std;
int main(){
    string a;char t;
    int i,n,max=0,j;
    cin>>a;
    n=a.length();
    for(i=0;i<n-1;i++)
    {
      for(j=i+1;j<n;j++)
      {
       if(a[i]<a[j]){t=a[i];a[i]=a[j];a[j]=t;}
       }
       cout<<a[i];
       }
       cout<<a[i];
                     
   //system("pause");
    return 0;
}
