#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=200005;
struct heap{
	int val,id;
	bool operator <(const heap &rhs)
	const{return val<rhs.val;}
};
priority_queue<heap>q;
bool bj[MAXN];
int n,m,a[MAXN],L[MAXN],R[MAXN],Ans,pos;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	n=getint(),m=getint();
	for(ri i=1;i<=n;i++)
	{
		a[i]=getint();
		q.push((heap){a[i],i});
		L[i]=i-1,R[i]=i+1;
	}
	if(n/2<m){printf("Error!\n");return 0;}
	L[1]=n,R[n]=1;
	for(ri i=1;i<=m;i++)
	{
		while(bj[q.top().id])q.pop();//找到一个未被合并的 
		Ans+=q.top().val,pos=q.top().id,q.pop();//取出队首元素,并在该位置种树 
		bj[L[pos]]=1,bj[R[pos]]=1;//删除左右的元素
		q.push((heap){a[L[pos]]+a[R[pos]]-a[pos],pos});//将新元素加入队列 
		a[pos]=a[L[pos]]+a[R[pos]]-a[pos];	
		int	l=L[pos],r=R[pos];//修改链表 
		L[pos]=L[l],R[pos]=R[r];
		R[L[l]]=pos,L[R[r]]=pos;		
	}
	printf("%d",Ans);
	return 0;
}

