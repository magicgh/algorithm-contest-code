#include<iostream>
using namespace std;
int main()
{
    int s=0,flag=1;
    char a;
    for(cin>>a;a!='@';cin>>a)
    {
      if(a=='(')s++;
      if(a==')')s--;
      if(s<0)flag=0;
      }
      if(flag==1&&s==0)cout<<"YES";
      else cout<<"NO";
//system("pause");
return 0;
}
