#include<iostream>
using namespace std;
int main()
{
    int n,num,flag=0,i,sum=1;
    char color;
    cin>>n;
    for(cin>>color;color!='Q';cin>>color)
    {
      cin>>num;
      flag++;
      n=n-num;
      }
      for(i=1;i<=flag;i++)sum=sum*(n-i+2);
      cout<<sum;
    
//system("pause");
return 0;
}