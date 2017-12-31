#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<map>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> rb_tree;
map<int,bool>m;
rb_tree tr;
int N,M;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	int x,y;
	N=GetInt();
	M=GetInt();
	for(int i=1;i<=N;i++)
	{
		x=GetInt();
		if(!m[x])tr.insert(x),m[x]=1;
	}
	for(int i=1;i<=M;i++)
	{
		x=GetInt();
		y=GetInt();
		if(x==1)if(!m[y])tr.insert(y),m[y]=1;
		if(x==2)if(m[y])tr.erase(tr.find(y)),m[y]=0;
		if(x==3)printf("%d\n",*tr.find_by_order(y-1));
	}
	return 0;
}