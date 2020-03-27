#include<iostream>
using namespace std;
char a[9]={' ','{','[','(','<','>',')',']','}'};
string str;
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
     int i,j,len,k=0;
     bool x=true;
     int c[1005]={0};
     cin>>str;
     len=str.length();
     for(i=0;i<len;i++)
     {
	 for(j=1;j<=8;j++)if(str[i]==a[j])break;
      if(j<=4)
      {
	  if(c[k]>j){cout<<"NO"<<endl;x=false;break;}
        else {k++;c[k]=j;}
      }
      else if(j+c[k]!=9){cout<<"NO"<<endl;x=false;break;}
        else k--;
     }
     if(x==true)
      if(k==0)cout<<"YES"<<endl;
       else cout<<"NO"<<endl;
    }
     return 0;
}