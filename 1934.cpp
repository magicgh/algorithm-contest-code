#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
 long long a[10000005]={0},m,n,i,flag=1;
int main(){
    cin>>n>>m;
    for(i=1;i<=m;i++)scanf("%d",&a[i]);
    sort(a,a+m+1);
	a[0]=1;
    int t=0;
    if(m==1) {cout<<a[1];return 0;}
    for(i=1;i<=m;i++)
    {
    if(a[i]!=a[i-1])t=0;
    t++;
    if(t>m/2){flag=0;cout<<a[i];break;}
}
if(flag==1)cout<<-1;
    return 0;
}