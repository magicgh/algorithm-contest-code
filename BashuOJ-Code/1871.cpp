#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue>
using namespace std;
int Fac[15]= {1,1,2,6,24,120,720,5040,40320,362880};
struct digit
{
    int map[5][5];
} Begin,q[400000];
int Tmp[10],start,final,cnt[400000];
bool Hash[362885];
void DB(digit a);
int Contor(digit Achen)
{
    int ans=0;
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)Tmp[(i-1)*3+j]=Achen.map[i][j];
    for(int i=1; i<=9; i++)
        {
            int cnt=0;
            for(int j=i+1; j<=9; j++)if(Tmp[j]<Tmp[i])cnt++;
            ans+=Fac[9-i]*cnt;
        }
    return ans+1;
}
digit Trans(int num,int k)
{
    digit t;
    //cout<<endl;
    t=q[num];
    if(k==1)
        {
        t.map[1][1]=q[num].map[2][1];
		t.map[1][2]=q[num].map[1][1];
		t.map[1][3]=q[num].map[1][2];
		t.map[2][3]=q[num].map[1][3];
		t.map[3][3]=q[num].map[2][3];
		t.map[3][2]=q[num].map[3][3];
		t.map[3][1]=q[num].map[3][2];
		t.map[2][1]=q[num].map[3][1];
        }
    if(k==2)
        {
          t.map[2][2]=q[num].map[2][1];
          t.map[2][3]=q[num].map[2][2];
          t.map[2][1]=q[num].map[2][3];
        }
        return t;
}
void Debug(digit a,int b,int c)
{
	cout<<"ID:"<<b<<"  "<<endl;
	for(int i=1;i<=3;i++)
	{
	
	for(int j=1;j<=3;j++)
	{
		cout<<a.map[i][j]<<' ';
	}
	cout<<endl;
	}
	cout<<endl;
	cout<<"Total Count:"<<c<<endl<<endl;
}
void DB(digit a)
{
	for(int i=1;i<=3;i++)
	{
	
	for(int j=1;j<=3;j++)
	{
		cout<<a.map[i][j]<<' ';
	}
	cout<<endl;
	}
	cout<<endl;
}
bool BFS()
{
    int h=1,t=1;
    q[1]=Begin,cnt[1]=0;
    digit tmp;
    while(h<=t)
    {
    for(int i=1; i<=2; i++)
    {
    //	cout<<"OLD"<<endl;
	//DB(tmp);  
      tmp=Trans(h,i);
      int t_num=Contor(tmp);
      //Debug(tmp,t_num,q[t].cnt);
      if(!Hash[t_num])
      {
         q[++t]=tmp;
         cnt[t]=cnt[h]+1;
         Hash[t_num]=1;
      }
	  if(t_num==1)
         {
            cout<<cnt[t]<<endl;
            return 1;
         }
     }
      h++;
    }
    return 0;
}
int main()
{
	//freopen("text.txt","w",stdout); 
    while(cin>>Begin.map[1][1])
    {
    memset(Hash,0,sizeof(Hash));
    memset(cnt,0,sizeof(cnt));
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
        {
		if(i==1&&j==1)continue;
		cin>>Begin.map[i][j];
		}
    start=Contor(Begin);
    Hash[start]=1;
   // cout<<endl;
    if(!BFS())cout<<"UNSOLVABLE";
	}
    return 0;
}