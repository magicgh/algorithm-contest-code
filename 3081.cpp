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
class BigInt
{
	public: 
		static const int BASE=10000;//万进制
		static const int WIDTH=4;
		vector<int>s;
		int bj;//符号位
	BigInt(){*this=0,bj=1;}
	BigInt(int num){bj=num<0?-1:1,*this=abs(num);}
	int &operator[](int num){return s[num];}
	bool operator <(const BigInt &b)
	const
	{
		if(s.size()<b.s.size())return 1;
		if(s.size()>b.s.size())return 0;
		for(register int i=s.size()-1;i>=0;i--) 
		{
			if(s[i]<b.s[i])return 1;
			if(s[i]>b.s[i])return 0;
		}
		return 0;
	}
	bool operator >=(const BigInt &b)const{return !(*this<b);}
	bool operator <=(const BigInt &b)const{return !(*this>b);}
	bool operator ==(const BigInt &b)
	const
	{
		if(s.size()!=b.s.size())return 0;
		for(register int i=0;i<s.size();i++)
			if(s[i]!=b.s[i])return 0;
		return 1;
	}
	bool operator !=(const BigInt &b)const{return !(*this==b);}
	bool operator >(const BigInt &b)const{return (*this>=b)&&(*this!=b);}
	BigInt operator =(const string &str)
	{
		s.clear();
		int x,len=(str.length()-1)/WIDTH+1;
        for(register int i=0;i<len;i++)
		{
	        int end=str.length()-i*WIDTH,start=max(0,end-WIDTH);//取出区间
	        sscanf(str.substr(start,end-start).c_str(),"%d",&x);//把start-end的字符串转成数字 
	        s.push_back(x);
        }
        return *this;
	} 
	BigInt operator =(int num)
	{
		char t[15];string str;
		sprintf(t,"%d",num);str=t;
		*this=str;
		return *this;
	}
	friend istream &operator >>(istream &input,BigInt &num)
	{
		string str;
        if(!(input>>str)) return input;
        if(str[0]=='-')num.bj=-1,str=str.substr(1);
        num=str;
        return input;
	}
	friend ostream &operator <<(ostream &output,const BigInt &num) 
	{
		if(num.bj==-1)putchar('-');
		output<<num.s.back();
		for(register int i=num.s.size()-2;i>=0;i--) 
		{
	    	char buf[25];
	    	sprintf(buf,"%04d",num.s[i]);
	    	for(register int j=0;j<strlen(buf);j++)output<<buf[j];
	    }
		return output;
	}
	BigInt operator +(const BigInt &b)
	const
	{
		if(bj*b.bj==-1)
		{
			BigInt tmp=(bj==1)?b:*this;
			tmp.bj=1;
			return (bj==1)?*this-tmp:b-tmp;
		}
		BigInt c;
		c.bj=this->bj;
		c.s.resize(max(s.size(),b.s.size()+1));
		for(register int i=0;i<max(s.size(),b.s.size());i++)
		{
			int tmp1=(i>=s.size())?0:s[i],tmp2=(i>=b.s.size())?0:b.s[i];
			c[i]+=tmp1+tmp2;
		}
		for(register int i=0;i<c.s.size()-1;i++)
		{
			c[i+1]+=c[i]/BASE;
			c[i]%=BASE;
		}
		while(c[c.s.size()-1]==0&&c.s.size()>1)c.s.resize(c.s.size()-1);
		return c;
	}
	BigInt operator +=(const BigInt &num)
	{
		*this=*this+num;
		return *this;
	}
	BigInt operator +=(int num)
	{
		*this=*this+num;
		return *this;
	}
	BigInt operator +(long long b)
	{
		BigInt c;
		c=b;
		c+=*this;
		return c;
	}
	BigInt operator -(const BigInt &b)
	const
	{
		BigInt tmp1=*this,tmp2=b;
		BigInt c=*this;
		for(register int i=0;i<c.s.size();i++) 
		{
			int tmp=(i>=b.s.size())?0:b.s[i];
			if(c[i]<tmp)c[i+1]-=1,c[i]+=BASE;
			c[i]-=tmp;
		}
		while(c[c.s.size()-1]==0&&c.s.size()>1)c.s.resize(c.s.size()-1);
		return c;
	}
	BigInt operator -(int b)
	{
		BigInt c;
		c=b;
		c=*this-c;
		return c;
	}
	BigInt operator -=(const BigInt &num)
	{
		*this=*this-num;
		return *this;
	}
	BigInt operator -=(int num)
	{
		*this=*this-num;
		return *this;
	}
};
int n,m;
BigInt f[55][1250];
int main()
{
	n=getint(),m=getint(),f[1][0]=1;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=m;j++)
			f[i][j]=(f[i][j-1]+f[i-1][j]-((j-i<0)?0:f[i-1][j-i]));
		cout<<f[n][m]<<endl; 
	return 0;
}