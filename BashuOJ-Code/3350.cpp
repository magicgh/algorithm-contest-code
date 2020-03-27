#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50005;
long long Ans=0;
int N,M,NN;
int color[MAXN],pos[MAXN],cnt[MAXN];
struct node
{
	int l,r,num;
	long long n1,n2;
}a[MAXN];
inline long long gcd(long long a,long long  b)
{
	return b==0?a:gcd(b,a%b);
}
inline bool cmp1(node x,node y)
{
	if(pos[x.l]==pos[y.l])return x.r<y.r;
	return pos[x.l]<pos[y.l];
}
inline bool cmp2(node x,node y)
{
	return x.num<y.num;
}
inline int GetInt()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
void Maintain(int x,int val)
{
	Ans-=((long long)cnt[color[x]]*(long long)cnt[color[x]]);
	cnt[color[x]]+=val;
	Ans+=((long long)cnt[color[x]]*(long long)cnt[color[x]]);
}
int main(){
	N=GetInt();
	M=GetInt();
	for(int i=1;i<=N;i++)color[i]=GetInt();
	NN=int(sqrt(N));
	for(int i=1;i<=N;i++)pos[i]=(i-1)/NN+1;
	for(int i=1;i<=M;i++)a[i].l=GetInt(),a[i].r=GetInt(),a[i].num=i;
	sort(a+1,a+M+1,cmp1);
	for(int i=1,l=1,r=0;i<=M;i++)
	{
		while(r<a[i].r)Maintain(r+1,1),r++;
		while(r>a[i].r)Maintain(r,-1),r--;
		while(l>a[i].l)Maintain(l-1,1),l--;
		while(l<a[i].l)Maintain(l,-1),l++;
		if(a[i].l==a[i].r)a[i].n1=0,a[i].n2=1;
		else
		{
			a[i].n1=Ans-(a[i].r-a[i].l+1);
			a[i].n2=((long long)(a[i].r-a[i].l+1)*(a[i].r-a[i].l));
			long long k=gcd(a[i].n1,a[i].n2);
			a[i].n1/=k,a[i].n2/=k;
		}
	}
	sort(a+1,a+M+1,cmp2);
	for(int i=1;i<=M;i++)printf("%lld/%lld\n",a[i].n1,a[i].n2);
	return 0;
}
