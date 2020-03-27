#include<iostream>
using namespace std;
int main(){
	long long a,b,i;
	while(cin>>a>>b)
	{
		if(!a&&!b)return 0;
		for(i=0;i<99;i++)
		{
			if((a*100+i)%b==0)cout<<i/10<<i%10<<' ';
		}
		cout<<endl;
	}
	return 0;
}