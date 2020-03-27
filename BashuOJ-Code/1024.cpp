#include<iostream>
using namespace std;
int main()
{
    int i,j,sub1,sub2,sub3,k,s=0;
    cin>>k;
    for(i=10000;i<=30000;i++)
    {
      int a[6]={0};
      a[1]=i/10000;
      a[2]=i/1000%10;
      a[3]=i/100%10;
      a[4]=i%100/10;
      a[5]=i%10000;
      sub1=a[1]*100+a[2]*10+a[3];
      sub2=a[2]*100+a[3]*10+a[4];
      sub3=a[3]*100+a[4]*10+a[5];
      if(sub1%k==0&&sub2%k==0&&sub3%k==0){s++;cout<<i<<endl;}
      }
      if(s==0)cout<<"No";
//system("pause");
return 0;
}
