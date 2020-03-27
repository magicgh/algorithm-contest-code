#include<iostream>
using namespace std;
long n,a[505]={0};
int tree(int root)//树函数 
{
	cout<<root<<' ';
	for(int i=1;i<=n;i++)if(a[i]==root)tree(i);
}
int main(){
	int x,y,root;
         cin>>n;
         for(int i=1;i<=n;i++){cin>>x>>y;a[x]=y;}//输入 
         for(int i=1;i<=n;i++)if(a[i]==0)root=i;//找树根 
         tree(root);//进入函数 
         
	return 0;
}
