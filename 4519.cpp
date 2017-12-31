#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define ri register int
using namespace std;
const int INF=0x7fffffff/2;
int T,N,Ans=INF;
int Card[30],Cnt[20];
inline const int getint()
{
    int num=0,bj=1;
    char ch=getchar();
    while(!isdigit(ch))bj=(ch=='-'||bj==-1)?-1:1,ch=getchar();
    while(isdigit(ch))num=num*10+ch-'0',ch=getchar();
    return num*bj;
}
inline int FindOther()
{
    int step=0;
    memset(Cnt,0,sizeof(Cnt));
    for(ri i=3;i<=16;i++)Cnt[Card[i]]++;
    while(Cnt[4]&&Cnt[2]>=2)//四带二对 
        Cnt[4]--,Cnt[2]-=2,step++;
    while(Cnt[4]&&Cnt[1]>=2)//四带二 
        Cnt[4]--,Cnt[1]-=2,step++;
    while(Cnt[4]&&Cnt[2])//四带一对 
        Cnt[4]--,Cnt[2]--,step++;
    while(Cnt[3]&&Cnt[2])//三带一对
        Cnt[3]--,Cnt[2]--,step++;
    while(Cnt[3]&&Cnt[1])//三带一
        Cnt[3]--,Cnt[1]--,step++;
    return step+Cnt[1]+Cnt[2]+Cnt[3]+Cnt[4];//各种纯数码牌 
}
void DFS(int tot,int step);
inline void FindSta(int Type,int tot,int step)//各种顺子
{
    int Limit;
    if(Type==3)Limit=2;
    if(Type==2)Limit=3;
    if(Type==1)Limit=5;
    for(ri s=Type;s<=15-Limit;s++)
    {
        if(Card[s]<Type)continue;
        for(ri len=Limit;s+len-1<=14;len++)
        {
            int t=s+len-1;bool Suc=0;
            for(ri i=s;i<=t;i++)
                if(Card[i]<Type){Suc=1;break;}
            if(Suc)break;
            for(ri i=s;i<=t;i++)
                Card[i]-=Type;
            DFS(tot-len*Type,step+1);
            for(ri i=s;i<=t;i++)
                Card[i]+=Type;
        }
    }
} 
void DFS(int tot,int step)
{
    if(tot<0||step>=Ans)return;
    Ans=min(Ans,step+FindOther());
    FindSta(3,tot,step);
    FindSta(2,tot,step);
    FindSta(1,tot,step);
}
int main()
{
    T=getint(),N=getint();
    while(T--)
    {
        memset(Card,0,sizeof(Card));
        Ans=INF;
        for(ri i=1;i<=N;i++)
        {
            int x=getint(),y=getint();
            if(x==0)x=16;
            else if(x>=1&&x<=2)x+=13;
            Card[x]++;
        }
        DFS(N,0);
        printf("%d\n",Ans);
    }
    return 0;
}