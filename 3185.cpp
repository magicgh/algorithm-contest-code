#include<iostream>
using namespace std;
int main()
{    int i,num[16]={0},t;
    string n;
    cin>>n;
   num[0]=n.length();
  for(i=1;i<=num[0];i++)num[i]=n[num[0]-i]-'0';
     t=1;
     while(num[t]==0)t++;
    while(num[num[0]]=='-'-48)
       {cout<<"-";num[0]--;}
      for(i=t;i<=num[0];i++)cout<<num[i];
    return 0;
}

