#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;
class BigInt
{
	public: 
		static const int BASE=10000;//万进制
		static const int WIDTH=4;
		vector<int>s;
		int bj;//符号位
	BigInt(){*this=0,bj=1;}
	BigInt(int num){bj=num<0?-1:1,*this=abs(num);}
	BigInt(long long num){bj=num<0?-1:1,*this=abs(num);}
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
	BigInt operator *(const BigInt &b)
	const
	{ 
		BigInt c;
		c.bj=bj*b.bj;
		c.s.resize(s.size()+b.s.size());
		for(register int i=0;i<s.size();i++)
			for(register int j=0;j<b.s.size();j++)c[i+j]+=s[i]*b.s[j];
		for(register int i=0;i<c.s.size()-1;i++) 
		{
			c[i+1]+=c[i]/BASE;
			c[i]%=BASE;
		}
		while(c[c.s.size()-1]==0&&c.s.size()>1)c.s.resize(c.s.size()-1);
		c.bj=(c==0)?1:c.bj;
		return c;
	}
	BigInt operator *(int b)
	{
		BigInt c;
		c=b;
		c=c*(*this);
		return c;
	}

};
BigInt a=1,b=1;
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)a=a*10,b=b*9;
	cout<<a-b;
	return 0;
}