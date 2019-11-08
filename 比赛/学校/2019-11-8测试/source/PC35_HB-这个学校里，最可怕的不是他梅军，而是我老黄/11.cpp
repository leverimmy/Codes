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
	int n,v[100010];
};
bigInt x,y,ans,p;
bigInt operator +(bigInt x,bigInt y)
{
	memset(ans.v,0,sizeof(ans.v));
	ans.n=std::max(x.n,y.n);
	int up(0);
	for(int i=1;i<=ans.n;i++)
	{
		int p=x.v[i]+y.v[i]+up;
		up=p/10;
		ans.v[i]=p%10;
	}
	if(up)
		ans.v[++ans.n]=1;
	return ans;
}
char a[100010],b[100010];
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
signed main()
{
	freopen("11.in","r",stdin);
	freopen("11.out","w",stdout);
	while(~scanf("%s%s",a,b))
	{
		convert(x,a);
		convert(y,b);
		p=x+y;
		print(p);
	}
	return 0;
}
