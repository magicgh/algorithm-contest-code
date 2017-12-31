#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
 	string a;
 	char b;
 	double n,m,s=0,i,j,con=0,u=0;
 	cin>>n>>b;
 	for(i=1;i<=n;i++)
 	{
      cin>>a;
     if(a[0]=='c'&&a[1]=='o'&&a[2]=='n')con++;
     m=a.length();
     u=u+m; 
 	for(j=0;j<m;j++)
 	{
       if(a[j]==b)s++;
          
         }  
         }    
         s=(s/u)*100;
       cout<<con<<endl;
       cout<<fixed<<setprecision(2)<<s<<"%";
   // system("pause");
    return 0;
}
