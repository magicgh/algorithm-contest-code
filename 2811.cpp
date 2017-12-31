#include<iostream>
using namespace std;
int main(){
    int l,r,c=0,i=1,a=0,b=0,f=0;
    cin>>l>>r;
    for(i=l;i<=r;i++)
    {
      f=i;
      while(f!=0)
      {
         a=f%10;
         f=f/10;
         if(a==2||b==2)
         {
           c++;
           }
           }
           }
           cout<<c;
      
       
    
   // system("pause");
    return 0;
}