#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=0;
	int rere=0;
	while (ch<'0'||ch>'9') {ch=getchar();}
	while (ch>='0'&&ch<='9')
	{
		rere=rere*10+ch-'0';
		ch=getchar();
	}
	return rere;
}
inline void write(int rerere)
{
	if (rerere>9) write(rerere/10);
	putchar(rerere%10+'0');
	putchar('\n');
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,k,p,ans,x,y,t,z;
	t=read();
	while (t--)
	{
		n=read(),m=read();
		for (register int i=1;i<=m;i++)
		{
			x=read(),y=read(),z=read();
			if (x==y&&z==1) n=0;
		}
		if (n%2==1) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
