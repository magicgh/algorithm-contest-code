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
		static const int BASE=10000;
		static const int WIDTH=4;
		vector<int>s;
		int bj;
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
	        int end=str.length()-i*WIDTH,start=max(0,end-WIDTH);
	        sscanf(str.substr(start,end-start).c_str(),"%d",&x);
	        s.push_back(x);
        }
        return *this;
	} 
	BigInt operator =(int num)
	{
		char t[15];string str;
		sprintf(t,"%d",num);str=t;
		*this=str;return *this;
	}
	friend istream &operator >>(istream &input,BigInt &num)
	{
		string str;
        if(!(input>>str)) return input;
        if(str[0]=='-')num.bj=-1,str=str.substr(1);
        num=str;return input;
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
	BigInt operator -(int b){BigInt c=b;c=*this-c;return c;}
	BigInt operator *(const BigInt &b)
	const
	{ 
		BigInt c;c.bj=bj*b.bj;
		c.s.resize(s.size()+b.s.size());
		for(register int i=0;i<s.size();i++)
			for(register int j=0;j<b.s.size();j++)c[i+j]+=s[i]*b.s[j];
		for(register int i=0;i<c.s.size()-1;i++) c[i+1]+=c[i]/BASE,c[i]%=BASE;
		while(c[c.s.size()-1]==0&&c.s.size()>1)c.s.resize(c.s.size()-1);
		c.bj=(c==0)?1:c.bj;	
		return c;
	}
	BigInt operator *(int b){BigInt c=b;c=c*(*this);return c;}
	BigInt operator /(int k) //From YM
	const
	{
		int d=0;
		BigInt c=*this;
		for(register int i=c.s.size()-1; i>=0; i--) 
		{
			d=d*BASE+c.s[i];
			c.s[i]=d/k;
			d%=k;
		}
		while(c.s.back()==0&&c.s.size()>1)c.s.pop_back();
		return c;
	}
};
char ch;int n;BigInt k;
int ans[50005],one;
int main()
{
	cin>>ch>>n>>k;
	BigInt l=1,r=1;
	for(int i=1;i<n;i++)r=r*2;
	if(k>r){printf("impossible");return 0;}
	if((ch=='B'||ch=='C')&&n%2==0){printf("impossible");return 0;}
	if((ch=='A'||ch=='D')&&n%2==1){printf("impossible");return 0;}
	for(int i=1;i<n;i++)
	{
		r=r/2;
		if(k>r)one++,ans[i]=1,k=k-r;
		else ans[i]=0;
	}
	if(ch=='B'||ch=='D')ans[n]=(one%2==0)?1:0;
	if(ch=='A'||ch=='C')ans[n]=(one%2==0)?0:1;
	for(int i=1;i<=n;i++)cout<<ans[i];
}