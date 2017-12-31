#include<iostream>
using namespace std;
long n,a[505]={0};
int tree(int root)
{
	for(int i=1;i<=n;i++)if(a[i]==root)tree(i);
	cout<<root<<' ';
}
int main(){
	int x,y,root;
         cin>>n;
         for(int i=1;i<n;i++){cin>>x>>y;a[x]=y;}
         for(int i=1;i<=n;i++)if(a[i]==0)root=i;
         tree(root);
	return 0;
}