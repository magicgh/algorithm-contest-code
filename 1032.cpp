#include<iostream>
using namespace std;
long n;
void Calc()
{
	int h=1,t=1,total=1;
	while(h<=t)
	{
		if(total<=n){t++;total+=t;}
		else{total-=h;h++;total-=t;t--;}
		if(total==n)cout<<h<<" "<<t<<endl;
	}
return;
}
int main()
{
cin>>n;
Calc();
return 0;
}
