#include<bits/stdc++.h>
//#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
const int MAXN=1005;
int r,c,k,Ans;
int belx[MAXN],bely[MAXN];
bool vx[MAXN],vy[MAXN];
vector<int>a[MAXN];
inline int GetInt()
{
    int num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
inline void Init()
{
    for(ri i=1;i<=1000;i++)a[i].clear();
    memset(belx,0,sizeof(belx));
    memset(bely,0,sizeof(bely));
}
bool DFS(int u)
{
    vx[u]=1;
    for(ri v:a[u])
    {
        if(vy[v])continue;
        vy[v]=1;
        if(!bely[v]||DFS(bely[v]))
        {
            belx[u]=v,bely[v]=u;
            return 1;
        }
    }
    return 0;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    while(1)
    {
        r=GetInt(),c=GetInt(),k=GetInt(),Ans=0;
        if(r==0&&c==0&&k==0)break;
        Init();
        for(ri i=1;i<=k;i++)
        {
            int x=GetInt(),y=GetInt();
            a[x].push_back(y);
        }
        for(ri i=1;i<=r;i++)
        {
            memset(vx,0,sizeof(vx));
            memset(vy,0,sizeof(vy));
            Ans+=DFS(i);
        }
        printf("%d ",Ans);
        memset(vx,0,sizeof(vx));
        memset(vy,0,sizeof(vy));
        for(ri i=1;i<=r;i++)
            if(!belx[i])DFS(i);
        for(ri i=1;i<=r;i++)if(!vx[i])printf("r%d ",i);
        for(ri j=1;j<=c;j++)if(vy[j])printf("c%d ",j);
        printf("\n");
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}