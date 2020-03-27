#include<iostream>
using namespace std;
int main()
{
    long long a[100]={0},m,n,i=0,j;
    cin>>m>>n;
    cout<<"("<<m<<")10=(";
    while(m!=0)
    {
       i++;
       a[i]=m%n;
       m=m/n;
       }
       for(j=i;j>0;j--)
       {
         if(a[j]>=10){cout<<char(65+a[j]-10);}
         else {cout<<a[j];}
         }
         cout<<")"<<n<<endl;
//system("pause");
return 0;
}
