#include<iostream>
#include<cmath>
using namespace std;
long long n,js=0,a[25]={0};
bool b[25]={0};
 char l1,l2;
void dfs(int depth)
{
	int i;
	if(depth>n){
	js++;
	for(i=1;i<=n;i++){cout<<char(a[i]+l1-1)<<a[i]<<' ';}cout<<endl;return;}
	
	for(i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			a[depth]=i;
			b[i]=1;
			dfs(depth+1);
			b[i]=0;
		}
	}
	return;
}
int main(){
	cin>>l1>>l2;
	n=abs(l2-l1)+1;
	dfs(1);
	cout<<"total="<<js;
	return 0;
}
