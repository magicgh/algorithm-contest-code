#include<iostream>
#include<algorithm>
using namespace std;
long long k,a[50000];
int main()
{    a[1]=1;
     a[2]=1;
     for(int i=3;i<=49152;i++)a[i]=(a[(i-1)]+a[(i-2)])%32768;
     cin>>k;
     k=k%49152;
     if(k==0)cout<<a[49152]<<endl;
        else cout<<a[k]<<endl;
     return 0;
}
