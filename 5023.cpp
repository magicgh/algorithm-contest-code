#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#define ri register int
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a/gcd(a,b)*b 
using namespace std;
const int MAXN=55;
struct di{ll a,c;};
di D[MAXN];
ll a[MAXN],b[MAXN],c[MAXN];
int n,Type;
void SolveA()
{
	ll Lcm=D[1].a,Ans=0;
	for(ri i=2;i<=n;i++)
		Lcm=lcm(Lcm,D[i].a);
	for(ri i=1;i<=n;i++)
		Ans+=Lcm*c[i]/a[i];
	printf("%lld\n",Ans);
}

struct BigInt
{
	static const int BASE=100000000;
	static const int WIDTH=8;
	vector<ll>s;
	BigInt()   //构造函数：初始赋0
	{
		*this=0;
	}
	BigInt(const ll& num)   // 构造函数
	{
		*this=num;
	}
	//赋值
	BigInt operator = (ll num)
	{
		s.clear();
		do
			{
				s.push_back(num%BASE);
				num/=BASE;
			}
		while(num>0);
		return *this;
	}
	//+
	BigInt operator + (BigInt b)
	{
		BigInt c;
		c.s.clear();
		ll g=0;
		for(int i=0; ; i++)
			{
				if(g==0&&i>=s.size()&&i>=b.s.size())break;
				ll x=g;
				if(i<s.size())x+=s[i];
				if(i<b.s.size())x+=b.s[i];
				c.s.push_back(x%BASE);
				g=x/BASE;
			}
		return c;
	}
	void operator += (BigInt b)
	{
		*this=*this+b;
	}
	BigInt operator + (const ll& b)
	{
		BigInt c;
		c=b;
		c+=*this;
		return c;
	}
	void operator += (const ll& b)
	{
		*this=*this+b;
	}
	//*
	BigInt operator * (ll b)
	{
		BigInt c;
		if(b==0)
			{
				c=0;
				return c;
			}
		c.s.clear();
		for(int i=0; i<s.size(); i++)c.s.push_back(s[i]*b);
		for(int i=0; i<c.s.size()-1; i++)
			{
				c.s[i+1]+=c.s[i]/BASE;
				c.s[i]%=BASE;
			}
		while(c.s.back()>=BASE)
			{
				ll now=c.s.back();
				c.s.back()%=BASE;
				c.s.push_back(now/BASE);
			}
		return c;
	}
	void operator *= (ll b)
	{
		*this=*this*b;
	}
	// /
	BigInt operator / (ll k)
	{
		ll d=0;
		BigInt c;
		c=*this;
		for(int i=c.s.size()-1; i>=0; i--)
			{
				d=d*BASE+c.s[i];
				c.s[i]=d/k;
				d%=k;
			}
		while(c.s.back()==0&&c.s.size()>1)c.s.pop_back();
		return c;
	}
	void operator /= (ll k)
	{
		*this=*this/k;
	}
	friend ostream& operator << (ostream& output,const BigInt& x)
	{
		output<<x.s.back();
		for(int i=x.s.size()-2; i>=0; i--)
			{
				char buf[20];
				sprintf(buf,"%08lld",x.s[i]);
				for(int j=0; j<strlen(buf); j++)output<<buf[j];
			}
		return output;
	}
};
void SolveB()
{
	BigInt Lcm=D[1].a,Ans;
	for(ri i=2;i<=n;i++)
		Lcm=Lcm*D[i].a;
	for(ri i=1;i<=n;i++)
		Ans+=Lcm*c[i]/a[i];
	cout<<Ans<<endl;
}
inline const int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
inline const ll getll()
{
	ll num=0;int bj=1;
	char c=getchar();
	while(!isdigit(c))bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(isdigit(c))num=num*10+c-'0',c=getchar();
	return num*bj;
}
int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	n=getint(),Type=getint();
	for(ri i=1;i<=n;i++)a[i]=getll();
	for(ri i=1;i<=n;i++)b[i]=getll();
	for(ri i=1;i<=n;i++)c[i]=abs(getll());
	for(ri i=1;i<=n;i++)
	{
		 ll Gcd=gcd(2*a[i],c[i]);
		 D[i].a=2*a[i]/Gcd,D[i].c=c[i]/Gcd;
	}
	if(Type==0)SolveA();
	else SolveB();
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}

