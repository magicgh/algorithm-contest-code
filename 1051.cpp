#include<iostream>
using namespace std;
int main(){
    long long n,i,fs[105],cj[105],lw[105],s[105]={0},max=0,mh=0,q=0;
    string a[105];
    char c[105],h[105];
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i]>>fs[i]>>cj[i]>>c[i]>>h[i]>>lw[i];
    for(i=1;i<=n;i++)
    {
      if(fs[i]>80&&lw[i]>=1)
      {
        s[i]=s[i]+8000;
        }
        if(fs[i]>85&&cj[i]>80)
        {
          s[i]=s[i]+4000;
          }
          if(fs[i]>90)
          {
            s[i]=s[i]+2000;
            }
            if(fs[i]>85&&h[i]=='Y')
            {
              s[i]=s[i]+1000;
              }
              if(cj[i]>80&&c[i]=='Y')
              {
                s[i]=s[i]+850;
                }
                }
                for(i=n;i>0;i--){q=q+s[i];if(max<=s[i]) {max=s[i];mh=i;}}
                cout<<a[mh]<<endl<<max<<endl<<q;
    //system("pause");
    return 0;
}