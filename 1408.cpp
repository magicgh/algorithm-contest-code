#include<iostream>
using namespace std;
int main(){
      int i,j,k,x,y,z;
     while(cin>>x)
     {
     i=0;j=-1;y=0;z=1;
     for(k=1;k<=x;k++)
     {
      y=(y+z)%10000;j++;
      if(i==j)
      {
      i++;j=-1;
      z=(z*2)%10000;
      }
      }cout<<y;
      cout<<endl;
      }
    //system("pause");
    return 0;
}
