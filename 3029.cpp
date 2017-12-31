#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
class BigInt{
	public: 
		static const int BASE=10000;
		static const int WIDTH=4;
		vector<int>s;
		int bj;
	BigInt(){*this=0,bj=1;}
	BigInt(int num){bj=num<0?-1:1,*this=abs(num);}
	int &operator[](int num){return s[num];}
	bool operator <(const BigInt &b)
	const{
		if(s.size()<b.s.size())return 1;
		if(s.size()>b.s.size())return 0;
		for(register int i=s.size()-1;i>=0;i--){
			if(s[i]<b.s[i])return 1;
			if(s[i]>b.s[i])return 0;
		}
		return 0;
	}
	bool operator >=(const BigInt &b)const{return !(*this<b);}
	bool operator ==(const BigInt &b)
	const{
		if(s.size()!=b.s.size())return 0;
		for(register int i=0;i<s.size();i++)if(s[i]!=b.s[i])return 0;
		return 1;
	}
	bool operator !=(const BigInt &b)const{return !(*this==b);}
	bool operator >(const BigInt &b)const{return (*this>=b)&&(*this!=b);}
	bool operator <=(const BigInt &b)const{return !(*this>b);}
	BigInt operator =(const string &str){
		s.clear();int x,len=(str.length()-1)/WIDTH+1;
        for(register int i=0;i<len;i++){
	        int end=str.length()-i*WIDTH,start=max(0,end-WIDTH);
	        sscanf(str.substr(start,end-start).c_str(),"%d",&x);
	        s.push_back(x);
        }
        return *this;
	} 
	BigInt operator =(int num){char t[15];string str;sprintf(t,"%d",num);str=t;*this=str;return *this;}
	friend istream &operator >>(istream &input,BigInt &num){
		string str;
        if(!(input>>str))return input;
        if(str[0]=='-')num.bj=-1,str=str.substr(1);
        num=str;return input;
	}
	friend ostream &operator <<(ostream &output,const BigInt &num){
		if(num.bj==-1)putchar('-');output<<num.s.back();
		for(register int i=num.s.size()-2;i>=0;i--){
	    	char buf[25];
	    	sprintf(buf,"%04d",num.s[i]);
	    	for(register int j=0;j<strlen(buf);j++)output<<buf[j];
	    }
		return output;
	}
	BigInt operator +(const BigInt &b)
	const{
		BigInt c;c.bj=this->bj;
		c.s.resize(max(s.size(),b.s.size()+1));
		for(register int i=0;i<max(s.size(),b.s.size());i++){
			int tmp1=(i>=s.size())?0:s[i],tmp2=(i>=b.s.size())?0:b.s[i];c[i]+=tmp1+tmp2;
		}
		for(register int i=0;i<c.s.size()-1;i++)c[i+1]+=c[i]/BASE,c[i]%=BASE;
		while(c[c.s.size()-1]==0&&c.s.size()>1)c.s.resize(c.s.size()-1);
		return c;
	}
	BigInt operator +(int b){BigInt c=b;c=c+*this;return c;}
	BigInt operator -(const BigInt &b)
	const{
		BigInt tmp1=*this,tmp2=b,c=*this;
		for(register int i=0;i<c.s.size();i++) {
			int tmp=(i>=b.s.size())?0:b.s[i];
			if(c[i]<tmp)c[i+1]-=1,c[i]+=BASE;c[i]-=tmp;
		}
		while(c[c.s.size()-1]==0&&c.s.size()>1)c.s.resize(c.s.size()-1);
		return c;
	}
	BigInt operator -(int b){BigInt c=b;c=*this-c;return c;}
	BigInt operator *(const BigInt &b)
	const{ 
		BigInt c;c.bj=bj*b.bj;c.s.resize(s.size()+b.s.size());
		for(register int i=0;i<s.size();i++)
			for(register int j=0;j<b.s.size();j++)c[i+j]+=s[i]*b.s[j];
		for(register int i=0;i<c.s.size()-1;i++) c[i+1]+=c[i]/BASE,c[i]%=BASE;
		while(c[c.s.size()-1]==0&&c.s.size()>1)c.s.resize(c.s.size()-1);
		c.bj=(c==0)?1:c.bj;
		return c;
	}
	BigInt operator *(int b){BigInt c=b;c=c*(*this);return c;}
};
int n;
BigInt k,Rank,base=2,len;
int main()
{
	cin>>n>>k;Rank=len=n;
	if(n==1)//特殊情况 
	{
		if(k==1)cout<<1<<endl;
		else cout<<-1<<endl;
	}
	else if(n==2)
	{
		if(k<=3)cout<<k<<endl;
		else cout<<-1<<endl;
	}
	else
	{
		while(Rank<k)
		{
			base=base*2;
			len=len*2-3;//推集合长度 
			Rank=Rank+len;
		}
		Rank=Rank-len;//多减了 
		base=base-1,k=k-Rank;//计算该排第一个和该数在该排的序号 
		base=base+k,base=base-1;
		cout<<base<<endl;
	}
	return 0;
}