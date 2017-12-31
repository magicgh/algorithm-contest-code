	#include<iostream>
	#include<cstdio>
	#include<iomanip>
	#include<cmath>
	#include<algorithm>
	#include<cstring>
	#include<cstdlib>
	#include<vector>
	#include<queue>
	#include<stack>
	#define ri register int
	#define ll long long
	const int MAXS=59060;
	const int INF=0x7fffffff/2;
	struct Query{int s,t,l,r;};
	Query que[15];
	int n,m,q,k;
	int map[25][25],dp[MAXS][25],sta[MAXS][15],base[15],Ans;
	inline int GetInt()
	{
		int num=0,bj=1;
		char c=getchar();
		while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
		while(isdigit(c))num=num*10+c-'0',c=getchar();
		return num*bj;
	}
	int main()
	{
		n=GetInt(),m=GetInt(),q=GetInt();
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<=n;j++)
				if(i!=j)map[i][j]=INF;
		for(ri i=1;i<=m;i++)
		{
			int u=GetInt(),v=GetInt(),c=GetInt();
			map[u][v]=std::min(c,map[u][v]);
		}
		base[0]=1;
		for(ri i=1;i<=q;i++)
			base[i]=base[i-1]*3;
		for(ri i=0;i<base[q];i++)
		{
			int x=i;
			for(ri j=0;j<q;j++)
				sta[i][j]=x%3,x/=3;
		}
		for(ri i=0;i<base[q];i++)
			for(ri j=0;j<=n;j++)dp[i][j]=INF;
		dp[0][1]=0;
		for(ri k=1;k<=n;k++)
			for(ri i=1;i<=n;i++)
				for(ri j=1;j<=n;j++)
					if(i!=j&&map[i][k]!=INF&&map[k][j]!=INF)
						map[i][j]=std::min(map[i][j],map[i][k]+map[k][j]);
		for(ri i=0;i<q;i++)
		{
			int s=GetInt(),t=GetInt(),l=GetInt(),r=GetInt();
			que[i]=(Query){s,t,l,r};
		}
		for(ri i=0;i<base[q];i++)
		{
			for(ri j=1;j<=n;j++)
			{
				if(dp[i][j]==INF)continue;
				for(ri k=0;k<q;k++)
				{
					if(sta[i][k]==0)
					{
						if(dp[i][j]+map[j][que[k].s]>=que[k].l)
							dp[i+base[k]][que[k].s]=std::min(dp[i+base[k]][que[k].s],dp[i][j]+map[j][que[k].s]);
						else if(dp[i][j]+map[j][que[k].s]<que[k].l)
							dp[i+base[k]][que[k].s]=std::min(dp[i+base[k]][que[k].s],que[k].l);
					}
					if(sta[i][k]==1)	
					{
						if(dp[i][j]+map[j][que[k].t]<=que[k].r)
							dp[i+base[k]][que[k].t]=std::min(dp[i+base[k]][que[k].t],dp[i][j]+map[j][que[k].t]);
					}
				}
			}
		}
		for(ri i=0;i<base[q];i++)
		{
			for(ri j=1;j<=n;j++)
			{
				if(dp[i][j]==INF)continue;
				int cnt=0;
				for(ri k=0;k<q;k++)
					if(sta[i][k]==2)cnt++;
				Ans=std::max(Ans,cnt);
			}
		}
		printf("%d\n",Ans);
		return 0;	
	}