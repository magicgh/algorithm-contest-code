#include<iostream>
using namespace std;
int main(){
int a[30][30],i,j,p,kn,mn,kw,mw,t;
string k,m,c="";
for(i=1;i<=26;i++)
  for(j=1;j<=26;j++){
  	t=i+j-1;
  	if(t>26)t-=26;
  	a[i][j]=t;
  }
cin>>k>>m;
mn=m.length();
kn=k.length();
for(i=0,j=-1;i<mn;i++){
j++;
if(j==kn)j=0;
if(k[j]<'a')kw=k[j]-'A'+1;
else kw=k[j]-'a'+1;
if(m[i]<'a')mw=m[i]-'A'+1;
else mw=m[i]-'a'+1;
for(p=1;p<=26;p++)
  if(a[p][kw]==mw)break;
if(m[i]<'a')c+='A'+p-1;
else c+='a'+p-1;
}
cout<<c;
return 0;
}