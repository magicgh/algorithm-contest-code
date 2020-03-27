#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
const int MAXN=505;
struct Student{int h,g,m,s;};
Student List[MAXN];
map<string,int>music,sports;
vector<int>G[MAXN];
int T,n,mcnt,scnt,bel[MAXN],vst[MAXN];
inline int GetInt()
{
    int num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
inline void Produce(int x)
{
    char gender;string t1,t2;
    cin>>gender>>t1>>t2;
    if(!music.count(t1))music[t1]=++mcnt;
    if(!sports.count(t2))sports[t2]=++scnt;
    List[x].g=(gender=='M')?1:2;
    List[x].m=music[t1],List[x].s=sports[t2];
}
inline void Init()
{
    mcnt=scnt=0;
    music.clear();sports.clear();
    for(ri i=1;i<=n;i++)G[i].clear();
}
inline bool Check(int x,int y)
{
    if(abs(List[x].h-List[y].h)>40)return 1;
    if(List[x].g==List[y].g)return 1;
    if(List[x].m!=List[y].m)return 1;
    if(List[x].s==List[y].s)return 1;
    return 0;
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
int Hungry()
{
    int Ans=0;
    memset(bel,0,sizeof(bel));
    memset(vst,0,sizeof(vst));
    for(ri i=1;i<=n;i++)Ans+=DFS(i,i);
    return Ans;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    T=GetInt();
    while(T--)
    {
        n=GetInt();
        Init();
        for(ri i=1;i<=n;i++)
        {
            List[i].h=GetInt();
            Produce(i);
        }
        for(ri i=1;i<n;i++)
            for(ri j=i+1;j<=n;j++)
                if(!Check(i,j))G[i].push_back(j),G[j].push_back(i);
        printf("%d\n",n-Hungry()/2);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}