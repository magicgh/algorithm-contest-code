#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define LL long long
const int Lim = 550005 , inf = 0x3f3f3f3f;

	int cnt , root , last , gl;
	LL f[Lim] , sub;
	int pre[Lim] , len[Lim] , ch[Lim][30];
	
	int Init(int val)
	{
		cnt++;
		pre[cnt] = 0;
		len[cnt] = val;
		for(int i=0;i<26;i++) ch[cnt][i] = 0;
		return cnt;
	}
	
	void Insert(int w)
	{
		int p = last , now = Init(len[last]+1);
		last = now;
		for(; p && !ch[p][w] ;p=pre[p]) 
			ch[p][w] = now;
		if(!p) pre[now] = root;	/*可以直接连到root*/
		else
		{
			int q = ch[p][w];
			if(len[q] == len[p]+1) pre[now] = q;
			else
			{
				int newq = Init(len[p]+1);
				for(int i=0;i<26;i++) ch[newq][i] = ch[q][i];
				pre[newq] = pre[q];
				pre[now] = pre[q] = newq;
				for(;p && ch[p][w] == q;p=pre[p]) 
				ch[p][w] = newq;
			}
		 } 
	}
	
	void Read(string str)
	{
		cnt = 0;
		root = last = Init(0);
		int n = str.length();
		for(int i=0;i<n;i++) Insert(str[i] - 'a');
	}
	
	void Dfs(int x)
	{
		if(f[x]) return;
		f[x]++;
		for(int i=0;i<26;i++)
			if(ch[x][i])
			{
				Dfs(ch[x][i]);
				f[x] += f[ch[x][i]];
			}
	}
	
	void Query(int x , int num)
	{
		if(num>=gl) return;
		for(int i=0;i<26;i++)
			if(ch[x][i])
			{
				
				if(num + f[ch[x][i]] >= gl)	//逐步锁定 
				{
					printf("%c",i+'a');
					Query(ch[x][i] , num+1);
					return;
				}
				else num += f[ch[x][i]];
				
			}
	}

int main()
{
	
	string st1;
	cin>>st1;
	Read(st1); 
	Dfs(1);

	for(int i=0;i<26;i++)
		if(ch[1][i])
			sub += f[ch[1][i]];
	sub = f[1]- 1;

	int m , t;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&t);
		if(t > sub) gl = t % sub;
			else gl = t;
		Query(1,0);
		printf("\n");
	}
	return 0;
}