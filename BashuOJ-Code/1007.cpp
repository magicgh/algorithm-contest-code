#include<iostream>
using namespace std;
int main()
{
    long long a[6010]={0},i,n,flag=1;
    cin>>n;
    a[1]=1;
    for(i=1;flag<=n;i++)
    {
      if(a[i]==1)
      {
         cout<<i<<" ";
         flag++;
         a[i*2+1]=1;
         a[i*3+1]=1;
         }
         }
//system("pause");
return 0;
}
