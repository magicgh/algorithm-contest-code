#include<iostream>
using namespace std;
int main(){
   int n,flag=0,five=5;
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
     //system("pause");
    return 0;
}
