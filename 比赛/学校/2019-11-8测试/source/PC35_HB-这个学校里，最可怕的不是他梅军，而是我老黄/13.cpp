#include<cstdio>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
#include<bitset>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f
struct bigInt
{
	int n,v[100100];
};
bigInt x,y,ans;
bigInt operator *(bigInt x,bigInt y)
{
	memset(ans.v,0,sizeof(ans.v));
	ans.n=x.n+y.n-1;
	for(int i=1;i<=x.n;i++)
		for(int j=1;j<=y.n;j++)
			ans.v[i+j-1]+=x.v[i]*y.v[j];
	int up(0);
	for(int i=1;i<=ans.n;i++)
	{
		int p=ans.v[i]+up;
		up=p/10;
		ans.v[i]=p%10;
	}
	while(up)
	{
		ans.v[++ans.n]=up%10;
		up/=10;
	}
	return ans;
}
char a[100100],b[100100];
void convert(bigInt &ans,char *ch)
{
	memset(ans.v,0,sizeof(ans.v));
	ans.n=strlen(ch);
	int p(0);
	for(int i=ans.n-1;i>=0;i--)
		ans.v[++p]=ch[i]-'0';
}
void print(bigInt ans)
{
	for(int i=ans.n;i>=1;i--)
		putchar(ans.v[i]+'0');
	puts("");
}
bigInt p;
signed main()
{
	freopen("13.in","r",stdin);
	freopen("13.out","w",stdout);
	while(~scanf("%s%s",a,b))
	{
		convert(x,a);
		convert(y,b);
		p=x*y;
		print(p);
	}
	return 0;
}
