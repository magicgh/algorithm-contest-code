#include<iostream>
#include<iomanip>
using namespace std;
int main(){
   double g,ai,bi,i,m,s=0;
   cin>>g;
   for(i=1;i<=g;i++)
   {
   cin>>ai>>bi;
   m=ai*(bi/10);
   s=s+m;
   }
   cout<<fixed<<setprecision(2)<<s;   
    //system("pause");
    return 0;
}
