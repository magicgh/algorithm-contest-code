#include<iostream>
#include<cstring>
using namespace std;
string a;
int s;
char letter[50]={0};
void C(int i,int j)
{
	 if(i==s){cout<<letter<<endl;return;}
	while(j<=a.length())
	{         
		int ss=strlen(letter);
			letter[ss]=a[j-1];
			C(i+1,j+1);
			letter[ss]=0;
            j++;
	}
}
int main()
{
	cin>>a>>s;
	C(0,1);
	//system("pause");
	return 0;
}
