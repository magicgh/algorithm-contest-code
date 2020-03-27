#include<bits/stdc++.h>
#define DEBUG
#define ri register int
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int INF=INT_MAX;
struct Inf
{
    string Name;
    int cnt,Time,Try[15],sj[15];
};
Inf duiwu[55];
int T,n,m,q,tot;
int Rank[55];
map<string,int>Hash;
inline int GetInt()
{
    int num=0,bj=1;
    char c=getchar();
    while(!isdigit(c))bj=(bj==-1||c=='-')?-1:1,c=getchar();
    while(isdigit(c))num=num*10+c-'0',c=getchar();
    return num*bj;
}
inline bool cmp(const Inf &a,const Inf &b)
{
    if(a.cnt==b.cnt&&a.Time==b.Time)return a.Name<b.Name;
    if(a.cnt==b.cnt)return a.Time<b.Time;
    else return a.cnt>b.cnt;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    T=GetInt();
    while(T--)
    {
        memset(duiwu,0,sizeof(duiwu));tot=0;Hash.clear();
        memset(Rank,0,sizeof(Rank));
        n=GetInt(),m=GetInt();
        for(ri i=1;i<=m;i++)
        {
            string tmp;cin>>tmp;
            duiwu[++tot].Name=tmp;
            Hash[tmp]=tot;
        }
        q=GetInt();
        for(ri i=1;i<=q;i++)
        {
            string a,b,c;int Time;
            cin>>a>>Time>>b>>c;
            int id=Hash[a];
            if(c=="Compilation-Error")continue;
            if(duiwu[id].sj[b[0]-'A'+1])continue;
            if(c=="Accepted") 
            {
                if(!duiwu[id].sj[b[0]-'A'+1])
                {
                    duiwu[id].Try[b[0]-'A'+1]++;
                    duiwu[id].sj[b[0]-'A'+1]=Time,duiwu[id].cnt++;
                    duiwu[id].Time+=Time+20*(duiwu[id].Try[b[0]-'A'+1]-1);
                }
            }
            else duiwu[id].Try[b[0]-'A'+1]++;
        }
        sort(duiwu+1,duiwu+tot+1,cmp);
        Rank[1]=1;
        for(ri i=2;i<=tot;i++)
        {
            if(duiwu[i].cnt==duiwu[i-1].cnt&&duiwu[i].Time==duiwu[i-1].Time)Rank[i]=Rank[i-1];
            else Rank[i]=i;
        }
        for(ri i=1;i<=tot;i++)
        {
            cout<<Rank[i]<<' '<<duiwu[i].Name<<' '<<duiwu[i].cnt<<' '<<duiwu[i].Time<<' ';
            for(ri j=1;j<n;j++)
            {
                if(duiwu[i].sj[j]==0)printf("-%d ",duiwu[i].Try[j]);
                else printf("+%d(%d) ",duiwu[i].Try[j],duiwu[i].sj[j]);
            }
            if(duiwu[i].sj[n]==0)printf("-%d",duiwu[i].Try[n]);
            else printf("+%d(%d)",duiwu[i].Try[n],duiwu[i].sj[n]);
            cout<<endl;
        }
        cout<<endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}