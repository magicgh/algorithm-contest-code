#include<iostream>
using namespace std;
int main(){
    int s=0,z=0,n,max=0,b=0,i;
    char a;
    cin>>n;
    for(i=1;i<=n;i++)
    {s=0;z=0;
     for(cin>>a;a!='E';cin>>a)
     {
        if(a=='Y'){s++;z++;}
        if(a=='N'){z=0;}
        if(z==3){s++;z=0;}
        }
        if(s>=max){max=s;b=i;}
        }
        cout<<b<<endl<<max;
    //system("pause");
    return 0;
}
