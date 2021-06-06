inline double GetDouble()
{
	double num=0,dec=0;
	int bj=1,bits=1;
	char c=getchar();
	while(c<'0'||c>'9')bj=(c=='-'||bj==-1)?-1:1,c=getchar();
	while(c>='0'&&c<='9')num=num*10+c-'0',c=getchar();
	c=getchar();
	while(c>='0'&&c<='9')bits*=10,dec=dec*10+c-'0',c=getchar();
	return (num+dec/bits)*bj;
}
