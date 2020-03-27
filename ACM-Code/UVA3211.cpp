#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
const int MAXN=4005;
int n,Mt,part,cnt;
int tim[MAXN][2],dfn[MAXN],low[MAXN],bel[MAXN];
bool ins[MAXN];
vector<int>a[MAXN];
stack<int>s;
inline int GetInt()
{
    int num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
inline void BuildGraph(int x)
{
    for(ri i=1;i<n;i++)
        for(ri j=i+1;j<=n;j++)
        {
            if(abs(tim[i][0]-tim[j][0])<x)
            {
                a[i].push_back(j+n);
                a[j].push_back(i+n);
            }
            if(abs(tim[i][1]-tim[j][1])<x)
            {
                a[i+n].push_back(j);
                a[j+n].push_back(i);
            }
            if(abs(tim[i][0]-tim[j][1])<x)
            {
                a[i].push_back(j);
                a[j+n].push_back(i+n);
            }
            if(abs(tim[i][1]-tim[j][0])<x)
            {
                a[i+n].push_back(j+n);
                a[j].push_back(i);
            }
        }
}
void Tarjan(int u)
{
    dfn[u]=low[u]=++cnt;
    s.push(u),ins[u]=1;
    for(ri v:a[u])
    {
        if(!dfn[v])
        {
            Tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v])low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        int t;part++;
        do
        {
            t=s.top();s.pop();
            ins[t]=0,bel[t]=part;
        }
        while(t!=u);
    }
}
inline void Init()
{
    cnt=part=0;
    while(!s.empty())s.pop();
    fill(dfn+1,dfn+2*n+1,0);
    fill(low+1,low+2*n+1,0);
    fill(bel+1,bel+2*n+1,0);
    fill(ins+1,ins+2*n+1,0);
    for(ri i=1;i<=2*n;i++)a[i].clear();
}
inline bool Check(int x)
{
    Init();
    BuildGraph(x);
    for(ri i=1;i<=2*n;i++)
        if(!dfn[i])Tarjan(i);
    for(ri i=1;i<=n;i++)
        if(bel[i]==bel[i+n])return 0;
    return 1;
}
int Binary()
{
    int l=0,r=Mt;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(Check(mid))l=mid+1;
        else r=mid-1;
    }
    return r;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    while(~scanf("%d",&n))
    {
        for(ri i=1;i<=n;i++)tim[i][0]=GetInt(),tim[i][1]=GetInt(),Mt=max(Mt,max(tim[i][0],tim[i][1]));
        printf("%d\n",Binary());
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}