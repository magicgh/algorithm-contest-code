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
const int Mod=1000000007;
int n,m,k;
int f[2][1005][205][2];
char a[1005],b[205];
inline const int getint()
{
    int num=0,bj=1;
    char ch=getchar();
    while(!isdigit(ch))bj=(ch=='-'||bj==-1)?-1:1,ch=getchar();
    while(isdigit(ch))num=num*10+ch-'0',ch=getchar();
    return num*bj;
}
int main()
{
    n=getint(),m=getint(),k=getint();
    scanf("%s%s",a+1,b+1);
    int now=0,next=1;
    f[now][0][0][0]=f[next][0][0][0]=1;
    for(ri i=1;i<=n;i++)
    {
        for(ri j=1;j<=m;j++)
            for(ri cnt=1;cnt<=k;cnt++)
            {
                if(a[i]==b[j])
                    f[next][j][cnt][1]=(f[now][j-1][cnt][1]+f[now][j-1][cnt-1][0])%Mod;
                else f[next][j][cnt][1]=0;
                f[next][j][cnt][0]=(f[now][j][cnt][0]+f[next][j][cnt][1])%Mod;
            }
        now=next,next^=1;
    }
    printf("%d\n",f[now][m][k][0]%Mod);
    return 0;
}