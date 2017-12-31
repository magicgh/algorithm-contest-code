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
const int MAXN=100005;
const ll INF=1e18;
struct node{int to;ll val;};
vector<node>a[MAXN]; 
int n,m,Army[MAXN],dep[MAXN],prt[MAXN],p[MAXN][25],ch_cnt;
ll val[MAXN],g[MAXN][25],Max;
bool bj[MAXN];
node L1[MAXN],L2[MAXN];
inline bool cmp(const node &x,const node &y){return x.val<y.val;}
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline ll getll()
{
	ll num=0;
	int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
} 
void DFSx1(int u,int depth,ll value)//第一次DFS,求深度及父子边权 
{
	dep[u]=depth,val[u]=value;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]==it->to)continue;
		prt[it->to]=u;
		if(u==1)ch_cnt++;
		DFSx1(it->to,depth+1,it->val);
	}
}
void ST()
{
	for(ri i=1;i<=n;i++)
		p[i][0]=prt[i],g[i][0]=val[i];
	int k=int(log2(n));
	for(ri j=1;j<=k;j++)
		for(ri i=1;i<=n;i++)
			{
				p[i][j]=p[p[i][j-1]][j-1];
				g[i][j]=g[i][j-1]+g[p[i][j-1]][j-1];       
			}
}
void DFSx2(int u)//从根开始向下DFS求出儿子节点的保护情况 
{
	bool isprotect=1,isleaf=1;
	vector<node>::iterator it;
	for(it=a[u].begin();it!=a[u].end();++it)
	{
		if(prt[u]==it->to)continue;
		DFSx2(it->to);
		if(!bj[it->to])isprotect=0;//儿子没被保护，父亲也没有
		isleaf=0;//同时也不是叶子节点 
	} 
	if(u!=1&&isprotect&&!isleaf)bj[u]=1;
	//不是根节点且被保护且不是叶子(可能根的一个儿子没有子树,没被保护且要驻扎军队),被标记已保护 
}
inline bool Check(int mid)
{
	int cnt1=0,cnt2=0;
	memset(bj,0,sizeof(bj));
	for(ri i=1;i<=m;i++)//军队从当前节点向上爬 
	{
		int u=Army[i];ll dist=0;
		int Limit=int(log2(n));
		for(ri j=Limit;j>=0;j--)
			if(p[u][j]&&dist+g[u][j]<=mid)dist+=g[u][j],u=p[u][j];//倍增爬树 
		if(u==1)//如果爬到了根节点 
		{
			int u_ch=Army[i];
			for(ri j=Limit;j>=0;j--)
				if(p[u_ch][j]>1)u_ch=p[u_ch][j];//求出军队是到根节点的哪个儿子上 
			L1[++cnt1]=(node){u_ch,mid-dist};//存储当前军队信息 
		}
		else bj[u]=1;//没有爬到根节点，则该点被保护 
	}
	DFSx2(1);//第二次DFS 
	vector<node>::iterator it;
	for(it=a[1].begin();it!=a[1].end();++it)
		if(!bj[it->to])L2[++cnt2]=(node){it->to,it->val};//把根的儿子节点中所有没被保护的节点取出，用军队去覆盖这些节点(贪心)
	sort(L1+1,L1+cnt1+1,cmp),sort(L2+1,L2+cnt2+1,cmp);//把军队驻扎节点和未保护节点按剩余时间进行排序
	//......双指针维护 
	L2[cnt2+1].val=INF;
	int i=1,j=1;
	for(i=1;i<=cnt1;i++)
	{
		if(!bj[L1[i].to])bj[L1[i].to]=1;//覆盖军队所在节点
		else if(L1[i].val>=L2[j].val)bj[L2[j].to]=1;//军队未覆盖其他节点，就去覆盖它能覆盖的根的儿子节点
		while(bj[L2[j].to])j++;//找到下一个未被保护集合中现在还未被保护的节点 
	}
	return j>cnt2;//如果全被保护，则继续缩小控制疫情的时间 
	
}
ll Binary()//二分答案 
{
	ll l=0,r=Max;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(Check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	n=getint();
	for(ri i=1;i<n;i++)
	{
		int u=getint(),v=getint();ll w=getll();
		a[u].push_back((node){v,w});
		a[v].push_back((node){u,w}); 
		Max+=w;
	}
	m=getint();
	for(ri i=1;i<=m;i++)Army[i]=getint(); 
	DFSx1(1,0,0);
	if(ch_cnt>m){printf("-1\n");return 0;}//军队数量小于根的儿子数量无解 
	ST(),printf("%lld\n",Binary());
	return 0;
}

