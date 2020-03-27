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
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
inline int getint()
{
	int num=0,bj=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=(num<<1)+(num<<3)+c-'0',c=getchar();
	return num*bj;
}
struct BigInteger {// from Yang_Ming
	static const int BASE=1000; //高进制
	static const int WIDTH=3; //高进制位数
	vector<int>s;
	int bj; //负数
	BigInteger() { //构造函数：初始赋0
		*this=0;
		bj=0;
	}
	BigInteger(const long long& num) { // 构造函数
		*this=num;
		bj=num>0?1:-1;
		if(num==0)bj=0;
	}
	//内部函数
	BigInteger abs(const BigInteger& b) {
		BigInteger a=b;
		if(a.bj==-1)a.bj=1;
		return a;
	}
	void swap(BigInteger& a,BigInteger& b) {
		BigInteger t=a;
		a=b;
		b=t;
	}
	//赋值
	BigInteger operator = (long long num) {
		s.clear();
		bj=1;
		if(num==0)bj=0;
		else if(num<0) {
			num=std::abs(num);
			bj=-1;
		}
		do {
			s.push_back(num%BASE);
			num/=BASE;
		} while(num>0);
		return *this;
	}
	BigInteger operator = (const string& str) {
		s.clear();
		int x,len=(str.length()-1)/WIDTH+1;
		for(int i=0; i<len; i++) {
			int end=str.length()-i*WIDTH;
			int start=max(0,end-WIDTH);
			sscanf(str.substr(start,end-start).c_str(),"%d",&x);
			s.push_back(x);
		}
		return *this;
	}
	//比较
	bool operator < (const BigInteger& b) {
		if(bj<b.bj)return true;
		if(bj>b.bj)return false;
		if(bj+b.bj==-2)return abs(*this)>abs(b);
		if(s.size()<b.s.size())return true;
		if(s.size()>b.s.size())return false;
		for(int i=s.size()-1; i>=0; i--) {
			if(s[i]<b.s[i])return true;
			if(s[i]>b.s[i])return false;
		}
		return false;
	}
	bool operator >= (const BigInteger& b) {
		return !(*this<b);
	}
	bool operator <= (const BigInteger& b) {
		return !(*this>b);
	}
	bool operator == (const BigInteger& b) {
		if(bj!=b.bj)return false;
		if(s.size()!=b.s.size())return false;
		for(int i=0; i<s.size(); i++)
			if(s[i]!=b.s[i])return false;
		return true;
	}
	bool operator != (const BigInteger& b) {
		return !(*this==b);
	}
	bool operator > (const BigInteger& b) {
		return ((*this>=b)&&(*this!=b));
	}
	//+
	BigInteger operator + (BigInteger b) {
		if(bj==-1)return b-abs(*this);
		if(b.bj==-1)return *this-abs(b);
		BigInteger c;
		c.bj=1;
		if(bj==-1&&b.bj==-1)c.bj=-1;
		else if(bj==0)c.bj=b.bj;
		else if(b.bj==0)c.bj=bj;
		c.s.clear();
		for(int i=0,g=0; ; i++) {
			if(g==0&&i>=s.size()&&i>=b.s.size())break;
			int x=g;
			if(i<s.size())x+=s[i];
			if(i<b.s.size())x+=b.s[i];
			c.s.push_back(x%BASE);
			g=x/BASE;
		}
		return c;
	}
	void operator += (BigInteger b) {
		*this=*this+b;
	}
	BigInteger operator + (const long long& b) {
		BigInteger c;
		if(b==0)return *this;
		if(b<0)return *this-abs(b);
		if(bj==0)return BigInteger(b);
		if(bj<0)return BigInteger(b)-abs(*this);
		c=b;
		c+=*this;
		return c;
	}
	void operator += (const long long& b) {
		*this=*this+b;
	}
	//-
	BigInteger operator - (BigInteger b) {
		BigInteger c;
		c=*this;
		if(c==b) {
			c=0;
			return c;
		} else if(c<b) {
			BigInteger tmp=b-c;
			tmp.bj*=-1;
			return tmp;
		}
		for(int i=0; i<c.s.size(); i++) {
			int tmp;
			if(i>=b.s.size())tmp=0;
			else tmp=b.s[i];
			if(c.s[i]<tmp) {
				c.s[i+1]-=1;
				c.s[i]+=BASE;
			}
			c.s[i]-=tmp;
		}
		while(c.s.back()==0&&c.s.size()>1)c.s.pop_back();
		return c;
	}
	void operator -= (BigInteger b) {
		*this=*this-b;
	}
	BigInteger operator - (const long long& b) {
		if(b==0)return *this;
		if(b<0)return *this+abs(b);
		BigInteger c,d=*this;
		c=b;
		d-=c;
		return d;
	}
	void operator -= (const long long& b) {
		*this=*this-b;
	}
	//*
	BigInteger operator * (long long b) {
		BigInteger c;
		c.bj=bj;
		if(b==0) {
			c=0;
			return c;
		} else if(b<0) {
			b=std::abs(b);
			c.bj=-bj;
		}
		c.s.clear();
		for(int i=0; i<s.size(); i++)c.s.push_back(s[i]*b);
		for(int i=0; i<c.s.size()-1; i++) {
			c.s[i+1]+=c.s[i]/BASE;
			c.s[i]%=BASE;
		}
		while(c.s.back()>=BASE) {
			int now=c.s.back();
			c.s.back()%=BASE;
			c.s.push_back(now/BASE);
		}
		return c;
	}
	BigInteger operator * (const BigInteger& b) {
		BigInteger c;
		c.bj=bj*b.bj;
		c.s.resize(s.size()+b.s.size());
		for(int i=0; i<s.size(); i++)
			for(int j=0; j<b.s.size(); j++)c.s[i+j]+=s[i]*b.s[j];
		for(int i=0; i<c.s.size()-1; i++) {
			c.s[i+1]+=c.s[i]/BASE;
			c.s[i]%=BASE;
		}
		while(c.s.back()==0&&c.s.size()>1)c.s.pop_back();
		return c;
	}
	// /
	BigInteger operator / (long long k) {
		int d=0;
		BigInteger c;
		c=*this;
		if(k==0)throw exception();
		if(k<0) {
			k=std::abs(k);
			c.bj=-1*c.bj;
		}
		for(int i=c.s.size()-1; i>=0; i--) {
			d=d*BASE+c.s[i];
			c.s[i]=d/k;
			d%=k;
		}
		while(c.s.back()==0&&c.s.size()>1)c.s.pop_back();
		return c;
	}
	BigInteger Copy(const BigInteger& b,int x) {
		BigInteger t;
		t.bj=b.bj;
		t.s.resize(b.s.size()+x);
		for(int i=0; i<b.s.size(); i++)t.s[i+x]=b.s[i];
		return t;
	}
	BigInteger operator / (const BigInteger& b) {
		BigInteger c,d,b0=b;
		c.s.resize(s.size()-b.s.size()+1);
		d=*this;
		if(b.bj==0)throw exception();
		c.bj=bj*b.bj;
		d=abs(d);
		b0=abs(b);
		for(int i=c.s.size()-1; i>=0; i--) {
			BigInteger t;
			t=Copy(b0,i);
			while(d>=t) {
				(c.s[i])++;
				d-=t;
			}
		}
		while(c.s.back()==0&&c.s.size()>1)c.s.pop_back();
		return c;
	}
	//±
	BigInteger operator -- () {
		*this-=1;
		return *this;
	}
	const BigInteger operator -- (int) {
		BigInteger tmp=*this;
		*this=*this-1;
		return tmp;
	}
	friend istream& operator >> (istream& input,BigInteger& x) {
		string s;
		if(!(input>>s))return input;
		if(s[0]=='-') {
			x.bj=-1;
			s=s.substr(1);
		} else x.bj=1;
		x=s;
		return input;
	}
	friend ostream& operator << (ostream& output,const BigInteger& x) {
		if(x.bj==-1)cout<<"-";
		output<<x.s.back();
		for(int i=x.s.size()-2; i>=0; i--) {
			char buf[20];
			sprintf(buf,"%03d",x.s[i]);
			for(int j=0; j<strlen(buf); j++)output<<buf[j];
		}
		return output;
	}
};
BigInteger n,k,Ans;
int main()
{
	cin>>n>>k;
	k-=1;
	Ans=(k*k*k*4+k*k*9+k*5)/6;
	Ans+=(n-k*k-k*2)*(k+1);
	cout<<Ans<<endl; 
	return 0;
}
