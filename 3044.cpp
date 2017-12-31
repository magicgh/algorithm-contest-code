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
ll n,step,sx,sy,num;
ll sum;
const ll Mod=1000000007ll;
inline ll getint()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	return num*bj;
}
void GetMatrix(){
	ll x,y,bj=0;
	step=sqrt(n);
	if(step&1){
		x=1,y=step,num=step*step;
		if(num==n)sx=x,sy=y;
		else if(num+1==n)sx=x,sy=y+1;
		else{
			num++,y++;
			for(ri i=1;i<=step;i++){num++,x++;if(num==n){sx=x,sy=y,bj=1;break;}}
			if(!bj)for(ll i=1;i<=step;i++){num++,y--;if(num==n){sx=x,sy=y,bj=1;break;}}
		}
	}
	else{
		x=step,y=1,num=step*step;
		if(num==n)sx=x,sy=y;
		else if(num+1==n)sx=x+1,sy=y;
		else{
			num++,x++;
			for(ri i=1;i<=step;i++){num++,y++;if(num==n){sx=x,sy=y,bj=1;break;}}
			if(!bj){for(ll i=1;i<=step;i++){num++,x--;if(num==n){sx=x,sy=y,bj=1;break;}}}
		}
	}
}
void GetSum()
{
	ll R=sx,C=sy,r=R,c=C;
	while(r>1||c>1)
	{
		if(r<=c)
		{
			ll Ans=0;
			if(c&1)
			{
				ll a=c*c%Mod;
				Ans=(a*r%Mod*R%Mod-((a+R)%Mod)*((r*r-r)/2%Mod)+(r*r-r)*(2*r-1)/6%Mod)%Mod;
			}
			else
			{
				ll a=((c-1)*(c-1)+1)%Mod;
				Ans=(a*R%Mod*r%Mod+((R-a)%Mod)*((r*r-r)/2%Mod)-(r*r-r)*(2*r-1)/6%Mod)%Mod;
			}
			sum=(sum+Ans*(C-c+1)%Mod)%Mod;
			c--;
		}
		else
		{
			ll Ans=0;
			if(r&1)
			{
				ll a=((r-1)*(r-1)+1)%Mod;
				Ans=(a*C%Mod*c%Mod+((C-a)%Mod)*((c*c-c)/2%Mod)-(c*c-c)*(2*c-1)/6%Mod)%Mod;
			}
			else
			{
				ll a=r*r%Mod;
				Ans=(a*c%Mod*C%Mod-((a+C)%Mod)*((c*c-c)/2%Mod)+(c*c-c)*(2*c-1)/6%Mod)%Mod;
			}
			sum=(sum+Ans*(R-r+1)%Mod)%Mod;
			r--;
		}
	}
	sum=(sum+R*C%Mod)%Mod;
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	n=getint();
	step=sqrt(n);
	GetMatrix();
	GetSum();
	printf("%lld\n",sum);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

