#include<iostream>
using namespace std;
int main()
{ 
int i,i1,i2,i3,i4,i5,i6,s=0,a1,b1,c1,d1,e1,f1,bj=0;
cin>>a1>>b1>>c1>>d1>>e1>>f1;
int a[1001];
for(i=1;i<=1000;i++)a[i]=0;
for(i1=0;i1<=a1;i1++)
    for(i2=0;i2<=b1;i2++)
          for(i3=0;i3<=c1;i3++)
                for(i4=0;i4<=d1;i4++)
                    for(i5=0;i5<=e1;i5++)
                          for(i6=0;i6<=f1;i6++)
                            {
                            s=i1*1+i2*2+i3*3+i4*5+i5*10+i6*20;
                            a[s]=1;
                           }
for(i=1;i<=1000;i++)if(a[i])bj++;
cout<<"TOTAL="<<bj<<endl;
return 0;
}
