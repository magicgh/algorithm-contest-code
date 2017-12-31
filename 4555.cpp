#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50005;
long long Ans=0;
int N,M,NN,K;
int color[MAXN],pos[MAXN],cnt[MAXN];
struct node
{
	int l,r,num;
	long long ans;
}a[MAXN];
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
	K=GetInt();
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
		a[i].ans=Ans;
	}
	sort(a+1,a+M+1,cmp2);
	for(int i=1;i<=M;i++)printf("%lld\n",a[i].ans);
	return 0;
}
