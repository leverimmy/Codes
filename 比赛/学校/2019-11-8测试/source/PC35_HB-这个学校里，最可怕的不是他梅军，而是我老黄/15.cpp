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
bigInt operator /(bigInt x,bigInt y)
{
	
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
	freopen("15.in","r",stdin);
	freopen("15.out","w",stdout);
	while(~scanf("%s%s",a,b))
	{
		convert(x,a);
		convert(y,b);
		p=x/y;
		print(p);
	}
	return 0;
}
