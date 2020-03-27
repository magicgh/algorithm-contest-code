#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
const int MAXN=505;
struct Taxi{int ax,ay,bx,by,t;};
Taxi L[MAXN];
vector<int>G[MAXN];
int T,n,bel[MAXN],vst[MAXN];
inline int GetInt()
{
    int num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
bool DFS(int u,int t)
{
    for(ri v:G[u])
    {
        if(vst[v]==t)continue;
        vst[v]=t;
        if(!bel[v]||DFS(bel[v],t))
        {
            bel[v]=u;
            return 1;
        }
    }
    return 0;
}
int main()
{
    T=GetInt();
    while(T--)
    {
        memset(bel,0,sizeof(bel));
        int Ans=0;
        n=GetInt();
        for(ri i=1;i<=505;i++)G[i].clear();
        for(ri i=1;i<=n;i++)
        {
            int hh=GetInt(),mm=GetInt();
            L[i]=(Taxi){GetInt(),GetInt(),GetInt(),GetInt(),hh*60+mm};                   
        }
        for(ri i=1;i<n;i++)
            for(ri j=i+1;j<=n;j++) 
                if(L[i].t+abs(L[i].ax-L[i].bx)+abs(L[i].ay-L[i].by)+abs(L[i].bx-L[j].ax)+abs(L[i].by-L[j].ay)<L[j].t)G[i].push_back(j);
        for(ri i=1;i<=n;i++)Ans+=DFS(i,i);
        printf("%d\n",n-Ans);               
    }
    return 0;
}