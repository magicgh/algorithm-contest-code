#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
const int M=50;
struct node
{
	int data,lch,rch;
	bool ison;
}
Tree[M];
int n;
void dfs(int k,int num)
{
	if(num==1)putchar(k-1+'A');
	if(Tree[k].lch!=0)dfs(Tree[k].lch,num);
	if(num==2)putchar(k-1+'A');
	if(Tree[k].rch!=0)dfs(Tree[k].rch,num);
	if(num==3)putchar(k-1+'A');
	return;
}
int main(){
	int tc,tp,prt,root;
	char t;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		tp=t-'A'+1;
		for(int j=1;;j++)
	{
		cin>>t;
		if(t=='0')break;
		tc=t-'A'+1;
		Tree[tc].ison=1;
		if(j==1)Tree[tp].lch=tc;
		else Tree[prt].rch=tc;
		prt=tc;
	}
	}
	for(int i=1;i<=n;i++)if(Tree[i].ison==0)root=i;
	dfs(root,1);cout<<endl;
	dfs(root,2);cout<<endl;
	dfs(root,3);cout<<endl;
	return 0;
}
