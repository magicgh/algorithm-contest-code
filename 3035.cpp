#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define ri register int
#define ll int
using namespace std;
struct BigInteger {
	static const int BASE=100000000; 
	static const int WIDTH=8; 
	vector<ll>s;
	int bj; 
	BigInteger() { 
		*this=0;
		bj=0;
	}
	BigInteger(const int& num) { 
		*this=num;
		bj=num>0?1:-1;
		if(num==0)bj=0;
	}
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
	BigInteger operator = (int num) {
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
	BigInteger operator + (const int& b) {
		BigInteger c;
		if(b==0)return *this;
		if(b<0)return *this-abs(b);
		if(bj==0)return BigInteger(b);
		if(bj<0)return BigInteger(b)-abs(*this);
		c=b;
		c+=*this;
		return c;
	}
	void operator += (const int& b) {
		*this=*this+b;
	}
	BigInteger operator - (BigInteger b) {
		if(bj==-1)return -(abs(*this)+b);
		if(b.bj==-1)return *this+abs(b);
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
			ll tmp;
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
	BigInteger operator - (const int& b) {
		if(b==0)return *this;
		if(b<0)return *this+abs(b);
		if(bj==0)return -b;
		if(bj<0)return -(abs(*this)+b);
		BigInteger c,d=*this;
		c=b;
		d-=c;
		return d;
	}
	void operator -= (const int& b) {
		*this=*this-b;
	}
	BigInteger operator * (int b) {
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
	void operator *= (int b) {
		*this=*this*b;
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
	void operator *= (const BigInteger& b) {
		*this=*this*b;
	}
	BigInteger operator / (int k) {
		ll d=0;
		BigInteger c;
		c=*this;
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
	void operator /= (int k) {
		*this=*this/k;
	}
	BigInteger operator + () {
		return *this;
	}
	BigInteger operator - () {
		BigInteger a=*this;
		a.bj*=-1;
		return a;
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
			char buf[105];
			sprintf(buf,"%08d",x.s[i]);
			for(int j=0; j<strlen(buf); j++)output<<buf[j];
		}
		return output;
	}
};
BigInteger n,ans;
int p=-1;
int KS;
int main()
{
	cin>>n;
    while((n=(n-2)/2)!=0)
    {
        KS++;
        if(KS>200000)break;
		if(n<0)break;
        p=-p;
        ans+=n*p;
    }
    cout<<ans*2<<endl;
	return 0;
}

