#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
#define ri register int
using namespace std;
const int MAXN=400005;
const int INF=0x7fffffff/2;
vector<int>a[MAXN];
int st[MAXN],ed[MAXN],List[MAXN];
int b[MAXN],l[MAXN];
int In[MAXN][5],f[MAXN][20],g[MAXN][20];
int N,Q,cnt;
inline int max(const int &a,const int &b)
{
    return a>b?a:b;
}
inline int min(const int &a,const int &b)
{
    return a<b?a:b;
}
inline int GetInt()
{
    int num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
void DFS(int u)
{
    st[u]=++cnt,List[cnt]=u;
    vector<int>::iterator it;
    vector<int>tmp;
    tmp.push_back(b[u]);
    for(it=a[u].begin();it!=a[u].end();++it) 
	{
        DFS(*it);
        for(ri i=0; i<3; i++)tmp.push_back(In[*it][i]);
    }
    sort(tmp.begin(),tmp.end(),greater<int>());
    for(unsigned ri i=0;i<tmp.size();i++) 
	{
        int value=tmp[i];
        if(In[u][0]==-1)In[u][0]=value;
        else if(In[u][1]==-1)In[u][1]=value;
        else if(In[u][2]==-1&&value!=In[u][1]) 
		{
            In[u][2]=value;
            break;
        }
    }
    ed[u]=cnt;
}
void ST()
{
    for(int i = 1; i <= N; i++) f[i][0] = l[List[i]];
    int k=log2(N);
    for(int j=1;j<=k;j++)
        for(int i=1;i+(1<<j)-1<=N;i++) 
		{
            int t=i+(1<<(j-1));
            if(f[i][j-1]>f[t][j-1]) 
                f[i][j]=f[i][j-1],g[i][j]=f[t][j-1];
			else if(f[i][j-1]<f[t][j-1]) 
                f[i][j]=f[t][j-1],g[i][j]=f[i][j-1];
            else
                f[i][j]=f[i][j-1],g[i][j]=max(g[i][j-1],g[t][j-1]);
        }
}
inline int RMQ_1(int l , int r)
{
    if(l>r)return 0;
    int k=log2(r-l+1);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}

inline int RMQ_2(int l , int r)
{
    if(l>r)return 0;
    int k=log2(r-l+1),t=r-(1<<k)+1;
    int f1=f[l][k],f2=f[t][k];
    if(f1!=f2)return min(f1,f2);
    else return max(g[l][k],g[t][k]);
}
inline int Query(int s)
{
    if(st[s] == ed[s])return 0;
	int zui = In[s][0] , ci = In[s][1];
	int f1 = RMQ_1(1 , st[s] - 1);
	int f2 = RMQ_1(ed[s] + 1 , N);
	int mx = max(f1 , f2);
	if(ci + mx > zui)return zui;
	if(ci + mx < zui)return ci+mx; 
	int se = 0;
	if(f1 != f2) se = min(f1 , f2);
	se = max(se , RMQ_2(1 , st[s] - 1));
	se = max(se ,  RMQ_2(ed[s] + 1 , N));
	int san = In[s][2], ans = (zui == ci) ? san : ci;
	ans = max(ans , san + mx);
	if(ci + se != zui) ans = max(ans , ci + se);
	return ans;
}
int main()
{
	int size =40 << 20;
	__asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size)); 
    N=GetInt(),Q=GetInt();
    for(ri i=2; i<=N; i++) 
	{
        int x=GetInt();
        a[x].push_back(i);
    }
    for(ri i=1; i<=N; i++)
        b[i]=GetInt(),l[i]=GetInt();
    memset(In,-1,sizeof(In));
    DFS(1),ST();
    for(ri i=1; i<=Q; i++) 
	{
        int x=GetInt();
        printf("%d\n",Query(x));
    }
    exit(0); 
    return 0;
}
