#include<iostream>
using namespace std;
      void hanoi(int n,char A,char C,char B)
      {
      if(n==1){cout<<A<<"->"<<C<<endl;
      return;}
      hanoi(n-1,A,B,C);
      cout<<A<<"->"<<C<<endl;
      hanoi(n-1,B,C,A);    
      }
      int main(){
         int n;
         cin>>n;
         hanoi(n,'A','C','B');
    //system("pause");
    return 0;
}
