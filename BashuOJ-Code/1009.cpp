#include<iostream>
using namespace std;
int gbs(int x,int y)
{
  if(x%y==0)return y;
  else return gbs(y,x%y);
}
int main(){
    int i,s=0,x0,y0;
    cin>>x0>>y0;
    if(y0%x0!=0){cout<<0;/*system("pause");*/return 0;}
    if(x0==y0){cout<<1;/*system("pause");*/return 0;}
    for(i=x0;i<=y0;i+=x0)
    {
      if(x0*y0%i==0)
      {
      if(gbs(i,x0*y0/i)==x0)
      {
      s++;
      }
      }
      }
          cout<<s;
//system("pause");
return 0;
}
