#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50005;
long long N,NN,M,MM,ans=0;
long long c[MAXN],order[MAXN],pos[MAXN],Order[MAXN],Ans[MAXN];
inline long long GetInt()
{
	long long num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
struct node
{
	long long l,r,num;
}a[MAXN];
inline bool cmp_sort(node fac1,node fac2)
{
	if(pos[fac1.l]==pos[fac2.l])return fac1.r<fac2.r;
	return fac1.l<fac2.l;
}
inline bool cmp_num(node fac1,node fac2)
{
	return fac1.num<fac2.num;
}
inline int Lowbit(int x){return x&(-x);}
inline void Insert(int x,long long d)
{
	for(int i=x;i<=N;i+=Lowbit(i))c[i]+=d;
}
long long Sum(int x)
{
	long long Ans=0;
	for(int i=x;i>0;i-=Lowbit(i))Ans+=c[i];
	return Ans;
}
int main(){
	N=GetInt();
	for(int i=1;i<=N;i++)Order[i]=order[i]=GetInt();
	sort(order+1,order+N+1); 
	MM=unique(order+1,order+N+1)-(order+1);
	for(int i=1;i<=N;i++)Order[i]=lower_bound(order+1,order+MM+1,Order[i])-order;
	NN=sqrt(MM);
	for(int i=1;i<=MM;i++)pos[i]=(i-1)/NN+1;
	M=GetInt();
	for(int i=1;i<=M;i++)a[i]=(node){GetInt(),GetInt(),i};
	sort(a+1,a+M+1,cmp_sort);
	for(int i=1,l=1,r=0;i<=M;i++)
	{
		while(r<a[i].r)ans+=(r-l+1)-Sum(Order[r+1]),Insert(Order[r+1],1),r++;
		while(r>a[i].r)ans-=(r-l+1)-Sum(Order[r]),Insert(Order[r],-1),r--;
		while(l>a[i].l)ans+=Sum(Order[l-1]-1),Insert(Order[l-1],1),l--;
		while(l<a[i].l)ans-=Sum(Order[l]-1),Insert(Order[l],-1),l++;
		//(r-l+1)-Sum(x)求大于x的和
		Ans[a[i].num]=ans;
	}
	for(int i=1;i<=M;i++)printf("%lld\n",Ans[i]);
	return 0;
}
