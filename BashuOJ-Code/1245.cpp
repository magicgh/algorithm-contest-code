#include<iostream>
using namespace std;
int main()
{
    string m;
    int n,s=0,i;
    cin>>n>>m;
    for(i=0;m[i]!='\0';i++)
    {
      s=s*n+m[i]-'0';
      if(m[i]>='A')s=s+'0'-'A'+10;}
     cout<<"("<<m<<")"<<n<<"=("<<s<<")10"; 
//system("pause");
return 0;
}
