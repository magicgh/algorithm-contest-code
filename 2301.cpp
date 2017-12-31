#include<iostream>
using namespace std;
int x1=0,a[10]={6,2,5,5,4,5,6,3,7,6},n,s,ans=0,i,j;
int fire(int x)
{
  int b=0;
  if(x<10)return a[x];
  while(x){b+=a[x%10];x=x/10;}
  return b;
}
int main(){
    cin>>n;
    n-=4;
    for(i=0;i<=1111;i++)
    {
        for(j=0;j<=1111;j++)
            {
              if(fire(i)+fire(j)+fire(i+j)==n)ans++;
              }
              }
              cout<<ans<<endl;
//system("pause");
return 0;
}
