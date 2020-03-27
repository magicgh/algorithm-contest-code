#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
//#include<windows.h>
using namespace std;
int to[1005],sep[1005],f[1005][1005],n=0,flag=0;
int cnt1=0,cnt2=0;
bool vst[1005],vst1[1005];
inline void BFS(int x)
{
	queue<int>q;
	q.push(x);
	vst[x]=1;
	while(!q.empty())
	{
		int now=q.front();
		//cout<<now<<' ';
		for(int i=0;i<n;i++)
		{
			if(i==flag)continue;
			if(f[now][i]&&(!vst[i]))
			{
				vst[i]=1;
				q.push(i);
			}
		}
		q.pop();
	}
}
int main(){
	memset(f,0,sizeof(f));
	memset(to,0,sizeof(to));
	memset(vst,0,sizeof(vst));
	memset(vst1,0,sizeof(vst1));
	memset(sep,0,sizeof(sep));
	int x;
	for(int i=0;i<50;i++)
	{
		for(int j=1;j<=100;j++)
		{
			cin>>x;
			if(x==-2||x==-1)break;
			f[i][x]=1;
		}
		if(x==-1)break;
		n++;
	}
	for(int i=1;i<n-1;i++)
	{
		flag=i;
		memset(vst,0,sizeof(vst));
		BFS(0);
		if(!vst[n-1])to[++cnt1]=i;
	}
	int bj=0;
	//system("cls");
	for(int i=1;i<=cnt1;i++)
	{
	memset(vst,0,sizeof(vst));
	memset(vst1,0,sizeof(vst1));
	flag=to[i];
	BFS(0);
	//cout<<endl;
	memcpy(vst1,vst,sizeof(vst));
	memset(vst,0,sizeof(vst));
	BFS(to[i]);
	//cout<<endl;
	bj=0;
	for(int j=0;j<n;j++)
		if(vst1[j]&&vst[j]){bj=1;break;}
		if(!bj)sep[++cnt2]=to[i];
	}
	cout<<cnt1<<' ';
	for(int i=1;i<=cnt1;i++)cout<<to[i]<<' ';
	cout<<endl;
	cout<<cnt2<<' ';
	for(int i=1;i<=cnt2;i++)cout<<sep[i]<<' ';
	return 0;
}
