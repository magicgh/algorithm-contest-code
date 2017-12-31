#include<iostream>
using namespace std;
int n,h[1005]={0},t[1005]={0};
void scanf()
{
cin>>n;
for(int i=1;i<=n;i++)
cin>>h[i]>>t[i];
}
void qsort(int x,int y)
{
int i,j,mid;
i=x;j=y;mid=t[(x+y)/2];
while(i<=j)
{
while(t[i]<mid)i++;
while(t[j]>mid)j--;
if(i<=j)
{
swap(h[i],h[j]);
swap(t[i],t[j]);
i++;j--;
}
if(x<j)qsort(x,j);
if(i<y)qsort(i,y);
}
}
void print()
{
int ans=0;
for(int i=1,p=-1;i<=n;i++)
if(h[i]>=p){ans++;p=t[i];}
cout<<ans<<endl;
}
int main()
{
scanf();
qsort(1,n);
print();
return 0;
}