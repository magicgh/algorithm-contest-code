#include<iostream>
using namespace std;
int main(){
   long long n,flag=0,five=5;
   while(cin>>n)
   {
   flag=0;
   five=5;
   while(five<=n)
   {
     flag+=n/five;
     five=five*5;
     }
     cout<<flag<<endl;
     }
    return 0;
}