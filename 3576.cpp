#include<iostream>
#include<cstdio>
#include<cstring>
#include<iomanip>
#include<cmath>
#include<set>
using namespace std;
int n;
set<int,less<int> >s;
int main(){
	int i;
	scanf("%d",&n);
	s.insert(1);
	for(i=1;i<n;i++)
	{
		int k=*s.begin();
		s.erase(k);
		s.insert(2*k);
		s.insert(3*k);
		s.insert(5*k);
		s.insert(7*k);
	}
	printf("%d",*s.begin());
	return 0;
}