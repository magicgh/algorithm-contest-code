#include<iostream>
using namespace std;
int main(){
    string a;
    int s,i,j,k,n;
    cin>>a>>n;
    s=a.length();
    for(i=1;i<=n;i++)
    {
      for(j=0;j<s-1;j++)
      if(a[j]>a[j+1])
      {for(k=j;k<s-1;k++)
      a[k]=a[k+1];
      break;
      }
      s--;
      }
      i=0;
     while(a[i]=='0')i++;
     for(j=i;j<=s-1;j++)cout<<a[j];

//system("pause");
return 0;
}
