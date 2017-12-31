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
const int Maxn=60005;
int T,P[Maxn];
bool vst[Maxn];

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
	BigInt operator =(long long num)
	{
		char t[25];string str;
		sprintf(t,"%lld",num);str=t;
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
	BigInt operator *=(const BigInt &b)
	{
		*this=*this*b;
		return *this;
	}
	BigInt operator *(int b)
	{
		BigInt c;
		c=b;
		c*=(*this);
		return c;
	}
	BigInt operator *(long long b)
	{
		BigInt c;
		c=b;
		c*=(*this);
		return c;
	}
};
BigInt p[7010],num; 
void Init()
{
	for(int i=2;i<Maxn;i++)
	{
		if(!vst[i])P[++P[0]]=i;
		for(int j=1;j<=P[0]&&i*P[j]<Maxn;j++)
		{
			if(!vst[i*P[j]])
			{
				vst[i*P[j]]=1;	
				if(i%P[j]==0)break;
			}
		}
	}
}
void Pretreatment()
{
	p[0]=1;
	for(ri i=1;i<=P[0];i++)p[i]=p[i-1]*P[i];
}
void Binary()
{
	int l=1,r=P[0];
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(p[mid]<=num)l=mid+1;
		else r=mid-1;
	}
	cout<<p[r]<<endl;
}
int main()
{
	Init();
	Pretreatment();
	cin>>T;
	while(T--)
	{
		cin>>num;
		Binary();
	}
	return 0;
}