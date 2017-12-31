#include<iostream>
using namespace std;
int main() 
{   
   char a[14];
   int s=0,k=1;
   for(int i=1;i<=13;i++)cin>>a[i];
    for(int i=1;i<=12;i++)
    {
    if(a[i]!='-')
    {
      if(a[i]=='X')
      {
        a[i]=(int)a[i];
        }
      s=s+(a[i]-'0')*k;
      k++;
      }
      }
      s=s%11;
      if(a[13]=='X'&&s==10)
      {
        cout<<"Right";
        }
        else if(s==10)
       {
             for(int i=1;i<13;i++)
             {cout<<a[i];}
      cout<<"X";}
      
      else if(a[13]-'0'==s)
      {
           {cout<<"Right";}
      }
      else
      {
      for(int i=1;i<13;i++){cout<<a[i];}
      cout<<s;
      }
        
    //system("pause");  
    return 0;      
}