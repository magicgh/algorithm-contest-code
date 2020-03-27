#include<iostream>
using namespace std;
int main()
{    
     int a,i,x,m=0,s=0,s1=0,a1=0;
    
     for(i=1;i<=12;i++)
{   
    cin>>a;    
    s=s+300;            
    if(s>=a)
{   
    s=s-a;    
    m=m+(s/100*100);        
    s=s%100;
}    
     else    
{    x=i;        
     cout<<-x<<endl;     
    // system("pause");    
     return 0;
}
}         
     s=s+m*12/10;
     cout<<s<<endl;    
     //system("pause");    
     return 0;
}
