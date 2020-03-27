#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int f[1000005],n,l,r,len=1,mid=0; 
struct node
{
	int a,b;
};
node c[1000005];
bool comp(node x,node y)
{
	return x.a<y.a;
	
}
int main(){
	
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)scanf("%d %d",&c[i].a,&c[i].b);
   sort(c,c+n,comp);
   f[1]=c[1].b;
    for(i=2;i<=n;i++)
    {
    l=1;r=len;
	if(f[len]<c[i].b){len++;f[len]=c[i].b;continue;}
	while(l<=r)
     {
      mid=(l+r)/2;
     if(f[mid]<c[i].b)l=mid+1;else r=mid-1;	
     }	
    f[l]=c[i].b;
    }
    cout<<len;
    return 0;
}