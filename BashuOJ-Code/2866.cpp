#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<queue> 
using namespace std;
int get_int()
{
	int num=0;
	char a=getchar();
	while(a<'0'||a>'9')a=getchar();
	while(a>='0'&&a<='9')
	{
		num=num*10+(a-'0');
		a=getchar();
	}
	return num;
}
int main(){
	priority_queue<int, vector<int>, less<int> >q;
	int t1,t2,n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	t1=get_int();
    	if(t1==1)
    	{
    	   t2=get_int();
    		q.push(t2);
		}
		if(t1==2)
		{
		t2=q.top();q.pop();
		}
		if(t1==3)printf("%d\n",q.top());
	}
	return 0;
}
