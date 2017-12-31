#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#define ri register int
#define ll long long
using namespace std;
const int MAXN=100005;
const int INF=0x7fffffff/2;
struct node{int x,y,z;};
node a[MAXN*10];
queue<int>q;
map<int,bool>Hash;
int n,Ans,Size,num[10],b[10],prt[MAXN],Maxn=-INF;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline bool cmp(const node &a,const node &b){return a.z<b.z;}
inline int getfa(int u)
{
	if(prt[u]==u)return u;
	return prt[u]=getfa(prt[u]);	
} 
void Kruskal()
{
	for(ri i=1;i<=MAXN;i++)prt[i]=i;
	for(ri i=1;i<=Size;i++)
	{
		int f1=getfa(a[i].x),f2=getfa(a[i].y);
		if(f1!=f2)
		{
			prt[f2]=f1;
			Ans+=a[i].z;
		}
	}
}
inline int Combine(int cnt)
{
	int ans=0;
	for(ri i=1;i<=cnt;i++)ans=ans*10+num[i];
	return ans;
}
inline int Delete(int cnt,int pos)
{
	int ans=0;
	for(ri i=1;i<=cnt;i++)if(i!=pos)ans=ans*10+num[i];
	return ans;
}
void BFS()
{
	while(!q.empty())
	{
		int now=q.front();q.pop();
		memset(num,0,sizeof(num));
		int cnt=(int)log10(now)+1,tmp=now;
		for(ri i=cnt;i>=1;i--)
		{
			num[i]=tmp%10;
			tmp/=10;
		}
		//交换 
		for(ri i=1;i<cnt;i++)
			for(ri j=i+1;j<=cnt;j++)
			{
				int val=((num[i]&num[j])+(num[i]^num[j]))<<1;
				swap(num[i],num[j]);
				int next=Combine(cnt);
				swap(num[i],num[j]);
				a[++Size]=(node){now,next,val};
				if(Hash.count(next))continue;
				Hash[next]=1;
				q.push(next);
			}
		//删除 
		num[cnt+1]=num[1],num[0]=num[cnt];
		if(cnt>1)
		{
			for(int i=1;i<=cnt;i++)
			{
				if(num[i-1]>num[i]||num[i]>num[i+1])continue;
				int val=num[i]+(num[i+1]&num[i-1])+(num[i+1]^num[i-1]);
				int next=Delete(cnt,i);
				a[++Size]=(node){now,next,val};
				if(Hash.count(next))continue;
				Hash[next]=1;
				q.push(next);
			}
		}
		//添加 
		if(cnt<Maxn)
		{
			for(int i=0;i<=cnt;i++)
			{
				for(int j=num[i];j<=num[i+1];j++)
				{
					int val=j+(num[i]&num[i+1])+(num[i]^num[i+1]);
					int next=0,k;
					for(k=1;k<=cnt;k++)
					{
						if(k==i+1)next=next*10+j;
						next=next*10+num[k];
					}
					if(k==cnt)next=next*10+num[cnt];
					a[++Size]=(node){now,next,val};
					if(Hash.count(next))continue;
					Hash[next]=1;
					q.push(next);
				}
			}
		}
	}
}
int main()
{
	n=getint();
	for(ri i=1;i<=n;i++)
	{
		b[i]=getint();
		Maxn=max(Maxn,(int)log10(b[i])+1); 
		q.push(b[i]);Hash[b[i]]=1;
	}
	for(ri i=1;i<n;i++)a[++Size]=(node){b[i],b[i+1],0};//互相连边 
	BFS();
	sort(a+1,a+Size+1,cmp); 
	Kruskal();
	printf("%d\n",Ans);
	return 0;
}

