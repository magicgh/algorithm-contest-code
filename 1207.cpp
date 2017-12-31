#include<iostream>
using namespace std;
long n;
int dfs(int i){
	cout<<i;
	if(2*i<=n){
	  cout<<"(";
	  dfs(2*i);
	  if(2*i<n){
	  	cout<<",";
	  	dfs(2*i+1);
	  }
	  cout<<")";
	}
}
int main(){
	cin>>n;
	cout<<"(";
	dfs(1);
	cout<<")";
return 0;
}