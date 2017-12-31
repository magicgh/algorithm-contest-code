#include<iostream>
using namespace std;
int main(){
   string a;
   cin>>a;
   int n,s,m[30]={0},maxn=0,minn=100,flag=0,i;
   n=a.length();
   for(i=0;i<n;i++)m[a[i]-'a']++;
   for(i=0;i<=25;i++)
   {
    if(m[i]>maxn)maxn=m[i];
    if(m[i]<minn&&m[i]!=0)minn=m[i];
}
  s=maxn-minn;
  if(s==1||s==0){cout<<"No Answer"<<endl;cout<<0<<endl;}
    if(s>1)
    {
     for(i=2;i<s;i++)
    {
      if(s%i==0)
      {
        flag=1;
        break;
        }
        }
      if(flag==1){cout<<"No Answer"<<endl;cout<<0<<endl;}  
      if(flag==0) {cout<<"Lucky Word"<<endl;cout<<s<<endl;} 
      }
//system("pause");
return 0;
}
