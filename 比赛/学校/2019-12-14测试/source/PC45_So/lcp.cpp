#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int N,Q;
char x[MAXN],y[MAXN];
bool Check(int a,int b)
{
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memcpy(x,s+a,N-a+1);
	memcpy(y,s+b,N-b+1);
	int flag=strcmp(x,y);
	return flag<0;
}

int main()
{
	freopen("lcp.in","r",stdin);
	freopen("lcp.out","w",stdout);
	scanf("%d%d",&N,&Q);
	scanf("%s",s+1);
	for(int i=1;i<=Q;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b)
		{
			puts("1");
			continue;
		}
		Check(a,b)?puts("0"):puts("1");
	}
	return 0;
}
