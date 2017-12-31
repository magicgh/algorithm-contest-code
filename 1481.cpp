#include<iostream>
using namespace std;
const string A="Stan wins.";
const string B="Ollie wins.";
bool Multi(double n)
{
	if(n>1&&n<=9)return true;
	else if(n>9&&n<=18)return false;
	else return Multi(n/18.0);
}
int main()
{
   double n;
   while(cin>>n)
   {
   	if(Multi(n))cout<<A<<endl;
   	else cout<<B<<endl;	
   }

return 0;
}
