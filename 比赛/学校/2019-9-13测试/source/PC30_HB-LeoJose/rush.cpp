#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=100001;
struct apair
{
	int x,y;
};
apair p[maxn];
int n,m;
inline int read()
{
	register int x=0,f=0;
	register char ch=getchar();
	while(ch<'0' || ch>'9')
		f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
int main()
{
	freopen("rush.in","r",stdin);
	freopen("rush.out","w",stdout);
	n=read(),m=read();
	for(register int i=1,x,y;i<=m;i++)
	{
		x=read(),y=read();
		pos++;
		p[pos].x=x;
		p[pos].y=y;
	}
	cout<<n;
}