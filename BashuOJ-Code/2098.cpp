#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> rb_tree;
rb_tree tr;
int N,People=0,Pet=0,Ans=0;
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main(){
	int k,x;
	N=GetInt();
	tr.insert(0x7fffffff/2);
	tr.insert(-0x7fffffff/2);//建立边界的前驱后继 
	for(int i=1;i<=N;i++)
	{
		k=GetInt();
		x=GetInt();
		if(k==0)
		{
			if(!Pet)tr.insert(x),People++;
			else
			{
				Pet--;
				int pre=*(--tr.lower_bound(x));
				int suc=*tr.upper_bound(x);
				 if(x-pre<=suc-x)
				{
					Ans=(Ans+x-pre)%1000000;
					tr.erase(tr.find(pre));
				}
				else
				{
					Ans=(Ans+suc-x)%1000000;
					tr.erase(tr.find(suc));
				} 
			}
		}
		if(k==1)
		{
			if(!People)tr.insert(x),Pet++;
			else
			{
				People--;
				int pre=*(--tr.lower_bound(x));
				int suc=*tr.upper_bound(x);
			   if(x-pre<=suc-x)
				{
					Ans=(Ans+x-pre)%1000000;
					tr.erase(tr.find(pre));
				}
				else
				{
					Ans=(Ans+suc-x)%1000000;
					tr.erase(tr.find(suc));
				}
			}
		}
	}
	printf("%d",Ans);
	return 0;
}