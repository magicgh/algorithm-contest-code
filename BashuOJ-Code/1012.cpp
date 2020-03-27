#include<iostream> 
using namespace std; 
int main()
 { int n,m,s=1,k; 
  cin>>n>>m;  
  for( int i=1;i<=n;i++) s*=m;
  if(m==2) s*=m; 
  s-=m-1; k=s;n++;
  while(n>1) 
    { n--; k=(k-1)/m*(m-1); }
  cout<<k<<endl<<s; 
  return 0;
 } 