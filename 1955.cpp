#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map> 
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long,null_type,less<long long>,splay_tree_tag,tree_order_statistics_node_update> splay_tree;
inline long long GetLL()
{
	long long num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int N;
map<long long,int>m;//相同关键字多次插入的标记
//理论上x左移10位+Hash可以实现1024(2^10)个相同关键字的标记 
splay_tree tr;//定义splay树 
int main()
{
	int opt;long long x;
	N=GetInt();
	for(int i=1;i<=N;i++)
	{
		map<long long,int>::iterator it;
		opt=GetInt();
		x=GetLL();
		if(opt==1)tr.insert((x<<10)+(m[x]++));
		if(opt==2)
		{
		tr.erase(tr.find((x<<10)+(--m[x])));
		if(!m[x])m.erase(m.find(x));
		}
		if(opt==3)printf("%d\n",tr.order_of_key((x<<10))+1);
		if(opt==4)printf("%lld\n",*tr.find_by_order((x-1))>>10);//元素(key)->指针 
		if(opt==5)
		{
			it=m.lower_bound(x);//找下界(前驱)
			it--;
			printf("%lld\n",it->first); 
		}
		if(opt==6)
		{
			it=m.upper_bound(x);//找上界(后驱)
			printf("%lld\n",it->first); 
		}
	}
 return 0;
}