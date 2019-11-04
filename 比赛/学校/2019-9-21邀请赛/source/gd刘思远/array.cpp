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
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	int a[100010],n,m,k,p,ans;
	n=read();
	for (register int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	m=read();
	for (register int i=1;i<=m;i++)
	{
		p=read(),k=read();
		ans=0;
		while (p<=n)
		{
			ans++;
			p=p+a[p]+k;
		}
		write(ans);
	}
	return 0;
}
