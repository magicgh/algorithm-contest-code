#include <iostream>
using namespace std;
const char match[12][12] = {"          ",
                            " 111222333",
                            " 111222333",
                            " 111222333",
                            " 444555666",
                            " 444555666",
                            " 444555666",
                            " 777888999",
                            " 777888999",
                            " 777888999"};
char c;
struct Ac{bool hash[15];};
Ac x[15], y[15], nine[15];
int g[15][15];
void In()
{
 for (int i=1;i<=9;i++)
 {
 for (int j=1;j<=9;j++)
{
 cin>>c;
 if (c>='0'&&c<='9')
{
 g[i][j]=c-'0';
 x[i].hash[c-'0']=y[j].hash[c-'0']=nine[match[i][j]-'0'].hash[c-'0']=true;
}
}
}
 return;
}


void Out()
{
 for (int i=1;i<=9;i++)
{
 for (int j=1;j<=9;j++) cout<<char(g[i][j]+'0');
 cout<<endl;
}
 return;
}

bool flag=false;
void Dfs(int x0, int y0)
{
 if (!x0)
{
 flag=true;
 Out();
 return;
}
 if (!g[x0][y0]&&!flag)
{
 for (int i=9;i&&!flag;i--)
 if (!x[x0].hash[i]&&!y[y0].hash[i]&&!nine[match[x0][y0]-'0'].hash[i])
{
 x[x0].hash[i]=y[y0].hash[i]=nine[match[x0][y0]-'0'].hash[i]=true;
 g[x0][y0]=i;
 if (y0==1) Dfs(x0-1, 9);
 else Dfs(x0, y0-1);
 x[x0].hash[i]= y[y0].hash[i]=nine[match[x0][y0]-'0'].hash[i]=false;
 g[x0][y0]= 0;
}
}
 else if (!flag)
{
 if (y0==1) Dfs(x0-1,9);
 else Dfs(x0, y0-1);
}
 return;
}

int main()
{
 In();
 Dfs(9, 9);
 return 0;
}