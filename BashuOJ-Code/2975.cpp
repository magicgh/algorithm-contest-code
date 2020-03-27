#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int n,m,temp,ans=0,js=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>temp;
		ans+=temp;
		if(ans>m)
		{
			ans=temp;
			js++;
		}
		else if(ans==m)
		{
			ans=0;
			js++;
		}
	}
	if(ans)js++;
	cout<<js;
	return 0;
}
